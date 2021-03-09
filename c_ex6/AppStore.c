#include "AppStore.h"
#include <stdlib.h>
#include "Application.h"
#pragma warning(disable : 4996)
/*
* Name: Omer Kaplan
* ID  : 208278036
* Date: 13/01/21
*/

/*
*   Application** apps;
	int num_of_apps;		
	char* name;
*/
/* int ISAppExist(Application** apps, int appNum, char name) // rec. looking for the app
{
	if (appNum == -1)
		return 0;

	if (apps[appNum]->name == name)
	{
		return 1;
	}
	return ISAppExist(apps, (appNum - 1), name);
} */

AppStore* AddApp(AppStore* as, Application* app) // app has name, price and downloads num
{
    if (NULL == as) // create new store "Colman Store" with the properties of app
    {
        AppStore* app_store = (AppStore*)malloc(sizeof(AppStore));
		if (NULL == app_store)
			return NULL;

		app_store->apps = (Application**)malloc(sizeof(Application*));
		if (NULL == app_store->apps)
		{
			FreeAppStore(app_store);
			return NULL;
		}
		
		app_store->apps[0] = DuplicateApp(app); //Dups the app into apps[0]
		if (NULL == app_store->apps[0])
		{
			FreeAppStore(app_store);
			return NULL;
		}
		
		char* first_name = "Colman Store";
		app_store->name = strdup(first_name); //or _strdup
		if (!(app_store->name))
		{
			FreeAppStore(app_store);
			return NULL;
		}
		app_store->num_of_apps = 1;
		
		return app_store;
    }
	
	if (as != NULL) // if exists, dup the as
	{
		AppStore* dup_as = DuplicateStore(as);
		if (!dup_as)
			return NULL;

		int appsNum = dup_as->num_of_apps;
		//int isAppExist = ISAppExist(dup_as->apps, appsNum, app->name);
		int run = as->num_of_apps;
		int i = 0;
		int j = 0;
		while (i < run && j == 0)
		{
			if ((strcmp(dup_as->apps[i]->name, app->name)) == 0)
			{
				dup_as->apps[i]->downloads += app->downloads;
				++j;
				++i;
				return dup_as;
			}
		}

		if (0 == j) // No such app in as
		{
			Application** tmp_apps = dup_as->apps;
			int newSize = (appsNum + 1);
			tmp_apps = (Application**)realloc(dup_as->apps, newSize);
			if (NULL == (tmp_apps))
			{
				FreeAppStore(dup_as);
				return NULL;
			}
			else // create new_app - dup app into it, if null realoc -1, num_of_Apps++
			{
				dup_as->apps = tmp_apps;
				dup_as->apps[appsNum] = DuplicateApp(app);
				if (!(dup_as->apps[appsNum]))
				{
					FreeAppStore(dup_as);
					return NULL;
				}
				(dup_as->num_of_apps)++;
			}
		}
		return dup_as;
	}
	return 0;
}

AppStore* DuplicateStore(AppStore* source)
{
	AppStore* dup_as = (AppStore*)malloc(sizeof(AppStore));
	if (!dup_as)
		return NULL;
	
	// malloc for each var, copy the data of: as.name, num of apps, app** 
	int num_of_apps = source->num_of_apps;
	dup_as->num_of_apps = num_of_apps;

	/* char old_as_name[50];
	strcpy(old_as_name, source->name);
	dup_as->name = _strdup(old_as_name); //or strdup 
	*/
	dup_as->name = (char*)malloc((strlen(source->name) + 1) * sizeof(char*));
	if (NULL == dup_as->name)
	{
		free(dup_as);
		return NULL;
	}
	dup_as->name = source->name;

	dup_as->apps = (Application**)malloc((num_of_apps) * sizeof(Application*));
	if (NULL == (dup_as->apps))
	{
		FreeAppStore(dup_as);
		return NULL;
	}
	for (int i = 0; i < num_of_apps; i++)
	{
		Application* tmpApp = DuplicateApp(source->apps[i]);
		if (!(tmpApp))
		{
			FreeAppStore(dup_as);
			return NULL;
		}
		dup_as->apps[i] = tmpApp;
	}
	return dup_as;
	//return NULL;
}

void SortByCost(AppStore* as)
{
	int size = as->num_of_apps;
	//int max = -1;
	int i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (as->apps[j]->cost > as->apps[j + 1]->cost)
			{
				Application* tmp = (Application*)malloc(sizeof(Application));
				if (NULL != (tmp))
				{
					tmp = as->apps[j + 1];
					as->apps[j + 1] = as->apps[j];
					as->apps[j] = tmp;
				}
			}
		}
	}
}

void SortByName(AppStore* as)
{
	int size = as->num_of_apps;
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (strcmp(as->apps[j]->name, as->apps[j+1]->name) > 0)
			{
				Application* tmp = (Application*)malloc(sizeof(Application));
				if (NULL !=(tmp))
				{
					tmp = as->apps[j + 1];
					as->apps[j + 1] = as->apps[j];
					as->apps[j] = tmp;
				}
			}
		}
	}
}

int TotalDownloads(AppStore* as)
{
	int sum = 0;
	int size = as->num_of_apps;
	
	for (int i = 0; i < size; ++i)
	{
		sum += as->apps[i]->downloads;
	}
	return sum;
}

int UpdateDownloads(AppStore* as, char* name, int toAdd)
{
	int size = as->num_of_apps;
	int isFound = 0;
	for (int i = 0; i < size; ++i)
	{
		if (strcmp(as->apps[i]->name, name) == 0)
		{
			as->apps[i]->downloads += toAdd;
			isFound = 1;
		}
	}
    return isFound;
}

int UpdateCost(AppStore* as, char* name, float newCost)
{
	int size = as->num_of_apps;
	int isFound = 0;
	for (int i = 0; i < size; ++i)
	{
		if (strcmp(as->apps[i]->name, name) == 0)
		{
			as->apps[i]->cost = newCost;
			isFound = 1;
		}
	}
	return isFound;
}

int GetAppDownloads(AppStore* as, char* name)
{
	int size = as->num_of_apps;
	int isDownloaded = -1;
	for (int i = 0; i < size; ++i)
	{
		if (strcmp(as->apps[i]->name, name) == 0)
		{
			isDownloaded = as->apps[i]->downloads;
		}
	}
	return isDownloaded;
}

void FreeAppStore(AppStore* as)
{
	/*int size = as->num_of_apps;
	int i = 0;
	for (i; i < size; ++i)
	{
		if (NULL != as->apps[i])
			FreeApp(as->apps[i]);
	}
	if (NULL != as->name)
		free(as->name);
	free(as);*/
	return 0;
}
