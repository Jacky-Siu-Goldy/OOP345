#ifndef _SDDS_CUSTOMERORDER_H
#define _SDDS_CUSTOMERORDER_H
#include "Station.h"
namespace sdds {
	struct Item {
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };
		Item(const std::string& src) : m_itemName(src) {};

		void setEmpty() {
			m_itemName = "";
			m_serialNumber = 0u;
			m_isFilled = false;
		}
		Item(Item& src) {
			setEmpty();
			*this = src;
		}
		Item& operator=(Item& src) {
			if (this != &src)
			{

				m_itemName = src.m_itemName;
				m_serialNumber = src.m_serialNumber;
				m_isFilled = src.m_isFilled;
				src.m_itemName = "";
				src.m_serialNumber = 0;
				src.m_isFilled = false;
			}
			return *this;
		}
	};

	class CustomerOrder {
		std::string m_name;// the name of the customer (e.g., John, Sara, etc)
		std::string m_product; //the name of the product being assembled(e.g., Desktop, Laptop, etc)
		size_t m_cntItem; //-a count of the number of items in the customer's order
		Item** m_1stItem; // a dynameically allocated array of pointers. Each element of the array points to a dynamically allocated object of type Item.
		//this is the resource that you must manage.

		static size_t m_widthField;//the maximum width of a field, used for display purposes

	public:

		CustomerOrder();
		void setEmpty();
		CustomerOrder(const std::string str);
		CustomerOrder(CustomerOrder& src) { throw "NO COPY CONSTRUCTOR ALLOWED!!"; };
		CustomerOrder& operator=(CustomerOrder& src) = delete;
		CustomerOrder(CustomerOrder&& src)noexcept;
		CustomerOrder& operator=(CustomerOrder&& src)noexcept;
		~CustomerOrder();
		bool isFilled() const;// returns true if all items in the order have been filled; false otherwise.
		bool isItemFilled(const std::string& ItemName)const;//return true if all items specified by items specified by itemName have been filled.
		//if the item doesn't exist in the order, this query returns true.

		void fillItem(Station& station, std::ostream& os);//this modifier fills all items in the current order that the Station specified in the
		//first parameter handles.
		//if the order doesn't contain the item handled, this function does nothing.
		//if the order contains items handled, and the Station's inventory contains at least one item, this function fills the order with one item. 
		//it substracts 1 from the inventory and updates Item::m_serialNumber and Item::m_isFilled. It also prints the message Filled Name, Product 
		//[ITEM_NAME].
		//If the order contains items handled but unfilled, and the inventory is empty, this function prints the message 
		//Unable to fill NAME, PRODUCT [ITEM_NAME].
		//all messages printed are terminated by an endline

		void display(std::ostream& os)const;//-this query displays the state of the current object in the format(see the sample output for details)


	};
}
#endif
