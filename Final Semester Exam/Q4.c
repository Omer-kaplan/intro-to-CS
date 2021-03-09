#include "exam.h"
#include <Math.h>
#pragma warning(disable:4996)

// *** double pow(double x, double y) ***//

int isGoodDist(Location l1, Location l2, int maxDist) // 2 Locations and max between them
{
	// Both Pow & Sqrt requires Double Type num;
	double x1 = (double)l1.x, x2 = (double)l2.x;
	double y1 = (double)l1.y, y2 = (double)l2.y;

	// square Like Pithagoras A^2 + B^2 = c^2
	double dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)); // Sets the dist between Scooter and person
	
	if (dist <= maxDist) // Checks Good Dist or Not
		return 1;
	return 0;
}

//** Can assume all alocs are good! **//
Scooter** findRelevantScooters(Lime* lime, Client* client, int maxDistance, int minimumBattery, int* numAvilable)
{
	// Decleraing my Vars
	int i, goodDist;
	Scooter** relScootArr = NULL;
	*numAvilable = 0;

	// search Foreach Scooter if good with criterias: 
	// (1) Dist. between Scoot & man <= maxDist.
	// (2) battery status is >= minBattery
	// (3) is Scooter status == 1 --isAvailable 
	for (i = 0; i < lime->numScooters; i++)
	{
		Scooter* tmpScoot = lime->scooters[i]; // Using tmp for clear writing and understanding
		goodDist = isGoodDist(tmpScoot->location, client->location, maxDistance); // Checks if Disatance is good and returns 0,1

		if (goodDist && tmpScoot->batteryLevel >= minimumBattery && tmpScoot->status == '1')
		{
			relScootArr = (Scooter**)realloc(relScootArr, *(numAvilable + 1), sizeof(Scooter*));
			relScootArr[*numAvilable++] = tmpScoot;  // sets ++ after current run  --- *numAvilable++;
		}

	}

	// Return updated Relevant Pointers Array for good Scooter
	return relScootArr;
}


Location rideFrom(Lime* lime, int scooterID) // finds the last location of the givven Scooter
{
	for (int i = 0; i < lime->numScooters; i++)
	{
		if (lime->scooters[i]->id == scooterID)
			return lime->scooters[i]->location;
	}
}
int isScooter(Lime* lime, int scooterID) // Scans is Scooter exist
{
	for (int i = 0; i < lime->numScooters; i++)
	{
		if (lime->scooters[i]->id == scooterID)
			return 1;
	}
	return 0;
}

//** Can assume all alocs are good! **//
void addNewRide(Lime* lime, Client* client, int scooterID, Location destination, int minutes, float pricePerMinute,
	char* date)
{
	// Alloc the new Ride with its param
	Ride* newRide = NULL;
	int i;

	// If Scooter exists, finds its last location then sets its parameters
	if (isScooter(lime, scooterID))
	{
		newRide = (Ride*)calloc(1, sizeof(Ride));
		newRide->clientID = client->id;
		newRide->scooterId = scooterID;
		strcpy(newRide->date, date);
		newRide->from = rideFrom(lime, scooterID); // Searching last scooters location 
		newRide->to = destination;
		newRide->minutes = minutes;
		float newPrice = (pricePerMinute * minutes) + 5;
		newRide->price = newPrice;

		// Realloc client's rides & lime.rides 
		// Adds the ride then ++numRides both
		lime->rides = (Ride**)realloc(lime->rides, (lime->numRides + 1), sizeof(Ride*));
		lime->rides[lime->numRides++] = newRide;

		client->rides = (Ride**)realloc(client->rides, (client->numRides + 1), sizeof(Ride*));
		client->rides[client->numRides++] = newRide;
	}
	// return -1; // Not found, But Void cannot return a value.
}