#ifndef RESERVATION_H_
#define RESERVATION_H_
#include<string>
#include<iostream>
#include<iomanip>
namespace sdds
{
	std::string ltrim(const std::string& s);
	std::string rtrim(const std::string& s);
	std::string trim(const std::string& s);
	class Reservation
	{
	public:
		Reservation()
		{
		}
		void update(int day, int time);
		Reservation(const std::string& res);
		Reservation& operator = (const Reservation& other);
		friend std::ostream& operator<<(std::ostream& ostr, const Reservation& obj);
	private:
		std::string m_reservationID;
		std::string m_resName;
		std::string m_email;
		size_t m_numOfppl = 0;
		size_t m_day = 0;
		size_t m_hour = 0;

	};
}
#endif // !RESERVATION_H_
