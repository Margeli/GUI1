#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "j1UI_Elem.h"



j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	p2List_item<j1UI_Elem*>* elem;

	for (elem = elements.start; elem != NULL; elem = elem->next)
	{
		elem->data->Start();
	}

	return true;
}

// Update all guis
bool j1Gui::Update(float dt)
{
	p2List_item<j1UI_Elem*>* elem;

	for (elem = elements.start; elem != NULL; elem = elem->next)
	{
		elem->data->Update(dt);
	}

	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	App->tex->UnLoad(atlas);
	LOG("Freeing GUI");
	p2List_item<j1UI_Elem*>* elem;

	for (elem = elements.start; elem != NULL; elem = elem->next)
	{
		elem->data->CleanUp();
		DestroyElement(elem->data);
	}
	elements.clear();
	return true;
}

// const getter for atlas
SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}



// class Gui ---------------------------------------------------

void j1Gui::DestroyElement(j1UI_Elem* elem) {
		
	int num = elements.find(elem);
	RELEASE(elements.At(num)->data);
	elements.del(elements.At(num));
}

j1UI_Elem* j1Gui::AddElement(UIType type, Alignment alignment ) {

	j1UI_Elem* ret = nullptr;

	switch (type)
	{
	case CHECK:
		ret = new GuiCheck(alignment);
		elements.add(ret);
		break;
	case IMAGE:
		ret = new GuiImage(alignment);
		elements.add(ret);
		break;
	case BUTTON:
		ret = new GuiButton(alignment);
		elements.add(ret);
		break;
	case INPUTBOX:
		ret = new GuiInput(alignment); 
		elements.add(ret);
		break;
	case TEXT:
		ret = new GuiText(alignment);
		elements.add(ret);
		break;	
	}
	return ret;
}

GuiImage* j1Gui::AddImage(Alignment align, char* path, SDL_Rect texture, iPoint displacement) {
	GuiImage* image = (GuiImage*)App->gui->AddElement(IMAGE, align);;
	image->rect = texture;
	image->displacement = displacement;
	if (path != nullptr) {	
		p2SString pat = path;
		image->tex = image->LoadTexture(pat.GetString());
	}
	return image;
}

GuiButton* j1Gui::AddButton(Alignment align, p2SString path, SDL_Rect texture, iPoint displacement) {
	GuiButton* button = (GuiButton*)App->gui->AddElement(BUTTON, align);;
	button->rect = texture;
	button->displacement = displacement;
	button->tex = button->LoadTexture(path.GetString());
	return button;

}

GuiCheck* j1Gui::AddCheck(Alignment align, p2SString path, SDL_Rect texture, iPoint displacement) {
	GuiCheck* check = (GuiCheck*)App->gui->AddElement(CHECK, align);
	check->rect = texture;
	check->displacement = displacement;
	check->tex = check->LoadTexture(path.GetString());
	return check;

}

GuiText* j1Gui::AddText(Alignment align, p2SString text, iPoint displacement) {
	GuiText* tex = (GuiText*)App->gui->AddElement(TEXT, align);
	tex->CreateText(text);
	tex->displacement = displacement;
	return tex;

}