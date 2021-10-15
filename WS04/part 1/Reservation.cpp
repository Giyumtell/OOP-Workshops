#include"Reservation.h"
namespace sdds
{
	void Reservation::update(int day, int time)
	{
		m_day = day;
		m_hour = time;
	}
	Reservation::Reservation(const std::string& res)
	{
		std::string trimed = trim(res);
		size_t last = trimed.find(':');
		m_reservationID = trim(trimed.substr(0, last));
		size_t temp = last;
		last = trimed.find(',', last + 1);
		m_resName = trim(trimed.substr(temp + 1, last - temp - 1));
		temp = last;
		last = trimed.find(',', last + 1);
		m_email = trim(trimed.substr(temp + 1, last - temp - 1));
		temp = last;
		last = trimed.find(',', last + 1);
		m_numOfppl = std::stoi(trim(trimed.substr(temp + 1, last - temp - 1)));
		temp = last;
		last = trimed.find(',', last + 1);
		m_day = std::stoi(trim(trimed.substr(temp + 1, last - temp - 1)));
		temp = last;
		last = trimed.find(',', last + 1);
		m_hour = std::stoi(trim(trimed.substr(temp + 1, last - temp - 1)));
	}
	Reservation& Reservation::operator = (const Reservation& other)
	{
		m_reservationID = other.m_reservationID;
		m_resName = other.m_resName;
		m_email = other.m_email;
		m_numOfppl = other.m_numOfppl;
		m_day = other.m_day;
		m_hour = other.m_hour;
		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, const Reservation& obj)
	{
		if (obj.m_hour >= 6 && obj.m_hour <= 9)
		{
			ostr << "Reservation " << std::setw(10) << std::right << obj.m_reservationID<<": " << std::setw(20) << std::right << obj.m_resName <<"  " << std::setw(20) << std::left << "<" + obj.m_email + ">" << "    Breakfast on day "<<obj.m_day << " @ " << obj.m_hour << ":00" << " for " << obj.m_numOfppl;
			if (obj.m_numOfppl == 1)
			{
				ostr << " person.\n";
			}
			else
			{
				ostr << " people.\n";
			}
		}
		else if (obj.m_hour >= 11 && obj.m_hour <= 15)
		{
			ostr << "Reservation " << std::setw(10) << std::right << obj.m_reservationID << ": " << std::setw(20) << std::right << obj.m_resName << "  " << std::setw(20) << std::left << "<" + obj.m_email + ">" << "    Lunch on day " << obj.m_day << " @ " << obj.m_hour<<":00" << " for " << obj.m_numOfppl;
			if (obj.m_numOfppl == 1)
			{
				ostr << " person.\n";
			}
			else
			{
				ostr << " people.\n";
			}
		}
		else if (obj.m_hour >= 17 && obj.m_hour <= 21)
		{
			ostr << "Reservation " << std::setw(10) << std::right << obj.m_reservationID << ": " << std::setw(20) << std::right << obj.m_resName << "  " << std::setw(20) << std::left << "<" + obj.m_email + ">" << "    Dinner on day " << obj.m_day << " @ " << obj.m_hour << ":00" << " for " << obj.m_numOfppl;
			if (obj.m_numOfppl == 1)
			{
				ostr << " person.\n";
			}
			else
			{
				ostr << " people.\n";
			}
		}
		else
		{
			ostr << "Reservation " << std::setw(10) << std::right << obj.m_reservationID << ": " << std::setw(20) << std::right << obj.m_resName << "  " << std::setw(20) << std::left << "<" + obj.m_email + ">" << "    Drinks on day " << obj.m_day << " @ " << obj.m_hour << ":00" << " for " << obj.m_numOfppl;
			if (obj.m_numOfppl == 1)
			{
				ostr << " person.\n";
			}
			else
			{
				ostr << " people.\n";
			}
		}
		return ostr;
	}
	const std::string WHITESPACE = " \n\r\t\f\v";
	std::string ltrim(const std::string& s)
	{
		size_t start = s.find_first_not_of(WHITESPACE);
		return (start == std::string::npos) ? "" : s.substr(start);
	}

	std::string rtrim(const std::string& s)
	{
		size_t end = s.find_last_not_of(WHITESPACE);
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}

	std::string trim(const std::string& s)
	{
		return rtrim(ltrim(s));
	}
}