// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
/*
date: 2021-11-14
Name: Chun Kit Jacky Siu
ID: 134663186
email: jsiu5@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (auto i = 0ul; i < desc.size(); ++i) {

			for (auto a = 0ul; a < price.size(); ++a) {
				if (desc[i].code == price[a].code) {
					auto* temp = new Product(desc[i].desc, price[a].price);

					try {
						temp->validate();
					}
					catch (const std::string& msg) {
						Product::Trace = false;
						delete temp;
						Product::Trace = true;
						throw;
					}
					priceList += temp;
					delete temp;
				}
			}

		}


		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (auto i = 0ul; i < desc.size(); ++i) {
			for (auto a = 0ul; a < price.size(); ++a) {
				if (desc[i].code == price[a].code) {
					std::unique_ptr<Product> temp(new Product(desc[i].desc, price[a].price));
					temp->validate();
					priceList+= temp;

				}
			}
		}

		return priceList;
	}
}