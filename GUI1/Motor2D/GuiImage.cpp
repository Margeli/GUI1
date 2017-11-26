#include "GuiImage.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"
#include "j1App.h"
#include "j1Render.h"



GuiImage::GuiImage(Alignment alignment): j1UI_Elem(UIType::IMAGE, Alignment::NONE){
	align = alignment;
	
}


GuiImage::~GuiImage()
{
}

bool GuiImage::Start() {

	if (tex==nullptr)
		tex = App->gui->GetAtlas();
	return true;
}

bool GuiImage::CleanUp() {

	//App->tex->UnLoad(tex);
	return true;

}

bool GuiImage::Update(float dt) {

	UpdateAlignment();
	App->render->Blit(tex, position.x + displacement.x, position.y + displacement.y, &rect);
	return true;
}