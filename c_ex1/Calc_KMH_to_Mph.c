/*
Name: Omer Kaplan
ID: 208278036
Goal: This program gets speed in km/h and print its miles/h
*/

#include <stdio.h>
int main()
{
	// Declare vars
	double input_kmh, output_miles;

	printf("--------------------------------------------------------------");
	printf("\nPlease enter speed in km/h format:\t");
	scanf_s("%lf", &input_kmh);
	
	// Transport to miles per hour and print it
	output_miles = input_kmh / 1.609344;
	printf("\nThe speed in miles is:\t %.2f\n", output_miles);
	printf("--------------------------------------------------------------\n");

	return 0;
}