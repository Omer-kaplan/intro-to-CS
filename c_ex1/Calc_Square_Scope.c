/*
Name: Omer Kaplan
ID: 208278036
Goal: This program gets width and height and print its squares scope
*/

#include <stdio.h>

int main()
{
	// Declaring vars 
	double square_width, square_height;

	// Get the squares height and width, prints the scope
	printf("\nPlease enter the squares width:\t");
	scanf_s("%lf", &square_width);
	printf("\nPlease enter the squares height:\t");
	scanf_s("%lf", &square_height);
	printf("\nThe scope is:\t%.2lf\n", ((square_height + square_width) *2));

	return 0;
}