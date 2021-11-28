// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> res;
		Product* temp = nullptr;
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					temp = new Product(desc[i].desc, price[j].price);
					temp->validate();
					res += temp;
					temp->~Product();
				}
			}
		}
		return res;
	}
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		List<Product> res;
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					std::shared_ptr<Product> temp(new Product(desc[i].desc, price[j].price));
					temp->validate();
					res += temp;
				}
			}
		}
		return res;
	}
}