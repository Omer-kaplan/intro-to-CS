#include "exam.h"
#include <string.h>
#include <stdlib.h>

#define TREE 1
#define STONE 2
#define ICE 3

Bird* createNewBird(char* name, char* color, int injury, int pen)
{
	Bird* bird = (Bird*)malloc(sizeof(Bird));
	bird->name = (char*)malloc((strlen(name) + 1)*sizeof(char));
	strcpy(bird->name, name);
	strcpy(bird->color, color);
	bird->injuryPower = injury;
	bird->penetrationType = pen;

	return bird;
}

void pigsPowerReduceBirds(const Level *level, int out_pigsPower[3])
{
	int pigsStone = 0, pigsTree = 0, pigsIce = 0;
	int i;
	//Counts all picgs power by type of hiding
	for (i = 0; i < level->pigSize; i++)
	{
		if (level->pigsArr[i]->status == TREE)
			pigsTree += level->pigsArr[i]->strength;
		else if (level->pigsArr[i]->status == STONE)
			pigsStone += level->pigsArr[i]->strength;
		else if (level->pigsArr[i]->status == ICE)
			pigsIce += level->pigsArr[i]->strength;
	}
	//Reduce birds power from accumulated pigs power
	for (i = 0; i < level->birdsSize; i++)
	{
		if (level->birdsArr[i]->penetrationType == TREE)
			pigsTree -= level->birdsArr[i]->injuryPower;
		else if (level->birdsArr[i]->penetrationType == STONE)
			pigsStone -= level->birdsArr[i]->injuryPower;
		else if (level->birdsArr[i]->penetrationType == ICE)
			pigsIce -= level->birdsArr[i]->injuryPower;
	}
	out_pigsPower[0] = pigsTree;
	out_pigsPower[1] = pigsStone;
	out_pigsPower[2] = pigsIce;
}

int isPassableLevel (const Level* level)
{
	int pigP[3];
	pigsPowerReduceBirds(level, pigP);
	if(pigP[0] > 0 || pigP[1] > 0 || pigP[2] > 0)
		return 0;
	else return 1;
}
//This function assume all memory allocation succeeds
Level* fixLevel(Level* level, int max)
{
	int pigP[3],i;
	int residual, birdToAdd;
	int orginalBirdsSize = level->birdsSize;
	pigsPowerReduceBirds(level, pigP);
	Bird** tmp;
	//Need to add birds that penetrates tree
	if (pigP[0] > 0)
	{
		residual = 0;
		if (pigP[0] % max != 0)
			residual = 1;
		birdToAdd = (pigP[0] / max) + residual;
		level->birdsArr = (Bird**)realloc(level->birdsArr, (level->birdsSize + birdToAdd) * sizeof(Bird*));
		for (i = 0; i < birdToAdd; i++)
			level->birdsArr[level->birdsSize + i] = createNewBird("", "red", max, TREE);
		level->birdsSize += birdToAdd;
	}
	if (pigP[1] > 0)
	{
		residual = 0;
		if (pigP[1] % max != 0)
			residual = 1;
		birdToAdd = (pigP[1] / max) + residual;
		level->birdsArr = (Bird**)realloc(level->birdsArr, (level->birdsSize + birdToAdd) * sizeof(Bird*));
		for (i = 0; i < birdToAdd; i++)
			level->birdsArr[level->birdsSize + i] = createNewBird("", "yellow", max, STONE);
		level->birdsSize += birdToAdd;
	}
	if (pigP[2] > 0)
	{
		residual = 0;
		if (pigP[2] % max != 0)
			residual = 1;
		birdToAdd = (pigP[2] / max) + residual;
		level->birdsArr = (Bird**)realloc(level->birdsArr, (level->birdsSize + birdToAdd) * sizeof(Bird*));
		for (i = 0; i < birdToAdd; i++)
			level->birdsArr[level->birdsSize + i] = createNewBird("", "black", max, ICE);
		level->birdsSize += birdToAdd;
	}

	return level;
}
void deleteLevel(Level* level)
{
	int i;
	for (i = 0; i < level->birdsSize; i++)
	{
		free(level->birdsArr[i]->name);
		free(level->birdsArr[i]);
	}
	for (i = 0; i < level->pigSize; i++)
	{
		free(level->pigsArr[i]->name);
		free(level->pigsArr);
	}
	free(level->birdsArr);
	free(level->pigsArr);
	free(level);
}
