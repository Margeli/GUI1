#ifndef __GUIINPUT_H__
#define __GUIINPUT_H__

#include "j1UI_Elem.h"

class GuiLabel;


// ---------------------------------------------------
class GuiInput : public j1UI_Elem
{
public:

	GuiInput(Alignment alignment = NONE);

	// Destructor
	virtual ~GuiInput();
	bool Start();
	bool CleanUp();
	bool Update(float dt);

	p2SString text;

	void StateChanging(ButtonState state);
	void AddDefaultText();

private:
	SDL_Texture* hover;
	SDL_Texture* idle;

	GuiLabel* inputtext;
};

#endif // __GUIINPUT_H__