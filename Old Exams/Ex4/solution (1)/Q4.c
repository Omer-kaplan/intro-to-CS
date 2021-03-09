#include "exam.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

float distance(GpsLocation l1, GpsLocation l2)
{
	return sqrt(pow(l1.xPos - l2.xPos, 2) + pow(l1.yPos - l2.yPos, 2));
}
Apartment* addAppartment(Airbnb* db, int id, Apartment ap)
{
	int i;
	ApartmentOwner* own = NULL;
	Apartment *newApart, **tmp;
	for (i = 0; i < db->numOfOwners; i++)
		if (id == db->owners[i]->id)
		{
			own = db->owners[i];
			break;
		}
	if (!own)
		return NULL;
	newApart = (Apartment*)malloc(sizeof(Apartment));
	if (!newApart)
		return NULL;
	*newApart = ap; //since Apartment dosen't have pointers

	tmp = (Apartment**)realloc(own->apartments, (1 + own->numApartments) * sizeof(Apartment*));
	if (!tmp)
	{
		free(newApart);
		return NULL;
	}
	own->apartments = tmp;
	own->apartments[own->numApartments] = newApart;
	++(own->numApartments);

	return newApart;
}
Apartment** searchApartment(Airbnb* db, GpsLocation location, int radius, float maxPrice, int rooms, int *numRelevantApartments)
{
	int i, j;
	Apartment** relevantAp = NULL, **tmp;
	Apartment* currAp;

	*numRelevantApartments = 0;
	for(i=0;i<db->numOfOwners;i++)
		for (j = 0; j < db->owners[i]->numApartments; j++)
		{
			currAp = db->owners[i]->apartments[j];
			if ((distance(location, currAp->location) <= radius) &&
				(currAp->price <= maxPrice) && currAp->numRooms >= rooms)
			{
				tmp = (Apartment**)realloc(relevantAp, ((*numRelevantApartments) + 1) * sizeof(Apartment*));
				if (!tmp)
				{
					*numRelevantApartments = -1; // to tell outside that the allocation didn't succeed
					free(relevantAp);
					return NULL;
				}
				relevantAp = tmp;
				relevantAp[*numRelevantApartments] = currAp;
				++(*numRelevantApartments);
			}
		}
	return relevantAp;
}
int checkFacilities(Apartment* ap, int service)
{
	unsigned char mask = 1;
	mask <<= service - 1;
	if (ap->facilities & mask)
		return 1;
	else
		return 0;
}
