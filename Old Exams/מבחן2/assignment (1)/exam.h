#ifndef EXAM_H_
#define EXAM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5
#ifndef NULL
#define NULL 0
#endif


typedef enum {sent=1, received, receivedAndRead} Status;
typedef struct{
	char* message;
	Status messageStatus;
}Message;

typedef struct{
	char* name;
	char phoneNumber[14];
	Message** messagesArr;
	int numOfMessages;
}Contact;

typedef struct
{
	char* groupName;
	Contact** contactArr;
	int numContacts;
	Message** groupMessageArr;
	int numOfGroupMessages;
}Group;

typedef struct
{
	Contact** contacts;
	int numOfContacts;
	Group** groups;
	int numOfGroups;
}WhatsApp;

void fx1();
void fx2();
int TakeLastN(int num, int n);
void ChangeFrame(int mat[N][N],int rowCol, int size);
int isDiagonal(int mat[N][N]);
int numberOfSmallLetterWords(char* str);
unsigned int setBitByIndex(unsigned int num, int index);
Message* findLongestMessage (const WhatsApp* app);
int clearHistory(WhatsApp* app, int max);
void deleteWhatsApp (WhatsApp* app);

#endif