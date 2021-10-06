#ifndef SET_SUMMABLE_H_
#define	SET_SUMMABLE_H_
#include "Set.h"
namespace sdds
{
	template<size_t N, typename T >
	class SetSummable : public Set<N, T>
	{
	public:
		T accumulate(const std::string& filter) const
		{
			T tObj(filter);
			for (size_t i = 0; i < N; i++)
			{
				if (tObj.isCompatibleWith(this.get(i)))
				{
					tObj += this.get(i);
				}
			}
			return tObj;
		}

	private:

	};

}
#endif // !SET_SUMMABLE_H_