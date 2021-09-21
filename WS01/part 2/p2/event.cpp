#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <iomanip>
#include <cstring>
unsigned int g_sysClock = 0;
namespace sdds
{
	Event::~Event()
	{
		delete[] m_description;
		m_description = nullptr;
	}
	Event::Event()
	{
		m_eventStart = 0;

	}
	void Event::display()
	{
		static int counter = 1;
		if (m_description)
		{
			std::cout <<std::setw(2) << std::right << std::setfill(' ') << counter << ". " << std::setw(2) << std::right << std::setfill('0') << (m_eventStart / 60) / 60 << ':' << std::setw(2) << std::right << (m_eventStart / 60) % 60 << ':' << std::setw(2) << std::right << m_eventStart % 60 << " => " << m_description << std::endl;
		}
		else
		{
			std::cout << std::setw(2) << std::right << std::setfill(' ') << counter << ". " << "| No Event |" << std::endl;
		}
		counter++;
	}
	void Event::set(char* arg)
	{
		if (arg)
		{
			delete[] m_description;
			m_description = nullptr;
			m_description = new char[strlen(arg)+1];
			m_eventStart = g_sysClock;
			strcpy(m_description, arg);
		}
		else
		{
			delete[] m_description;
			m_description = nullptr;
			m_eventStart = 0;
		}
	}
	Event::Event(Event& e)
	{
		m_eventStart = e.m_eventStart;
		if (e.m_description)
		{
			delete[] m_description;
			m_description = nullptr;
			m_description = new char[strlen(e.m_description) + 1];
			strcpy(m_description, e.m_description);
		}
		
	}
	Event& Event::operator=(Event& e)
	{
		m_eventStart = e.m_eventStart;
		if (e.m_description)
		{
			delete[] m_description;
			m_description = nullptr;
			m_description = new char[strlen(e.m_description) + 1];
			strcpy(m_description, e.m_description);
		}
		return *this;
	}
}