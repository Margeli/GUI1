#include "GuiButton.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Render.h"



GuiButton::GuiButton(Alignment alignment) : j1UI_Elem(UIType::BUTTON, Alignment::NONE) {
	align = alignment;
}


GuiButton::~GuiButton()
{
}

bool GuiButton::Start() {

	
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