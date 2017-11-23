#ifndef __j1UIELEM_H__
#define __j1UIELEM_H__

#include "j1Module.h"
#include "SDL\include\SDL_rect.h"
#include "p2Point.h"


struct SDL_Texture;

enum UIType {
	CHECK = 1,
	IMAGE,
	BUTTON,
	INPUTBOX,
	TEXT
};
enum ButtonState {
	PRESSED = 1,
	IDLE,
	DISABLED
};

enum Alignment {
	NONE,
	LEFT = 1,
	CENTERED,
	RIGHT
};
// ---------------------------------------------------
class j1UI_Elem : j1Module
{
public:

	j1UI_Elem(UIType type, Alignment align);

	// Destructor
	virtual ~j1UI_Elem();

	// Called when before render is available
	virtual bool Awake(pugi::xml_node&) { return true; };

	// Call before first frame
	virtual bool Start();

	// Called before all Updates
	virtual bool Update(float dt) { return true; };

	// Called after all Updates
	virtual bool PostUpdate() { return true; };

	// Called before quitting
	virtual bool CleanUp();

	//sets the pos depending on the alignment
	void UpdateAlignment();


	SDL_Texture* tex;
	UIType type;
	Alignment align;
	SDL_Rect rect;
	iPoint position;

private:
	bool Blit() const { return true; }
};

#endif // __j1UIELEM_H__