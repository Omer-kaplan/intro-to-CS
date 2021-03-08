/*
* Name: Omer Kaplan
* ID: 208278036
* Goal: This progrem gets hours number and minutes number,
sums up the min. no. then prints how many minutes there are.
*/

#include <stdio.h>

int main()
{
	// Declare vars
int minutes, hours, hoursToMinutes;

printf("\nPlease enter number of hours:\t");
scanf_s("%d", &hours);
printf("\nPlease enter number of minutes:\t");
scanf_s("%d", &minutes);
hoursToMinutes = hours * 60;
printf("\nThe sum (Total) is:\t%d\n", (hoursToMinutes + minutes)); 

	return 0;
}