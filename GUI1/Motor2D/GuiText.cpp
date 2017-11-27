#include "GuiText.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Fonts.h"
#include "j1Render.h"



GuiText::GuiText(Alignment alignment) : j1UI_Elem(UIType::TEXT, Alignment::NONE) {
	align = alignment;
	const char* path;
	int size = 14;
	if (frizqt == nullptr) {
		path = "fonts/wow/FRIZQT__.ttf";
		frizqt = App->font->Load(path, size);
	}
	if (morpheus == nullptr) {
		path = "fonts/wow/MORPHEUS.ttf";
		morpheus = App->font->Load(path, size);
	}
	if (skurri == nullptr) {
		path = "fonts/wow/skurri.ttf";
		morpheus = App->font->Load(path, size);
	}
	if (arialn == nullptr) {
		path = "fonts/wow/ARIALN.ttf";
		morpheus = App->font->Load(path, size);
	}
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

void GuiText::CreateText(p2SString txt, SDL_Color color, FontType font) {
	_TTF_Font* fnt = nullptr;
	switch (font) {
	case FRIZQT:
		fnt = frizqt;
		break;

	case MORPHEUS:
		fnt = morpheus;
		break;

	case SKURRI:
		fnt = morpheus;
		break;

	case ARIALN:
		fnt = morpheus;
		break;
	}
	
	tex = App->font->Print(txt.GetString(), color, fnt);
	rect = { 0,0, (int)txt.Length(),100 }; // prepared to fit in the alignUpdate method

}
bool GuiText::Update(float dt) {

	UpdateAlignment();
	App->render->Blit(tex, position.x+ displacement.x, position.y+ displacement.y);
	return true;
}