#include "Autoshop.h"
namespace sdds
{
    Autoshop::Autoshop()
    {
    }
    Autoshop::~Autoshop()
    {
        for (size_t i = 0; i != m_vehicles.size(); i++)
        {
            delete m_vehicles[i];
        }
    }
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);
        return *this;
    }
    void Autoshop::display(std::ostream& out) const
    {
        out << "--------------------------------\n| Cars in the autoshop!        |\n--------------------------------\n";
        for (auto itr = m_vehicles.begin() ; itr != m_vehicles.end(); itr++)
        {
            (*itr)->display(out);
            out << std::endl;
        }
        out << "--------------------------------\n";
    }
}