#ifndef __GUIBUTTON_H__
#define __GUIBUTTON_H__

#include "j1UI_Elem.h"


// ---------------------------------------------------
class GuiButton : public j1UI_Elem
{
public:

	GuiButton(Alignment alignment = NONE);

	// Destructor
	virtual ~GuiButton();
	bool Start();
	bool CleanUp();
	bool Update(float dt);




private:

};

#endif // __GUIBUTTON_H__