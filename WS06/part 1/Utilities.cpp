#include"Utilities.h"
#include "Car.h"
#include "Racecar.h"
namespace sdds
{
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
	Vehicle* createInstance(std::istream& in)
	{
		if (!in.eof())
		{
			char c = ' ';
			std::string temp;
			while (c == ' ')
			{
				c = in.get();
			}
			std::getline(in, temp, ',');
			if (c != 'c' && c != 'C' && c != 'r' && c != 'R')
			{
				std::string a = "Unrecognized record type: [";
				a += c;
				a += "]";
				std::invalid_argument e(a.c_str());
				std::getline(in, temp, '\n');
				throw e;
			}
			return (c == 'c' || c == 'C') ? new Car(in) : (c == 'r' || c == 'R') ? new Racecar(in) : nullptr;
		}
		else
		{
			return nullptr;
		}
	}
}