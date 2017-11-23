#ifndef __GUITEXT_H__
#define __GUITEXT_H__

#include "j1UI_Elem.h"
#include "SDL_TTF\include\SDL_ttf.h"


// ---------------------------------------------------
class GuiText : public j1UI_Elem
{
public:

	GuiText();

	// Destructor
	virtual ~GuiText();
	bool Start();
	bool CleanUp();

private:
	_TTF_Font* font;

};

#endif // __GUITEXT_H__