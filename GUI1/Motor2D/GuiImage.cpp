#include "GuiImage.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1Textures.h"
#include "j1App.h"



GuiImage::GuiImage(): j1UI_Elem(UIType::IMAGE, Alignment::NONE)
{


}


GuiImage::~GuiImage()
{
}

bool GuiImage::Start() {

	tex = App->gui->GetAtlas();
	return true;
}