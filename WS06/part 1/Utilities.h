#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include<string>
#include "Vehicle.h"
#include<exception>
namespace sdds
{
	std::string ltrim(const std::string& s);
	std::string rtrim(const std::string& s);
	std::string trim(const std::string& s);
	Vehicle* createInstance(std::istream& in);
}
#endif //SDDS_UTILITIES_H