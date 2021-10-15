#ifndef RESTAURANT_H_
#define RESTAURANT_H_
#include "Reservation.h"
#include <iostream>
#include <iomanip>
namespace sdds
{
	class Restaurant
	{
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(Restaurant& other);
		Restaurant(Restaurant&& other) noexcept;
		Restaurant& operator=(Restaurant& other);
		Restaurant& operator=(Restaurant&& other)noexcept;
		~Restaurant();
		size_t size() const
		{
			return m_cnt;
		}
		friend std::ostream& operator<<(std::ostream& ostr, Restaurant& obj);
	private:
		Reservation* m_res = nullptr;
		size_t m_cnt = 0;
	};
}
#endif // !RESTAURANT_H_
