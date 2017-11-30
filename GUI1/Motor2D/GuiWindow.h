#ifndef __GUIWINDOW_H__
#define __GUIWINDOW_H__

#include "j1UI_Elem.h"
#include "p2List.h"


#define MAX_BUTTON_NUM 10

class GuiButton;
class GuiLabel;
// ---------------------------------------------------
class GuiWindow : public j1UI_Elem
{
public:

	GuiWindow(Alignment alignment = NONE);

	// Destructor
	virtual ~GuiWindow();
	bool Start();
	bool CleanUp();
	bool Update(float dt);


	p2SString title;
	uint num_buttons;

	void StateChanging(ButtonState state);
	void SetButtonName(uint button_num, p2SString txt); // changes the name of the button in the position (button_num) starting from above

private:

	p2List<GuiButton*> win_buttons;
	GuiLabel* win_text;

	void Drag();
	void StartDrag();
	void EndDrag();
	void PutWindowButtons();
	void DragWindowElements(iPoint displace);


};

#endif // __GUIWINDOW_H__