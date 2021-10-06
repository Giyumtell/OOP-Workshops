/*
Name: Sahar Hosseinichegeni
Student Number: 139670202
Email: shosseinichegeni@myseneca.ca
Date: 21-10-03
Section: NAA
*/
#ifndef TIMED_EVENTS_H
#define TIMED_EVENTS_H

#include <string>
#include <chrono>
#include <iostream>

namespace sdds {
    struct Event {
        std::string event_name;
        std::string time_unit;
        std::chrono::steady_clock::duration duration;
    };

    class TimedEvents {
    public:
        TimedEvents();
        void startClock();
        void stopClock();
        void addEvent(const char* event_name);

        friend std::ostream& operator<<(std::ostream& stream, const TimedEvents& timed_events);

        
    private:
        size_t num_records;
        std::chrono::steady_clock::time_point start_time;
        std::chrono::steady_clock::time_point end_time;
        
        static const size_t MAX_EVENTS {10};
        Event events[MAX_EVENTS];
    };
}

#endif