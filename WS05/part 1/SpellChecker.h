#ifndef SPELL_CHECKER_H_
#define SPELL_CHECKER_H_
#include <string>
namespace sdds
{
	class SpellChecker
	{
	public:
		SpellChecker();
		~SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	private:
		std::string m_badWords[6];
		std::string m_goodWords[6];
		size_t m_counter[6] = { 0,0,0,0,0,0 };

	};
	void findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr);
}
#endif // !SPELL_CHECKER_H_
