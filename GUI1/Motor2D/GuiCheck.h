#ifndef __GUICHECK_H__
#define __GUICHECK_H__

#include "j1UI_Elem.h"


// ---------------------------------------------------
class GuiCheck : public j1UI_Elem
{
public:

	GuiCheck(Alignment alignment = NONE);

	// Destructor
	virtual ~GuiCheck();
	bool Start();
	bool CleanUp();
	bool Update(float dt);

	p2SString text;
	bool pressed = false;


private:
	void AddCheckText() const ;
	bool CheckPressedCheck() const;
	SDL_Texture* check;
};

#endif // __GUICHECK_H__