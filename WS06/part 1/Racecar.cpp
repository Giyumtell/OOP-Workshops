#include "Racecar.h"
#include "Utilities.h"
namespace sdds
{
	Racecar::Racecar()
	{
	}
	Racecar::Racecar(std::istream& in) : Car::Car(in)
	{
		std::string temp;
		std::getline(in, temp, '\n');
		temp = trim(temp);
		m_booster = std::stod(temp);
	}
	Racecar::~Racecar()
	{
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << '*';
	}
	double Racecar::topSpeed() const
	{
		double TS = Car::topSpeed();
		return TS + (TS * m_booster);
	}
}