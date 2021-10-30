#include "Book.h"
#include <iostream>
#include <iomanip>
namespace sdds
{
	Book::Book()
	{
	}
	Book::Book(const std::string& strBook)
	{
		std::string trimed = trim(strBook);
		size_t last = trimed.find(',');
		m_author = trim(trimed.substr(0, last));
		size_t temp = last;
		last = trimed.find(',', last + 1);
		m_title = trim(trimed.substr(temp + 1, last - temp - 1));
		temp = last;
		last = trimed.find(',', last + 1);
		m_country = trim(trimed.substr(temp + 1, last - temp - 1));
		temp = last;
		last = trimed.find(',', last + 1);
		m_price = std::stod(trim(trimed.substr(temp + 1, last - temp - 1)));
		temp = last;
		last = trimed.find(',', last + 1);
		m_yearOfPublic = std::stoi(trim(trimed.substr(temp + 1, last - temp - 1)));
		temp = last;
		m_description = trim(trimed.substr(temp + 1));
	}
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_country;
	}
	const size_t& Book::year() const
	{
		return m_yearOfPublic;
	}
	double& Book::price()
	{
		return m_price;
	}
	Book& Book::operator=(const Book& other)
	{
		m_author = other.m_author;
		m_country = other.m_country;
		m_description = other.m_description;
		m_price = other.m_price;
		m_title = other.m_title;
		m_yearOfPublic = other.m_yearOfPublic;
		return *this;
	}
	Book::~Book()
	{
	}
	std::ostream& operator<<(std::ostream& ostr, Book& obj)
	{
		ostr << std::setw(20)<< obj.m_author;
		ostr << " | ";
		ostr << std::setw(22) << obj.m_title;
		ostr << " | ";
		ostr << std::setw(5) << obj.m_country;
		ostr << " | ";
		ostr << std::setw(4) << obj.m_yearOfPublic;
		ostr << " | ";
		ostr << std::setw(6) << std::fixed <<std::setprecision(2)<< obj.m_price;
		ostr << " | ";
		ostr << obj.m_description << std::endl;
		return ostr;
	}
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
}