#ifndef EXAM_H_
#define EXAM_H_

#define M 4
#ifndef NULL
#define NULL 0
#endif

typedef struct
{
	char* name;
	int status;
	int strength;
}Pig;

typedef struct
{
	char* name;
	char color[10];
	int injuryPower;
	int penetrationType;
}Bird;

typedef struct
{
	Bird** birdsArr;
	int birdsSize;
	Pig** pigsArr;
	int pigSize;
}Level;

void calcSum(int arr_in[][M], int arr_sum[][M], int rows);
char *removeBlanks(char *str);
int getBitByIndex(unsigned int num, int index); 
int toStart(int num, int start);
int merge(int n1, int n2);
int isPassableLevel (const Level* level);
Level* fixLevel(Level* level, int max);
void deleteLevel(Level* level);


void fx1();
void fx2();


#endif