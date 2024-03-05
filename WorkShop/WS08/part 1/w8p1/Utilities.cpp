// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		
			for (auto i = 0u; i < desc.size(); ++i) {
				
					for (auto a = 0u; a < price.size(); ++a) {
						if (desc[i].code == price[a].code) {
							auto* temp = new Product(desc[i].desc, price[a].price);
						
								temp->validate();
						
							priceList += temp;
							delete temp;
						}
					}
				
			}
		
		return priceList;
		
	}
}