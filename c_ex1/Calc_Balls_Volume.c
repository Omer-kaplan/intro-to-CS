/*
Name: Omer Kaplan
ID: 208278036
Goal: This program gets a balls radius length and prints the balls volume.
*/

#include <stdio.h>
#include <math.h>

int main()
{
	// Declaring vars
	double radius_length = 0;
	double balls_volume = 0;
	double pow_vol = 3;

	// Input the radius
	printf("\nPlease enter the radius lenght:\t");
	scanf_s("%lf", &radius_length);

	// Calculating the volume - 4*pie*r^3 / 3
	balls_volume = ((4 * 3.14) * (pow(radius_length, pow_vol))) / 3;
	
	printf("\nThe volume is:\t%.2lf\n" , balls_volume);

	return 0;
}