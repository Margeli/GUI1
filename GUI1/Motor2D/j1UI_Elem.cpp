#include "j1UI_Elem.h"
#include "j1Gui.h"
#include "j1App.h"
#include "j1Render.h"


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

iPoint j1UI_Elem::DoAlignment(Alignment alignment) {

	switch (alignment) {
	case CENTERED:
		

	case RIGHT:

	case LEFT:
	}

}