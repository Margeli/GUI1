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
	if (moving) {
		Drag();
	}

	
	UpdateAlignment();
	App->render->Blit(tex, position.x + displacement.x, position.y + displacement.y, &rect);

	return true;
}
void GuiButton::AddButtonText() {

	int width, heigh;

	App->font->CalcSize(text.GetString(), width, heigh);

	switch (align) {
	case NONE:
		buttontext = App->gui->AddText(NONE, text, { displacement.x , displacement.y + 2 }, MORPHEUS, { 255, 255,0,255 });
		break;
	case CENTERED:
		buttontext = App->gui->AddText(align, text, { displacement.x , displacement.y + 2 }, MORPHEUS, { 255, 255,0,255 });
		break;
	case RIGHT:
		buttontext = App->gui->AddText(align, text, { displacement.x + width/ 2 - rect.w /2 , displacement.y + 2 }, MORPHEUS, { 255, 255,0,255 });
		break;
	case LEFT:
		buttontext = App->gui->AddText(align, text, { displacement.x + (rect.w -width)/2 , displacement.y + 2 }, MORPHEUS, { 255, 255,0,255 });
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
		StartDrag();
		tex = press;
		state = status;
		break;
	case UP_L:
		EndDrag();
		state = status;
		break;
	}
}

void GuiButton::ChangeButtonTxt(p2SString txt) {

	buttontext->ChangeText(txt);
}

void GuiButton::Drag(iPoint displace) {

	displacement.x += displace.x;
	displacement.y += displace.y;
	DragButtonElements(displace);
}

void GuiButton::DragButtonElements(iPoint displace){
	
	buttontext->Drag(displace);
	}

void GuiButton::StartDrag() {

	iPoint mouse_position;
	App->input->GetMousePosition(mouse_position.x, mouse_position.y);
	click_pos = mouse_position;

	moving = true;
}

void GuiButton::EndDrag() {

	click_pos = { 0,0 };

	moving = false;
}

void GuiButton::Drag() {
	iPoint mouse_position;
	App->input->GetMousePosition(mouse_position.x, mouse_position.y);

	displacement.x += (mouse_position.x - click_pos.x);
	displacement.y += (mouse_position.y - click_pos.y);
	DragButtonElements({ mouse_position.x - click_pos.x , mouse_position.y - click_pos.y });

	click_pos = mouse_position;
}