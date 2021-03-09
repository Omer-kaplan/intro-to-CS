#pragma once
#pragma warning(disable : 4996) // Disables the unsfe warning for strcpy

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COLS 10
#define ROWS 5
#define MAX_ARR_SIZE 10
#define MAX_STRING_SIZE 100

// int compareStr(void* p_a, void* p_b);
void SortByAB(char matStr[][COLS], int rows, int cols);

void SortByLenght(char matStr[][COLS], int rows, int cols);

void AnalyseArray(int* arr, int size, double* avg, int* startIdx);

int Separate(char* str, char separator, char** words, int* lengths);

char* ReverseWords(char* words);