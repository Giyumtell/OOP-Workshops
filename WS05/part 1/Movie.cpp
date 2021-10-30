#include "Movie.h"
#include "Book.h"
#include <iomanip>
namespace sdds
{
	Movie::Movie()
	{
	}
	Movie::~Movie()
	{
	}
	const std::string& Movie::title() const
	{
		return m_title;
	}
	Movie::Movie(const std::string& strMovie)
	{
		std::string trimed = trim(strMovie);
		size_t last = trimed.find(',');
		m_title = trim(trimed.substr(0, last));
		size_t temp = last;
		last = trimed.find(',', last + 1);
		m_yearOfRelease = std::stoi(trim(trimed.substr(temp + 1, last - temp - 1)));
		temp = last;
		m_description = trim(trimed.substr(temp + 1));
	}
	Movie& Movie::operator=(const Movie& other)
	{
		m_title = other.m_title;
		m_yearOfRelease = other.m_yearOfRelease;
		m_description = other.m_description;
		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, const Movie& obj)
	{
		ostr << std::setw(40) << obj.m_title;
		ostr << " | ";
		ostr << std::setw(4) <<obj.m_yearOfRelease;
		ostr << " | ";
		ostr << obj.m_description << std::endl;
		return ostr;
	}
}