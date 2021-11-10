#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
#include<exception>
namespace sdds
{
	enum class Conditions
	{
		New, Used, broken
	};
	class Car:public Vehicle
	{
	public:
		Car();
		Car(std::istream& istr);
		~Car();
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	private:
		std::string m_maker;
		double m_top_speed = 0;
		Conditions m_condition;
	};
}
#endif //SDDS_CAR_H