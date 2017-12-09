#include "GuiInput.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Render.h"
#include "SDL/include/SDL.h"
#include "p2Log.h"


GuiInput::GuiInput(Alignment alignment) : j1UI_Elem(UIType::INPUTBOX, Alignment::NONE) {
	align = alignment;
	can_focus = true;
}


GuiInput::~GuiInput()
{
}

bool GuiInput::Awake(pugi::xml_node& conf) {

	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		
	}
	return true;
}
bool GuiInput::Start() {
	idle = LoadTexture("gui/wow ui/CHATFRAME/UI-ChatInputBorder.png");
	hover = LoadTexture("gui/wow ui/CHATFRAME/UI-CHATINPUTBORDER-LEFT.png");
	rect = { 0,0,256,32 };
	tex = idle;
	AddDefaultText();
	
	
	return true;
}

bool GuiInput::CleanUp() {

	//App->tex->UnLoad(tex);
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;

}
bool GuiInput::PreUpdate() {


	static SDL_Event evnt;	
	char* text;
	
	if (readinput == true) {
		SDL_StartTextInput();


		while (SDL_PollEvent(&evnt) != 0)
		{
			switch (evnt.type) {
			case SDL_QUIT:

				break;

			case SDL_TEXTINPUT:
				text = evnt.edit.text;
				inputtext->AddCharToTxt(text);
				
				break;
			}


		}
		SDL_StopTextInput();
	}
	
	return true;

}
bool GuiInput::Update(float dt) {
	UpdateAlignment();
	App->render->Blit(tex, position.x + displacement.x, position.y + displacement.y, &rect);
	//----SHIFTFOCUS--
	if (focus) {
		tex = hover;
		ReadInput();
		int height, width;
		int margin = 10; // should be the same as margin in AddDefaultTxt()
		inputtext->GetTxtDimensions(width, height);		
		App->render->DrawQuad({position.x + margin + width , position.y + displacement.y+8,1, height }, 255, 255, 255, 255);
		
	}
	if (lose_focus) {
		focus = false;
		tex = idle;
		lose_focus = false;
	}
	//------
	
	
	return true;
}

void GuiInput::StateChanging(ButtonState status) {

	switch (status) {
	case IDLE:
		tex = idle;
		state = status;
		break;
	case HOVER:
		tex = hover;
		state = status;
		break;
	case PRESSED_L:
		readinput = true;
		if (strcmp(inputtext->GetText(), "Default text")== 0) {
			LOG("%s", inputtext->GetText());
			RemoveText();
		}
		focus = true;
		state = status;
		break;
	case UP_L:		
		state = status;
		break;
	}
}
void GuiInput::AddDefaultText(){
	p2SString txt = "Default text";
	int pos= position.x;
	int margin = 10;
	if (align == CENTERED) { CenteredtoLeft(pos); }
	inputtext = App->gui->AddText(LEFT, txt, { pos+ displacement.x +margin , displacement.y +6 }, MORPHEUS, { 255, 255,255,255 });

}

void GuiInput::ReadInput() {

	
}

void GuiInput::RemoveText() {
	inputtext->ChangeText("");
}