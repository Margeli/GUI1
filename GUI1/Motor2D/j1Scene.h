#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"

struct SDL_Texture;
class GuiImage;
class GuiText;
class GuiButton;
class GuiCheck;


class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

private:
	SDL_Texture* debug_tex;
	GuiImage* background;
	GuiImage* WC_logo;
	GuiImage* rating;
	GuiImage* blizzard;

	GuiButton* login;
	GuiButton* cinematics;
	GuiButton* credits;
	GuiButton* ToU;
	GuiButton* quit;
	GuiButton* manageaccount;
	GuiButton* commsite;
	GuiCheck* check;
	
	GuiText* release;
	GuiText* copyright;
	GuiText* date;
	GuiText* web;

	
};

#endif // __j1SCENE_H__