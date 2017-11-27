#ifndef __GUITEXT_H__
#define __GUITEXT_H__

#include "j1UI_Elem.h"
#include "SDL_TTF\include\SDL_ttf.h"


// ---------------------------------------------------
class GuiText : public j1UI_Elem
{
public:

	GuiText(Alignment alignment = NONE);

	// Destructor
	virtual ~GuiText();
	bool Start();
	bool CleanUp();
	bool Update(float dt);
	

	void CreateText(p2SString txt, SDL_Color color, FontType font);
	

private:
	p2SString text;

	_TTF_Font* frizqt = nullptr;
	_TTF_Font* morpheus = nullptr;
	_TTF_Font* arialn = nullptr;
	_TTF_Font* skurri = nullptr;
};

#endif // __GUITEXT_H__