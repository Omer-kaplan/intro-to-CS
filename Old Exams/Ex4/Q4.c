#include "exam.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

Apartment* addAppartment(Airbnb* db, int id, Apartment ap)
{
	// look for the guy, create ap and realloc his arr with the new one
	for (int i = 0; i < db->numOfOwners; i++)
	{
		if (db->owners[i]->id == id) // Found the guy
		{
			// do
			Apartment* newAp = (Apartment*)calloc(1, sizeof(Apartment));
			if (!newAp)
				return NULL;
			
			*newAp = ap;
			Apartment** newApArr = (Apartment**)realloc(db->owners[i]->apartments, (db->owners[i]->numApartments + 1), sizeof(Apartment*));
			if (!newApArr)
			{
				free(newAp);
				return NULL;
			}
			db->owners[i]->apartments = newApArr;
			db->owners[i]->apartments[db->owners[i]->numApartments] = newAp;
			++(db->owners[i]->numApartments);

			return newAp;
		}
	}
}

int isGoodLoc(GpsLocation l1, GpsLocation l2, int radius) // (location, currAp->location)
{
	float tmp = sqrt(pow(l1.xPos - l2.xPos, 2) + pow(l1.yPos - l2.yPos, 2));
	if (tmp <= radius)
		return 1;
	return 0;
}

Apartment** searchApartment(Airbnb* db, GpsLocation location, int radius, float maxPrice, int rooms, int *numRelevantApartments)
{
	*numRelevantApartments = 0;
	Apartment** relAp = NULL;

	for (int i = 0; i < db->numOfOwners; i++)
	{
		for (int j = 0; j < db->owners[i]->numApartments; j++)
		{
			if (isGoodLoc(db->owners[i]->apartments[j]->location, location, radius)) // isGoodLocation
			{
				if (db->owners[i]->apartments[j]->price <= maxPrice) // isGoodPrice
				{
					if (db->owners[i]->apartments[j]->numRooms == rooms) // isGoodRooms
					{
						++(*numRelevantApartments);
						relAp = (Apartment**)realloc(relAp, *numRelevantApartments, sizeof(Apartment*));
						relAp[*numRelevantApartments - 1] = db->owners[i]->apartments[j];
					}
				}
			}
		}
	}
	return relAp;;
}
int checkFacilities(Apartment* ap, int service)
{
	return -1;
}
