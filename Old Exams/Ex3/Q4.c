#include "exam.h"
#include <string.h>
#include <stdlib.h>
/*
Apartment* addAppartment(Airbnb* db, int id, Apartment ap)
{
	// check for person?
	for (int i = 0; i < db->numOfOwners; i++) {
		if (db->owners[i]->id == id){
			int new_num_ap = db->owners[i]->numApartments + 1;
			Apartment** new_arr = (Apartment**)realloc(db, new_num_ap * sizeof(Apartment*)); // realloc his App** to numApartments++
			
			if (!new_arr)
				return NULL;
			
			// Create new apartnent and set in the new_arr[new_num_ap];
			Apartment* new_ap = (Apartment*)malloc(sizeof(Apartment));
			if (!new_ap)
				return NULL;
			
			// Else, All good --> creates new apartment and store with details
			*new_ap->address = ap.address;
			*new_ap->description = ap.description;
			new_ap->facilities = ap.facilities;
			new_ap->floor = ap.floor;
			new_ap->location = ap.location;
			new_ap->numRooms = ap.numRooms;
			new_ap->price = ap.price;
			new_ap->size = ap.size; 
			new_arr[new_num_ap] = new_ap;
			db->owners[i]->numApartments = new_num_ap;
			return new_ap;
		}
	}
	return NULL;
}
Apartment** searchApartment(Airbnb* db, GpsLocation location, int radius, float maxPrice, int rooms, int *numRelevantApartments)
{
	Apartment** ap_arr = (Apartment**)malloc(sizeof(Apartment*));
	if (ap_arr != NULL)
	{
		for (int i = 0; i < db->numOfOwners; i++) // run for all Ap owners
		{
			*numRelevantApartments = 0;
			for (int j = 0; j < db->owners[i]->numApartments; j++) // foreach owner, for his Ap.
			{
				double pitaguras;
				GpsLocation tmp; // BlaBla
				if (pitaguras <= radius) // radius calc
				{
					if (db->owners[i]->apartments[j]->price <= maxPrice) // Price smaller than maxPrice
					{
						if (db->owners[i]->apartments[j]->numRooms == rooms) // Exactly rooms == numRooms
						{
							Apartment** tmp_ap_arr = (Apartment**)realloc(ap_arr, (*numRelevantApartments + 1) * sizeof(Apartment*));
							if (tmp_ap_arr != NULL)
							{
								ap_arr = tmp_ap_arr;
								*numRelevantApartments++;
								int index = *numRelevantApartments;
								ap_arr[index] = db->owners[i]->apartments[j];// ---> insert the pointer to the found apartment
							}
							else
							{
								// freeAll();
								return NULL;
							}
						}
					}
				}
			}
		}
		return ap_arr;
	}
	else
		return NULL;
}
int checkFacilities(Apartment* ap, int service)
{
	return -1;
}
*/


float distance(GpsLocation l1, GpsLocation l2)
{
	return sqrt(pow(l1.xPos - l2.xPos, 2) + pow(l1.yPos - l2.yPos, 2));
}
Apartment* addAppartment(Airbnb* db, int id, Apartment ap)
{
	
	for (int i = 0; i < db->numOfOwners; i++)
	{
		if (db->owners[i]->id == id)
		{
			// tmp_ap
			Apartment* tmp_Apar = (Apartment*)malloc(sizeof(Apartment));
			if (!tmp_Apar)
				return NULL;
			
			// tmp apArr
			Apartment** tmp_Apar_Arr = (Apartment**)realloc( db->owners[i]->apartments ,(db->owners[i]->numApartments + 1) ,sizeof(Apartment*));
			if (!tmp_Apar_Arr)
			{
				free(tmp_Apar);
				return NULL;
			}

			*tmp_Apar = ap;
			tmp_Apar_Arr[db->owners[i]->numApartments++] = tmp_Apar;
			db->owners[i]->apartments = tmp_Apar_Arr;

			return tmp_Apar;
		}
	}
	return NULL;
}

Apartment** searchApartment(Airbnb* db, GpsLocation location, int radius, float maxPrice, int rooms, int* numRelevantApartments)
{
	int i, j;
	*numRelevantApartments = 0;
	Apartment** goodApar = NULL, **tmp; // (Apartment**)calloc(1, sizeof(Apartment*));
	
	for (i = 0; i < db->numOfOwners; i++) // Foreach owner
		for (j = 0; j < db->owners[i]->numApartments; j++) // Foreach owners Apartment
		{
			GpsLocation l1 = db->owners[i]->apartments[j]->location; // Tmp GPSLocation for conviniancy
			if (distance(l1, location) <= radius &&
				db->owners[i]->apartments[j]->price <= maxPrice &&
				db->owners[i]->apartments[j]->numRooms == rooms) // All The Conditions
			{
				tmp = (Apartment**)realloc(goodApar, *numRelevantApartments + 1, sizeof(Apartment*));
				if (!tmp) // Bad alloc
					return NULL; // Can set *numRelevantApartments to -1 to tell of a problem

				goodApar = tmp;
				goodApar[*numRelevantApartments++] = db->owners[i]->apartments[j]; // Sets in the Apar, than ++ num of Aparts.
			}
		}
	return goodApar;
}

int checkFacilities(Apartment* ap, int service)
{
	return -1;
}