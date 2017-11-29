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

	
	int width, height;
	App->font->CalcSize(text.GetString(), width, height);
	rect.w = width;
	rect.h = height;

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
	text_color = color;
	text_font = fnt;
	text = txt;
	tex = App->font->Print(text.GetString(), text_color, text_font);
}

bool GuiText::Update(float dt) {

	UpdateAlignment();
	App->render->Blit(tex, position.x+ displacement.x, position.y+ displacement.y);
	return true;
}
void GuiText::DebugDraw() {	
	App->render->DrawQuad({ position.x + displacement.x, position.y + displacement.y, rect.w, rect.h }, 255, 255, 0, 100);
}
void GuiText::ChangeText(p2SString newtext) {

	tex = App->font->Print(newtext.GetString(), text_color, text_font);
}