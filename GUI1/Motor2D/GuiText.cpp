#include "GuiText.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Fonts.h"
#include "j1Render.h"



GuiText::GuiText(Alignment alignment) : j1UI_Elem(UIType::TEXT, Alignment::NONE) {
	
	align = alignment;
	int font_size = 14;
	const char* path;
	if (font_frizqt == nullptr) {
		path = "fonts/wow/FRIZQT__.ttf";
		font_frizqt = App->font->Load(path, font_size);
	}
	if (font_morpheus == nullptr) {
		path = "fonts/wow/MORPHEUS.ttf";
		font_morpheus = App->font->Load(path, font_size);
	}
	if (font_skurri == nullptr) {
		path = "fonts/wow/skurri.ttf";
		font_morpheus = App->font->Load(path, font_size);
	}
	if (font_arialn == nullptr) {
		path = "fonts/wow/ARIALN.ttf";
		font_morpheus = App->font->Load(path, font_size);
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
		fnt = font_frizqt;	break;
	case MORPHEUS:
		fnt = font_morpheus;	break;
	case SKURRI:
		fnt = font_skurri;	break;
	case ARIALN:
		fnt = font_arialn;	break;
	}
	text = txt;
	tex = App->font->Print(txt.GetString(), color, fnt);
}

bool GuiText::Update(float dt) {

	UpdateTextAlignment(text.GetString());
	App->render->Blit(tex, position.x+ displacement.x, position.y+ displacement.y);
	return true;
}
void GuiText::DebugDraw() {

	int width, height;
	App->font->CalcSize(text.GetString(), width, height);
	App->render->DrawQuad({ position.x + displacement.x, position.y + displacement.y, width, height }, 255, 255, 0, 100);
}