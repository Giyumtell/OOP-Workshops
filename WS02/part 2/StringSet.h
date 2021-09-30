#ifndef SDDS_STRINGSET_H_
#define SDDS_STRINGSET_H_
#include <string>
namespace sdds
{
	class StringSet
	{
	public:
		StringSet();
		StringSet(StringSet&);
		StringSet(StringSet&&)noexcept;
		~StringSet();
		StringSet(char*);
		size_t size();
		std::string operator[](size_t);
		StringSet& operator=(StringSet&);
		StringSet& operator=(StringSet&&)noexcept;
	private:
		std::string* elements = nullptr;
		size_t numOfStrings = 0;
	};

}
#endif // !SDDS_STRINGSET_H_