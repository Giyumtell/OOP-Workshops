/*
Name: Sahar Hosseinichegeni
Student Number: 139670202
Email: shosseinichegeni@myseneca.ca
Date: 21-10-03
Section: NAA
*/
#include "TimedEvents.h"
#include <iomanip>

namespace sdds {
    TimedEvents::TimedEvents()
        : num_records(0) {
    }

    void TimedEvents::startClock() {
        start_time = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock() {
        end_time = std::chrono::steady_clock::now();
    }

    void TimedEvents::addEvent(const char* event_name) {
        events[num_records].event_name = event_name;
        events[num_records].time_unit = "nanoseconds";
        events[num_records].duration = end_time - start_time;
        num_records++;
    }

    std::ostream& operator<<(std::ostream& stream, const TimedEvents& timed_events) {
        stream << std::string(26, '-') << '\n';
        stream << "Execution Times:" << '\n';
        stream << std::string(26, '-') << '\n';
        for (size_t i = 0; i < timed_events.num_records; i++) {
            stream << std::setw(21) << std::setfill(' ') << std::left 
            << timed_events.events[i].event_name << ' ';
            
            stream << std::setw(13) << std::setfill(' ') << std::right
            << timed_events.events[i].duration.count() << ' ';
            
            stream << timed_events.events[i].time_unit << '\n';
        }
        stream << std::string(26, '-') << std::endl;  
        return stream; 
    }
}