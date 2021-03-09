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
	int i,j;
	Event** tmp;
	for(i=0;i<numCalendars;i++)
		for (j = 0; j < cal[i]->evtSize; j++)
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
	for (i = 0; i < numCalendars; i++)
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
	int hour = date.hour;
	int endHour = 17 - duration;
	while (hour<=endHour)
	{
		ev->startDat.hour = hour;
		ev->startDat.min = 0;
		ev->endDat = ev->startDat;
		ev->endDat.hour = hour + duration;
		if (setEvent(cal, numCalendars, ev))
			return ev;
		hour++;
	}
	return NULL;	
}


Event* deleteContactFromEvent(Calendar** cal, int numCalendars, char* email, Event* ev)
{
	int i, j;
	int findContact = 0;
	//Delete event from relevant Calendar
	for(i=0;i<numCalendars && !findContact;i++)
		if (strcmp(cal[i]->owner.emailAddress, email) == 0)
		{
			findContact = 1;
			for (j = 0; j < cal[i]->evtSize && !findContact; j++)
				if (cal[i]->evt[j] == ev)
				{
					cal[i]->evt[j] = cal[i]->evt[cal[i]->evtSize - 1];
					cal[i]->evt = (Event**)realloc(cal[i]->evt, ((cal[i]->evtSize) - 1) * sizeof(Event*));
					cal[i]->evtSize = cal[i]->evtSize - 1;
				}
		}
	//Update event
	if (findContact)
	{
		for (i = 0; i < ev->numOfContacts; i++)
			if (strcmp(ev->cont[i]->emailAddress, email) == 0)
			{
				ev->cont[i] = ev->cont[ev->numOfContacts - 1];
				ev->cont = realloc(ev->cont, (ev->numOfContacts - 1) * sizeof(Contact*));
				--(ev->numOfContacts);
				return ev;
			}
	}
	return ev;

}
