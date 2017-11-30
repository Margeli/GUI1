#include "GuiWindow.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"
#include "p2Log.h"


GuiWindow::GuiWindow(Alignment alignment) : j1UI_Elem(UIType::INPUTBOX, Alignment::NONE) {
	align = alignment;
}


GuiWindow::~GuiWindow()
{
}

bool GuiWindow::Start() {

	tex = App->gui->GetAtlas();
	rect = { 30, 542, 422, 454 };

	PutWindowButtons();

	return true;
}

bool GuiWindow::CleanUp() {
	
	//App->tex->UnLoad(tex);
	return true;

}
bool GuiWindow::Update(float dt) {
	if (moving) {	
		Drag();		
	}

	UpdateAlignment();
	App->render->Blit(tex, position.x + displacement.x, position.y + displacement.y, &rect);
	return true;
}

void GuiWindow::StateChanging(ButtonState status) {

	switch (status) {
	case IDLE:
		state = status;
		break;
	case HOVER:		
		state = status;
		break;
	case PRESSED_L:
		StartDrag();		
		state = status;
		break;
	case UP_L:
		EndDrag();
		state = status;
		break;
	}
}

void GuiWindow::Drag() {
	iPoint mouse_position;
	App->input->GetMousePosition(mouse_position.x, mouse_position.y);

	displacement.x += ( mouse_position.x- click_pos.x);
	displacement.y += (mouse_position.y - click_pos.y);
	DragWindowElements({ mouse_position.x - click_pos.x , mouse_position.y - click_pos.y });

	click_pos = mouse_position;

}

void GuiWindow::StartDrag() {

	iPoint mouse_position;
	App->input->GetMousePosition(mouse_position.x, mouse_position.y);
	click_pos = mouse_position;

	moving = true;
}
void GuiWindow::EndDrag() {
	
	click_pos = {0,0};

	moving = false;
}
void GuiWindow::PutWindowButtons() {
	if (num_buttons > MAX_BUTTON_NUM) {
		LOG("Exceded max num buttons");
		num_buttons = MAX_BUTTON_NUM;
	}
	iPoint localPos = { position.x + displacement.x, position.y + displacement.y };
	for (int i = 0; i < num_buttons; i++) {
		GuiButton* butt;
		butt = App->gui->AddButton(align, nullptr, { localPos.x , localPos.y + 40*(i+1)}, listener);

		win_buttons.add(butt);
	}
}
void GuiWindow::DragWindowElements(iPoint displace) {
	
	for (p2List_item<GuiButton*>* button = win_buttons.start; button; button = button->next) {
		button->data->displacement.x += displace.x;
		button->data->displacement.y += displace.y;
	}
}

void GuiWindow::SetButtonName(uint button_num, p2SString txt) {

	int num = button_num - 1;

	win_buttons.At(num)->data->ChangeButtonTxt(txt);
}