#ifndef EXAM_H_
#define EXAM_H_

#ifndef NULL
#define NULL 0
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <math.h>

#define N 5

typedef struct
{
	int from_ID;
	int to_ID;
	float amount;
	char date[9];//ddmmyyyy
	char* remark;
}Transaction;


typedef struct
{
	char* full_name;
	int id;
	float financialBalance; 
	Transaction** transactions;
	int transSize;
}Client;

typedef struct
{
	Client** clients;
	int clientSize;
	Transaction** transactions;
	int transSize;
}PayBox;
//Q4
int addTransaction(PayBox* pb,int fromID, int toID, float amount,
 char* date, float amountLimit, char* remark);
Client** IrsReport(PayBox* pb, char* year, float amount, int* repSize);


//Q1
void crossSort(int mat[][N], int numRows);
//Q2
char *revWord(char inStr[]);
//Q3
int MultEven(int a[], int size);
void fx1();




#endif