#ifndef PAIR_H_
#define	PAIR_H_
#include <iostream>
namespace sdds
{
	template<typename V , typename K>
	class Pair
	{
	public:
		Pair()
		{
		}
		Pair(const K& key, const V& value)
		{
			m_key = key;
			m_value = value;
		}
		const V& value() const
		{
			return m_value;
		}
		const K& key() const
		{
			return m_key;
		}
		virtual void display(std::ostream& os) const
		{
			os << m_key << " : " << m_value << std::endl;
		}
		void concat(std::string value)
		{
			m_value = m_value + ", " + value;
		}
	private:
		V m_value;
		K m_key;
	};
	template<typename Vv, typename Kk>
	std::ostream& operator<<(std::ostream& os, const Pair<Vv, Kk>& pair)
	{
		pair.display(os);
		return os;
	}
}
#endif // !PAIR_H_
