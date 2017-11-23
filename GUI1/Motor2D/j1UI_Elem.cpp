#include "j1UI_Elem.h"
#include "j1Gui.h"
#include "j1Textures.h"
#include "j1App.h"


j1UI_Elem::j1UI_Elem(UIType type) : type(type)
{
	
}

bool j1UI_Elem::Start() {

	//tex = App->tex->Load("gui/atlas.png");
	return true;
}

bool j1UI_Elem::CleanUp() {

	//App->tex->UnLoad(tex);

	return true;
}

j1UI_Elem::~j1UI_Elem()
{
}

