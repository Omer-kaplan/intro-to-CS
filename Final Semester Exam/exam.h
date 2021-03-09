#ifndef EXAM_H_
#define EXAM_H_

#ifndef NULL
#define NULL 0
#endif

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define N 5


typedef struct
{
	int x, y;
}Location;

typedef struct
{
	int id;
	Location location;
	int batteryLevel; //range 0-5
	char status; //1- available, 2- not available, 3- broken
}Scooter;

typedef struct
{
	char date[9]; // ddmmyyyy   e.g. 25032020 means 20/03/2020
	Location from, to;
	int scooterId;
	int minutes;
	int clientID;
	float price;
}Ride;


typedef struct
{
	char fname[20];
	char lname[20];
	int id;
	Location location;
	int numRides;
	Ride** rides;
}Client;

typedef struct
{
	int numScooters;
	Scooter** scooters;
	int numRides;
	Ride** rides;
	int numClients;
	Client** clients;
}Lime;

//Q4
Scooter** findRelevantScooters(Lime* lime, Client* client,
	int maxDistance, int minimumBattery, int* numAvailable);

void addNewRide(Lime* lime, Client* client, int scooterID, Location destination, int minutes, float pricePerMinute,
	char* date);

//Q1
int maxSum(int a[], int n);
//Q2
char *cleanExcessBlanks(char *text);
//Q3
int isSuminArr(int arr[], int size, int sum);

void fx1();




#endif