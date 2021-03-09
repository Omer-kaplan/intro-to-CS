#include "exam.h"

Message* findLongestMessage (const WhatsApp* app)
{
	Message* longest_msg = app->contacts[0]->messagesArr[0]->message;
	int num_conts = app->numOfContacts;
	int num_messegaes = NULL;

	// runs for all contacts and looking for the longest
	for (int i = 0; i < num_conts; i++) // foreach contact
	{
		num_messegaes = app->contacts[i]->numOfMessages;

		for (int j = 0; j < num_messegaes; j++) // foreach message
		{
			int message_len = strlen(app->contacts[i]->messagesArr[j]->message);
			if (message_len > strlen(longest_msg)) // finds the longest message
				longest_msg = app->contacts[i]->messagesArr[j]->message;
		}
	}

	// runs for all groups and looking for the longest
	int num_groups = app->numOfGroups;
	for (int i = 0; i < num_groups; i++) // foreach group
	{
		int num_messegaes = app->groups[i]->numOfGroupMessages;
		for (int j = 0; j < num_messegaes; j++) // foreach groups message
		{
			int message_len = strlen(app->groups[i]->groupMessageArr[j]->message);
			if (message_len > strlen(longest_msg))
				longest_msg = app->groups[i]->groupMessageArr[j]->message;
		}
	}

	return longest_msg;
}
void FreeMsg(Message* msg)
{
	free(msg->message);
	free(msg);
}
Message** ClearMesages(Message** arr, int arr_size, int max, int* newSize) // newsize == *arr_size
{
	Message** new_arr = (Message**)calloc(arr_size, sizeof(Message*));
	int newArrSize = 0;
	
	for (int i = 0; i < arr_size; i++) // runs for all messages
	{
		if (strlen(arr[i]->message) > max) // check if size smaller than max
			FreeMsg(arr[i]);
		else
			new_arr[newArrSize++] = arr[i];
	}
	free(arr); // no need anymore - the last arr
	new_arr = (Message**)realloc(new_arr, newArrSize * sizeof(Message*)); // realloc for efficiency 
	*newSize = newArrSize; // updating the WA with the new msg size
	
	return new_arr;
}
int clearHistory(WhatsApp* app, int max)
{
	int flag_Change = 0;
	Message** newArr = NULL;
	Message** arr = NULL;
	int messageArrSize, newSize;

	for (int i = 0; i < app->numOfContacts; ++i)
	{
		arr = app->contacts[i]->messagesArr;
		messageArrSize = app->contacts[i]->numOfMessages;
		newArr = ClearMesages(arr, messageArrSize, max, &newSize);

		if (newSize < messageArrSize)
			flag_Change = 1;

		app->contacts[i]->messagesArr = newArr;
		app->contacts[i]->numOfMessages = newSize;
	}
	for (int i = 0; i < app->numOfGroups; ++i)
	{
		arr = app->groups[i]->groupMessageArr;
		messageArrSize = app->groups[i]->numOfGroupMessages;
		newArr = ClearMesages(arr, messageArrSize, max, &newSize);

		if (newSize < messageArrSize)
			flag_Change = 1;

		app->groups[i]->groupMessageArr = newArr;
		app->groups[i]->numOfGroupMessages = newSize;
	}
	return flag_Change;
}
void FreeContact(Contact* c)
{
	free(c->name);
	for (int i = 0; i < c->numOfMessages; i++)
	{
		FreeMsg(c->messagesArr[i]);
	}
	free(c->messagesArr);
	free(c);
}
void FreeGroups(Group* g)
{
	free(g->groupName);
	free(g->contactArr); // assume all contacts were deleted in FreeCont...
	for (int i = 0; i < g->numOfGroupMessages; i++)
	{
		FreeMsg(g->groupMessageArr[i]);
	}
	free(g->groupMessageArr);
}
void deleteWhatsApp (WhatsApp* app)
{
	// use free conts, group & msgs

	for (int i = 0; i < app->numOfContacts; i++)
	{
		FreeContact(app->contacts[i]);
	}
	free(app->contacts);

	for (int j = 0; j < app->numOfGroups; j++)
	{
		FreeGroups(app->groups[j]);
	}
	free(app->groups);

	free(app);
}
