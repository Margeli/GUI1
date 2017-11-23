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

	font = App->font->Load(DEFAULT_FONT);
	return true;
}

bool GuiText::CleanUp() {

	return true;

}
