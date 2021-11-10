#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"
#include <string>
#include<exception>
namespace sdds
{
	class Racecar:public Car
	{
	public:
		Racecar();
		Racecar(std::istream& in);
		~Racecar();
		void display(std::ostream& out) const;
		double topSpeed() const;

	private:
		double m_booster = 0;
	};
}
#endif //SDDS_RACECAR_H