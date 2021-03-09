#pragma once
#include <stdio.h>

#define NAMES 3
#define GRADES 5
#define SIZE1 8
#define SIZE2 6
#define ROWS 4
#define COLS 5

float Avg(int mat[][GRADES]);
int diff(int arr1[], int size1, int arr2[], int size2);
void computeDominance(int p[][COLS], int d[][COLS], int rows);
int max_rect_at_point(int p[][COLS], int d[][COLS], int i, int j);