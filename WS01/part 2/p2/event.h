extern unsigned int g_sysClock;
#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_
namespace sdds
{
	class Event
	{
	public:
		Event();
		~Event();
		Event(Event&);
		Event& operator=(Event&);
		void display();
		void set(char* = nullptr);
	private:
		char* m_description = nullptr;
		unsigned int m_eventStart = 0;
	};
}
#endif // !SDDS_EVENT_H_