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




private:

};

#endif // __GUICHECK_H__