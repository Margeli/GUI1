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
	

	void CreateText(p2SString txt);
	

private:
	p2SString text;

};

#endif // __GUITEXT_H__