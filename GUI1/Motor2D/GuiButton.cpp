#include "GuiButton.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Fonts.h"
#include "j1Input.h"


GuiButton::GuiButton(Alignment alignment) : j1UI_Elem(UIType::BUTTON, Alignment::NONE) {
	align = alignment;
	
}


GuiButton::~GuiButton()
{
}

bool GuiButton::Start() {

	up = LoadTexture("gui/wow ui/BUTTONS/UI-DialogBox-Button-Up.png");
	down = LoadTexture("gui/wow ui/BUTTONS/UI-DialogBox-Button-Down.png");
	press = LoadTexture("gui/wow ui/BUTTONS/UI-DialogBox-Button-Disabled.png");
	rect = { 0,0,128,32 };
	AddButtonText();
	tex = up;
	

	return true;
}

bool GuiButton::CleanUp() {

	//App->tex->UnLoad(tex);
	return true;

}
bool GuiButton::Update(float dt) {

	
	UpdateAlignment();
	App->render->Blit(tex, position.x + displacement.x, position.y + displacement.y, &rect);

	return true;
}
void GuiButton::AddButtonText() {

	int width, heigh;

	App->font->CalcSize(text.GetString(), width, heigh);

	switch (align) {
	case NONE:
		App->gui->AddText(NONE, text, { displacement.x , displacement.y + 2 }, MORPHEUS, { 255, 255,0,255 });
		break;
	case CENTERED:
		App->gui->AddText(align, text, { displacement.x , displacement.y + 2 }, MORPHEUS, { 255, 255,0,255 });
		break;
	case RIGHT:
		App->gui->AddText(align, text, { displacement.x + width/ 2 - rect.w /2 , displacement.y + 2 }, MORPHEUS, { 255, 255,0,255 });
		break;
	case LEFT:
		App->gui->AddText(align, text, { displacement.x + (rect.w -width)/2 , displacement.y + 2 }, MORPHEUS, { 255, 255,0,255 });
		break;
	}
			
	
}

void GuiButton::StateChanging(ButtonState status) {

	switch(status){
	case IDLE:
		tex = up;
		state = status;
		break;
	case HOVER:
		tex = down;
		state = status;
		break;
	case PRESSED_L:
		tex = press;
		state = status;
		break;
	}
}
