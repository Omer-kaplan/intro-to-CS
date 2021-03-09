#include "exam.h"
#include <string.h>
#include <stdlib.h>

isExist(PayBox* pb, int ID)
{
	for (int i = 0; i < pb->clientSize ; i++)
	{
		if (pb->clients[i]->id == ID)
		{
			return 1;
		}
	}
	return 0;
}
int addTransaction(PayBox* pb,int fromID, int toID, float amount, char* date, float amountLimit, char* remark)
 {
	float amountDay = 0.0;
	int i;
	if (isExist(pb, fromID) && isExist(pb, toID)) // Are they Exist?
	{
		//Check if the sum amount with the new one can be sent or over limit
		for (i = 0; i < pb->transSize; i++)
		{
			if (((pb->transactions)[i]->from_ID == fromID) && (strcmp((pb->transactions)[i]->date, date) == 0))
				amountDay += (pb->transactions)[i]->amount;
		}
		if (amountDay + amount > amountLimit)
			return 0;
		// Create new tran, realloc trans arr,  update transzie ++ (V)
		// Update sender - minus the financial, add trans, plus transize++
		// Update Reciver - Plus the financial, add trans, plus transize++
		Transaction* newTran = (Transaction*)malloc(sizeof(Transaction));
		newTran->from_ID = fromID;
		newTran->to_ID = toID;
		newTran->amount = amount;
		strcpy(newTran->date, date);
		newTran->remark = (char*)malloc(strlen(remark) + 1);
		strcpy(newTran->remark, remark);
		
		pb->transactions = (Transaction**)realloc(pb->transactions, ((pb->transSize) + 1) * sizeof(Transaction*));
		pb->transSize += 1;

		pb->transactions[pb->transSize - 1] = newTran; // Sets the tran into the arr in the PB

		for (int i = 0; i < pb->clientSize; i++) // Look for the sender and reciver to update their settings
		{
			if (pb->clients[i]->id == fromID) // The sender
			{
				pb->clients[i]->financialBalance -= amount;
				(pb->clients[i]->transSize)++;
				pb->clients[i]->transactions = (Transaction**)realloc(pb->clients[i]->transactions, (pb->clients[i]->transSize) * sizeof(Transaction*));
			}
			if (pb->clients[i]->id == toID) // The Reciver
			{
				pb->clients[i]->financialBalance += amount;
				(pb->clients[i]->transSize)++;
				pb->clients[i]->transactions = (Transaction**)realloc(pb->clients[i]->transactions, (pb->clients[i]->transSize) * sizeof(Transaction*));
			}
		}

		return 1;
	}
	else
		return 0;
 }
Client** IrsReport(PayBox* pb, char* year, float amount, int* repSize)
{
	// run for each client
	// sums his amount, if bigger than givven amount, add his pointer to the arr and update count++, repsize..
	*repSize = 0;
	Client** matchArr = NULL;
	for (int i = 0; i < pb->clientSize; i++)
	{
		int clientSum = 0;
		for (int j = 0; j < pb->clients[i]->transSize; j++)
		{
			char* tranYear = pb->clients[i]->transactions[j]->date + 4;
			if (strcmp(tranYear, year) == 0)
			{
				clientSum += pb->clients[i]->transactions[j]->amount;
			}
		}
		if (clientSum > amount) // busted
		{
			matchArr = (Client**)realloc(matchArr, ((*repSize) + 1) * sizeof(Client*));
			matchArr[*repSize] = pb->clients[i];
			*repSize += 1;
		}
	}

	return matchArr;
}
