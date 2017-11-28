#ifndef __j1UIELEM_H__
#define __j1UIELEM_H__

#include "j1Module.h"
#include "SDL\include\SDL_rect.h"
#include "p2Point.h"


struct SDL_Texture;

enum FontType {
	DEFAULT = 0,
	ARIALN,
	FRIZQT,
	MORPHEUS,
	SKURRI
};

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
enum ButtonEvent {

	MOUSE_NONE = 0,
	MOUSE_ENTER,
	MOUSE_LEAVE,
	CLICK_UP,
	CLICK_DOWN

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

	j1UI_Elem(UIType type, Alignment align, j1Module* listener = nullptr);

	// Destructor
	virtual ~j1UI_Elem();

	// Called when before render is available
	virtual bool Awake(pugi::xml_node&) { return true; };

	// Call before first frame
	virtual bool Start();

	// Called all Updates
	virtual bool Update(float dt);

	// Called after all Updates
	virtual bool PostUpdate() { return true; };

	// Called before quitting
	virtual bool CleanUp();

	//sets the pos depending on the alignment
	void UpdateAlignment();
	void UpdateTextAlignment( p2SString text );
	virtual void DebugDraw(); 

	SDL_Texture* LoadTexture(p2SString path);

	SDL_Texture* tex;
	UIType type;
	ButtonEvent event = ButtonEvent::MOUSE_NONE;
	ButtonEvent previous_event = ButtonEvent::MOUSE_NONE;
	ButtonState state = ButtonState::IDLE;
	Alignment align;
	SDL_Rect rect;
	iPoint position;
	iPoint displacement;
	j1Module* listener;


private:
	bool Blit() const { return true; }
	bool debug = false;
};

#endif // __j1UIELEM_H__