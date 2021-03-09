#include "exam.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

int addTransaction(PayBox* pb, int fromID, int toID, float amount,
	char* date, float amountLimit, char* remark)
{
	float amountDay = 0.0;
	Client *sendClient = NULL, *reciveClient = NULL;
	Transaction* trn;
	int i;
	//Check if the clients exist
	for (i = 0; i < pb->clientSize; i++)
	{
		if ((pb->clients)[i]->id == fromID)
			sendClient = (pb->clients)[i];
		if ((pb->clients)[i]->id == toID)
			reciveClient = (pb->clients)[i];
		if (sendClient != NULL && reciveClient != NULL)
			break;
	}
	if (sendClient == NULL || reciveClient == NULL)
		return 0;
	//Check is the accumulated amount is lower than amountLimit
	for (i = 0; i < pb->transSize; i++) 
	{
		if (((pb->transactions)[i]->from_ID == fromID) &&
			(strcmp((pb->transactions)[i]->date, date) == 0))
			amountDay += (pb->transactions)[i]->amount;
	}
	if (amountDay + amount > amountLimit)
		return 0;
	//Update PayBox with new Transaction
	pb->transactions = (Transaction**)realloc(pb->transactions, ((pb->transSize) + 1) * sizeof(Transaction*));
	pb->transSize += 1;
	pb->transactions[(pb->transSize) - 1] = (Transaction*)malloc(sizeof(Transaction));
	trn = pb->transactions[(pb->transSize) - 1];
	trn->amount = amount;
	trn->from_ID = fromID;
	trn->to_ID = toID;
	strcpy(trn->date, date);
	trn->remark = (char*)malloc(strlen(remark) + 1);
	strcpy(trn->remark, remark);

	//Update PayBox on Clients array
	sendClient->financialBalance -= amount;
	reciveClient->financialBalance += amount;
	sendClient->transactions = (Transaction**)realloc(sendClient->transactions, ((sendClient->transSize) + 1) * sizeof(Transaction*));
	reciveClient->transactions = (Transaction**)realloc(reciveClient->transactions, ((reciveClient->transSize) + 1) * sizeof(Transaction*));
	sendClient->transactions[sendClient->transSize] = trn;
	reciveClient->transactions[reciveClient->transSize] = trn;
	sendClient->transSize += 1;
	reciveClient->transSize += 1;

	return 1;
}
Client** IrsReport(PayBox* pb, char* year, float amount, int* repSize)
{
	Client** report = NULL;
	*repSize = 0;
	int i,j;
	float clientAmount;
	
	for (i = 0; pb->clientSize; i++)
	{
		clientAmount = 0;
		for (j = 0; j < (pb->clients[i])->transSize; j++)
			if (strcmp(year, (((pb->clients[i])->transactions[j])->date + 4)) == 0)
				clientAmount += ((pb->clients[i])->transactions[j])->amount;

		if (clientAmount > amount)
		{
			report = (Client**)realloc(report, ((*repSize) + 1) * sizeof(Client*));
			report[(*repSize)] = (pb->clients)[i];
			(*repSize) += 1;
		}
	}
	return report;
}