#include "SpellChecker.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdexcept> 
#include "Book.h"
namespace sdds
{
	SpellChecker::SpellChecker()
	{
	}
	SpellChecker::~SpellChecker()
	{
	}
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			file.close();
			throw "Bad file name!";
		}
		else
		{
			std::string temp;
			int index = 0;
			while (std::getline(file, temp))
			{
				m_badWords[index] = temp.substr(0, temp.find(' '));
				m_goodWords[index] = trim(temp.substr(temp.find(' ')));
				index++;
			}
		}
		
	}
	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < 6; i++)
		{
			size_t pos = text.find(m_badWords[i]);
			while (pos != std::string::npos)
			{
				text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
				pos = text.find(m_badWords[i], pos + m_goodWords[i].size());
				m_counter[i]++;
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics\n";
		for (size_t i = 0; i < 6; i++)
		{
			out<< std::setw(15)<<std::right <<m_badWords[i]<<": "<<m_counter[i]<<" replacements"<< std::endl;
		}
	}
}