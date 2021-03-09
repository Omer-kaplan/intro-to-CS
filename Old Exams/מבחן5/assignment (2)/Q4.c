#include "exam.h"
#include <string.h>
#include <stdlib.h>

int dateCmp(Date d1, Date d2)
{
	if (d1.year < d2.year)
		return -1;
	else if (d1.year > d2.year)
		return 1;
	if (d1.month < d2.month)
		return -1;
	else if (d1.month > d2.month)
		return 1;
	if (d1.day < d2.day)
		return -1;
	else if (d1.day > d2.day)
		return 1;
	if (d1.hour < d2.hour)
		return -1;
	else if (d1.hour > d2.hour)
		return 1;
	if (d1.min < d2.min)
		return -1;
	else if (d1.min > d2.min)
		return 1;
	return 0;
}

int setEvent(Calendar** cal, int numCalendars, Event* ev)
{
	// checks in each cal if can happen
	// if so, reallocs and so..
	int canExist = 1;
	for (int i = 0; i < numCalendars; i++)
	{
		for (int j = 0; j < cal[i]->evtSize; j++)
		{
			if (dateCmp(cal[i]->evt[j]->startDat, ev->startDat) == -1 &&
				dateCmp(cal[i]->evt[j]->endDat, ev->startDat) == 1)
			{
				return 0;
			}
			if (dateCmp(cal[i]->evt[j]->startDat, ev->startDat) >= 0 &&
				dateCmp(cal[i]->evt[j]->endDat, ev->endDat) == -1)
			{
				return 0;
			}
		}
	}
	Event** tmp;
	for (int i = 0; i < numCalendars; i++)
	{
		tmp = (Event**)realloc(cal[i]->evt, (1 + cal[i]->evtSize) * sizeof(Event*));
		if (!tmp)
		{
			//Don't need to take care - assume it succeeded
		}
		cal[i]->evt = tmp;
		cal[i]->evt[cal[i]->evtSize] = ev;
		++(cal[i]->evtSize);
	}

	return 1;
}
Event* findAndSetWorkMeeting(Calendar** cal, int numCalendars, Date date, int duration, Event* ev)
{
	return NULL;
}
Event* deleteContactFromEvent(Calendar** cal, int numCalendars, char* email, Event* ev)
{
	return NULL;
}

