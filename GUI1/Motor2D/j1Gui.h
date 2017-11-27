#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "p2List.h"
#include "j1UI_Elem.h"
#include "GuiImage.h"
#include "GuiText.h"
#include "GuiInput.h"
#include "GuiCheck.h"
#include "GuiButton.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes



class j1UI_Elem;

// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool Update(float dt);

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions

	SDL_Texture* GetAtlas() const;


	GuiImage* AddImage(Alignment align, char* path , SDL_Rect texture = { 0,0,0,0 }, iPoint displacement = { 0,0 });
	GuiButton* AddButton(Alignment align, p2SString text, iPoint displacement = { 0,0 });
	GuiCheck* AddCheck(Alignment align, p2SString text, iPoint displacement = { 0,0 });
	GuiText* AddText(Alignment align, p2SString text, iPoint displacement = { 0,0 }, FontType= DEFAULT, SDL_Color color = { 255,255,255,255 } );

	void DestroyElement(j1UI_Elem* elem);

private:
	j1UI_Elem* AddElement(UIType type, Alignment aligment = NONE);

	p2List<j1UI_Elem*> elements;
	SDL_Texture* atlas;
	p2SString atlas_file_name;
};

#endif // __j1GUI_H__