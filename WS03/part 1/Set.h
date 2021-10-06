#ifndef SET_H_
#define SET_H_
namespace sdds
{
	template<size_t N , typename T >
	class Set
	{
	public:
		size_t size() const
		{
			return m_current;
		}
		const T& get(size_t idx) const
		{
			return arr[idx];
		}
		void operator+=(const T& item)
		{
			if (m_current < N)
			{
				arr[m_current] = item;
				m_current++;
			}
		}
	private:
		T arr[N];
		size_t m_current = 0;
	};
}
#endif // !SET_H_