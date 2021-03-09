#include "Application.h"
#pragma warning(disable : 4996)

Application* CreateNewApp(char* _name, float _cost, int _downloads)
{
	// Returns new DinamicAlloc App 
	Application* app = (Application*)(malloc(sizeof(Application))); // Alloc app struct
	if (NULL == app)
		return NULL;

	//char buffer[50]; // Sets var for name
	//strcpy(buffer, _name);
	app->name = (char*)(malloc((strlen(_name)+ 1) * sizeof(char)));
	if (app->name)
		strcpy(app->name, _name);
	else
	{
		FreeApp(app); // free app struct
		return NULL;
	}

	app->cost = _cost; // Sets costs and downloads
	app->downloads = _downloads;

	return app;
}

Application* DuplicateApp(Application* source)
{
	Application* new_app = CreateNewApp(source->name, source->cost, source->downloads);
	return new_app;
}

void FreeApp(Application* app)
{
	if(NULL != app->name)
		free(app->name);
	free(app);
}
