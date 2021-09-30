#define _CRT_SECURE_NO_WARNINGS
#include "TimedEvents.h"
#include <cstring>
#include <iomanip>
namespace sdds
{
	TimedEvents::~TimedEvents()
	{
		for (int i = 0; i < numberOfRecords; i++)
		{
			delete[] eventObjs[i].eventName;
			delete[] eventObjs[i].unitsOfTime;
		}
	}
	void TimedEvents::startClock()
	{
		startTime = std::chrono::system_clock::now();
	}
	void TimedEvents::stopClock()
	{
		endTime = std::chrono::system_clock::now();
	}
	void TimedEvents::addEvent(const char* eventName)
	{
		eventObjs[numberOfRecords].eventName = new char[strlen(eventName) + 1];
		strcpy(eventObjs[numberOfRecords].eventName, eventName);
		eventObjs[numberOfRecords].unitsOfTime = new char[strlen("nanoseconds") + 1];
		strcpy(eventObjs[numberOfRecords].unitsOfTime, "nanoseconds");
		eventObjs[numberOfRecords].eventDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		numberOfRecords++;
	}
	std::ostream& operator<<(std::ostream& ostr, TimedEvents& obj)
	{
		ostr << "--------------------------\nExecution Times:\n--------------------------\n";
		for (int i = 0; i < obj.numberOfRecords; i++)
		{
			ostr << std::setw(21) << std::left << obj.eventObjs[i].eventName << std::setw(13) << std::right << obj.eventObjs[i].eventDuration.count()<< " " << obj.eventObjs[i].unitsOfTime << std::endl;
		}
		ostr << "--------------------------\n";
		return ostr;
	}
}