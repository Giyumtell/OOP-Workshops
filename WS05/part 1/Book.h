#ifndef BOOK_H_
#define BOOK_H_
#include <string>
namespace sdds
{

	class Book
	{
	public:
		Book();
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		friend std::ostream& operator<< (std::ostream& ostr, Book& obj);
		Book& operator=(const Book& other);
		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_description);
		}
		~Book();

	private:
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_yearOfPublic = 0;
		double m_price = 0;
		std::string m_description;
	};
	std::string ltrim(const std::string& s);
	std::string rtrim(const std::string& s);
	std::string trim(const std::string& s);
}
#endif // !BOOK_H_
