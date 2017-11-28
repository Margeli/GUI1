#include "GuiCheck.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"



GuiCheck::GuiCheck(Alignment alignment) : j1UI_Elem(UIType::CHECK, Alignment::NONE) {
	align = alignment;
}


GuiCheck::~GuiCheck()
{
}

bool GuiCheck::Start() {

	tex = LoadTexture("gui/wow ui/BUTTONS/UI-CheckBox-Down.png");
	check = LoadTexture("gui/wow ui/BUTTONS/UI-CheckBox-Check.png");
	rect = { 0,0,32,32 };

	AddCheckText();

	return true;
}

bool GuiCheck::CleanUp() {

	//App->tex->UnLoad(tex);
	return true;

}
bool GuiCheck::Update(float dt) {

	event = CheckPressedCheck();
	ManageEvents();

	UpdateAlignment();
	App->render->Blit(tex, position.x + displacement.x, position.y + displacement.y, &rect);
	if (pressed) {
		App->render->Blit(check, position.x + displacement.x, position.y + displacement.y, &rect);
	}
	return true;
}
void GuiCheck::AddCheckText() const {

	App->gui->AddText(align, text, { displacement.x+ 30 , displacement.y + 5 }, MORPHEUS, { 255, 255,0,255 });
}

ButtonEvent GuiCheck::CheckPressedCheck() const {

	ButtonEvent ret = MOUSE_NONE;
	iPoint pos;
	App->input->GetMousePosition(pos.x, pos.y);

	if (pos.x > position.x + displacement.x && pos.x < position.x + displacement.x + rect.w) {
		if (pos.y > position.y + displacement.y && pos.y < position.y + displacement.y + rect.h) {
			if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN) {
				ret =CLICK_DOWN;
			}
			if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_UP) {
				ret = CLICK_UP;
			}
		}
	}
	return ret;
}

void GuiCheck::ManageEvents() {
	if (event != previous_event) {
		switch (event) {
		case CLICK_DOWN:
			pressed = !pressed;
			previous_event = event;
			break;
		case CLICK_UP:			
			previous_event = event;
			break;
		}
	}
}