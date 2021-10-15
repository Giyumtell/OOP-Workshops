#include "Restaurant.h"
namespace sdds
{
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		m_res = new Reservation[cnt];
		m_cnt = cnt;
		for (size_t i = 0; i < cnt; i++)
		{
			m_res[i] = *reservations[i];
		}
	}
	Restaurant::Restaurant(Restaurant& other)
	{
		if (&other != this)
		{
			delete[] m_res;
			m_res = nullptr;
			m_cnt = other.size();
			m_res = new Reservation[m_cnt];
			for (size_t i = 0; i < m_cnt; i++)
			{
				m_res[i] = other.m_res[i];
			}
		}
	}
	Restaurant::Restaurant(Restaurant&& other) noexcept
	{
		if (&other != this)
		{
			delete[] m_res;
			m_res = other.m_res;
			m_cnt = other.m_cnt;
			other.m_res = nullptr;
			other.m_cnt = 0;
		}

	}
	Restaurant& Restaurant::operator=(Restaurant& other)
	{
		if (&other != this)
		{
			delete[] m_res;
			m_res = nullptr;
			m_cnt = other.size();
			m_res = new Reservation[m_cnt];
			for (size_t i = 0; i < m_cnt; i++)
			{
				m_res[i] = other.m_res[i];
			}	
		}
		return *this;
	}
	Restaurant& Restaurant::operator=(Restaurant&& other)noexcept
	{
		if (&other != this)
		{
			delete[] m_res;
			m_res = other.m_res;
			m_cnt = other.m_cnt;
			other.m_res = nullptr;
			other.m_cnt = 0;
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, Restaurant& obj)
	{
		static size_t CALL_CNT = 0;
		CALL_CNT++;
		ostr << "--------------------------\nFancy Restaurant (" << CALL_CNT << ")\n--------------------------\n";
		if (obj.size() == 0)
		{
			ostr << "This restaurant is empty!\n";
		}
		else
		{
			for (size_t i = 0; i < obj.size(); i++)
			{
				ostr << obj.m_res[i];
			}
		}
		ostr << "--------------------------\n";
		return ostr;
	}
	Restaurant::Restaurant()
	{
	}

	Restaurant::~Restaurant()
	{
		delete[] m_res;
		m_res = nullptr;
	}
}