#ifndef MOVIE_H_
#define MOVIE_H_
#include <string>
#include <iostream>
namespace sdds
{
	class Movie
	{
	public:
		Movie();
		~Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_description);
			spellChecker(m_title);
		}
		Movie& operator=(const Movie& other);
		friend std::ostream& operator << (std::ostream& ostr, const Movie& obj);
	private:
		std::string m_title;
		size_t m_yearOfRelease = 0;
		std::string m_description;

	};
}
#endif // !MOVIE_H_

