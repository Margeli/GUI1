#include "GuiCheck.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Render.h"



GuiCheck::GuiCheck(Alignment alignment) : j1UI_Elem(UIType::CHECK, Alignment::NONE) {
	align = alignment;
}


GuiCheck::~GuiCheck()
{
}

bool GuiCheck::Start() {


	return true;
}

bool GuiCheck::CleanUp() {

	//App->tex->UnLoad(tex);
	return true;

}
bool GuiCheck::Update(float dt) {

	UpdateAlignment();
	App->render->Blit(tex, position.x + displacement.x, position.y + displacement.y, &rect);
	return true;
}