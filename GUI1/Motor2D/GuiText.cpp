#include "GuiText.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Fonts.h"



GuiText::GuiText() : j1UI_Elem(UIType::TEXT, Alignment::NONE) {
	
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

	text = txt;
	tex = App->font->Print(text.GetString());
	rect = { 0,0, (int)text.Length(),0 }; // prepared to fit in the alignUpdate method

}
