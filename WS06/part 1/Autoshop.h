#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include<vector>
#include"Vehicle.h"
#include<list>
namespace sdds
{
	class Autoshop
	{
	public:
		Autoshop();
		~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (size_t i = 0; i < m_vehicles.size(); i++)
			{
				if (test(m_vehicles[i]))
				{
					vehicles.push_back(m_vehicles[i]);
				}
			}
		}
	private:
		std::vector<Vehicle*> m_vehicles;
	};
}
#endif //SDDS_AUTOSHOP_H