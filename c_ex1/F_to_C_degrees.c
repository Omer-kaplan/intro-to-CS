/*
Name: Omer Kaplan
ID: 208278036
Goal: This program gets a number (F. degrees) and output its transpormation 
to C. degrees.
*/

#include <stdio.h>

int main()
{
	// Declaring variables 
	float far_degress, cel_degrees;

	// Input Fahrenheit
	printf("\nPlease enter the temperature in Fahrenheit:\t");
	scanf_s("%f", &far_degress);

	// Converting to Celsius
	cel_degrees = ((double)far_degress - 32) / 1.8;

	printf("\nCelsius:\t%.2f\n", cel_degrees);
	
	return 0;
}