#include "GuiText.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Fonts.h"
#include "j1Render.h"



GuiText::GuiText(Alignment alignment) : j1UI_Elem(UIType::TEXT, Alignment::NONE) {
	align = alignment;
	
}


GuiText::~GuiText()
{
}

bool GuiText::Start() {

	
	return true;
}

bool GuiText::CleanUp() {

	return true;

}

void GuiText::CreateText(p2SString txt) {

	
	tex = App->font->Print(txt.GetString());
	rect = { 0,0, (int)txt.Length(),100 }; // prepared to fit in the alignUpdate method

}
bool GuiText::Update(float dt) {

	UpdateAlignment();
	App->render->Blit(tex, position.x+ displacement.x, position.y+ displacement.y);
	return true;
}