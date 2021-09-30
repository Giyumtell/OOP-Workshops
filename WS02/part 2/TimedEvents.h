#ifndef SDDS_TIMEDEVENTS_H_
#define SDDS_TIMEDEVENTS_H_
#include <chrono>
#include <iostream>
#include <cstring>
namespace sdds
{
	struct Event
	{
		char* eventName = nullptr;
		char* unitsOfTime = nullptr;
		std::chrono::steady_clock::duration eventDuration;
	};
	class TimedEvents
	{
	public:
		~TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char*);
		friend std::ostream& operator<< (std::ostream& ,TimedEvents&);
	private:
		Event eventObjs[10];
		int numberOfRecords = 0;
		std::chrono::time_point<std::chrono::system_clock> startTime;
		std::chrono::time_point<std::chrono::system_clock> endTime;
		;
	};
	
}
#endif // !SDDS_TIMEDEVENTS_H_