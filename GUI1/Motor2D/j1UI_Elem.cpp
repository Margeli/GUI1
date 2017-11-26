#include "j1UI_Elem.h"
#include "j1Gui.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"


j1UI_Elem::j1UI_Elem(UIType type, Alignment align) : type(type), align(align)
{
	
}

bool j1UI_Elem::Start() {


	return true;
}

bool j1UI_Elem::CleanUp() {

	

	return true; 
}

j1UI_Elem::~j1UI_Elem()
{
}

SDL_Texture* j1UI_Elem::LoadTexture(p2SString path) {

	SDL_Texture* ret = App->tex->Load(path.GetString());
	return ret;
}

void j1UI_Elem::UpdateAlignment() {

	switch (align) {
	case NONE:
		break;
	case CENTERED:
		position.x = (-App->render->camera.x + App->render->camera.w / 2) -(rect.w / 2);
		position.y = -App->render->camera.y;
		break;
	case RIGHT:
		position.x = (-App->render->camera.x + App->render->camera.w) - rect.w;
		position.y = -App->render->camera.y;
		break;
	case LEFT:
		position.x = -App->render->camera.x;
		position.y = -App->render->camera.y;
		break;
	}
	

}