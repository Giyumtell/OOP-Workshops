#include"Car.h"
#include"Utilities.h"
#include <iomanip>
namespace sdds
{
    Car::Car()
    {
        m_condition = Conditions::New;
    }
    Car::Car(std::istream& istr)
    {
        std::string temp;
        std::getline(istr, temp, ',');
        temp = trim(temp);
        m_maker = temp;
        std::getline(istr, temp, ',');
        temp = trim(temp);
        if (temp.empty())
        {
            m_condition = Conditions::New;
        }
        else
        {
            switch (temp[0])
            {
            case 'n':
                m_condition = Conditions::New;
                break;
            case 'u':
                m_condition = Conditions::Used;
                break;
            case 'b':
                m_condition = Conditions::broken;
                break;
            default:
                getline(istr, temp, '\n');
                std::invalid_argument e("Invalid record!");
                throw e;
            }
        }
        temp = "";
        char c = ' ';
        while (c!=',' && c!='\n' && istr.get(c))
        {
            if (c != ',' && c != '\n')
            {
                temp += c;
            }
        }
        temp = trim(temp);
        try
        {
            m_top_speed = std::stod(temp);
        }
        catch (const std::exception& e)
        {
            getline(istr, temp, '\n');
            std::invalid_argument f("Invalid record!");
            throw f;
        }
        
    }
    Car::~Car()
    {
        
    }
    std::string Car::condition() const
    {
        std::string con;
        switch (m_condition)
        {
        case Conditions::New:
            con = "new";
            break;
        case Conditions::Used:
            con = "used";
            break;
        case Conditions::broken:
            con = "broken";
            break;
        default:
            break;
        }
        return con;
    }
    double Car::topSpeed() const
    {
        return m_top_speed;
    }
    void Car::display(std::ostream& out) const
    {
        using namespace std;
        out << "| " << setw(10) << m_maker<<" | "<<setw(6) << left<<this->condition()<<right <<" | "<< setw(6) << fixed << setprecision(2) << topSpeed()<<" |";
    }
}