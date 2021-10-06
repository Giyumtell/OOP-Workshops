#ifndef PAIR_SUMMABLE_H_
#define PAIR_SUMMABLE_H_
#include "Pair.h"
#include <iomanip>
#include <string>
namespace sdds
{
	template<typename V, typename K>
	class PairSummable : public Pair<V, K>
	{
	public:
		PairSummable(){ }
		PairSummable(const K& key, const V& value = ) : Pair<V, K>(value, key)
		{
			m_maxWidth = key.size();
		}
		bool isCompatibleWith(const PairSummable<V, K>& b) const
		{
			return (b.key() == this->key());
		}

		PairSummable& operator+=(const PairSummable& obj)
		{
			if (typeid(this->m_Vobj) == std::string)
			{
				this->concat(obj.value());
			}
			else
			{
				this->m_Vobj += obj.value();
			}
			return *this;
		}
		virtual void display(std::ostream& os) const
		{
			os << std::left << std::setw(m_maxWidth);
			Pair<V, K>::display(os);
			os << std::right;
		}
	private:
		V m_Vobj;
		size_t m_maxWidth = 0;
	};
}
#endif // !PAIR_SUMMABLE_H_