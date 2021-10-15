#include "ConfirmationSender.h"
namespace sdds
{
	ConfirmationSender::ConfirmationSender(ConfirmationSender& other)
	{
		if (this != &other)
		{
			max = other.max;
			m_res = new const Reservation * [max];
			for (size_t i = 0; i < max; i++)
			{
				m_res[i] = other.m_res[i];
			}
		}
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& other)noexcept
	{
		if (this != &other)
		{
			m_res = other.m_res;
			max = other.max;
			other.m_res = nullptr;
			other.max = 0;

		}
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender& other)
	{
		if (this != &other)
		{
			max = other.max;
			m_res = new const Reservation * [max];
			for (size_t i = 0; i < max; i++)
			{
				m_res[i] = other.m_res[i];
			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept
	{

		if (this != &other)
		{
			m_res = other.m_res;
			max = other.max;
			other.m_res = nullptr;
			other.max = 0;
			
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool s = true;
		if (max >= 0)
		{
			for (size_t i = 0; i < max && s; i++)
			{
				if (m_res[i] == &res)
				{
					s = false;
				}
			}
		}
		if (s)
		{
			const Reservation** temp = nullptr;
			temp = new const Reservation * [max+1];
			if (max!=0)
			{
				for (size_t i = 0; i < max; i++)
				{
					temp[i] = m_res[i];
					m_res[i] = nullptr;
				}
			}
			max++;
			temp[max-1] = &res;
			delete[] m_res;
			m_res = temp;
			temp = nullptr;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		int j = -1;
		if (max >= 0)
		{
			for (size_t i = 0; i < max; i++)
			{
				if (m_res[i] == &res)
				{
					j = i;
				}
			}
		}
		if (j != -1)
		{
			const Reservation** m_temp = nullptr;
			m_temp = new const Reservation * [max - 1];
			size_t z = 0;
			for (size_t i = 0; z < max; z++)
			{
				if (z != (size_t)j)
				{
					m_temp[i] = m_res[z];
					i++;
				}
			}
			m_res[j] = nullptr;
			delete[]m_res;
			m_res = m_temp;
			max = max - 1;
			m_temp = nullptr;

		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, ConfirmationSender& other)
	{
		ostr << "--------------------------\nConfirmations to Send\n--------------------------\n";
		if (other.max == 0)
		{
			ostr << "There are no confirmations to send!\n";
		}
		else
		{
			for (size_t i = 0; i < other.max; i++)
			{
				ostr << *other.m_res[i];
			}
		}
		ostr << "--------------------------\n";
		return ostr;
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_res;
	}
}