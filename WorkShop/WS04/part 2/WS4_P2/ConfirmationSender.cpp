#include <utility>
#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender() {
		setEmpty();
	}

	void ConfirmationSender::setEmpty() {
		reservation_Array = nullptr;
		reservation_Arr_Size = 0u;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		if (reservation_Arr_Size == 0u) {
			delete[] reservation_Array;

			reservation_Array = new const Reservation *[1u];
			reservation_Array[0] = &res;
			++reservation_Arr_Size;

		}
		bool match = false;
		for (auto i = 0u; i < reservation_Arr_Size; ++i)
		{
			if (reservation_Array[i] == &res) {
				match = true;
				//break;
			}
		}

		if (!match) {
			const sdds::Reservation* temp[20];
			

			for (auto i = 0u; i < reservation_Arr_Size; ++i) {
				temp[i] = reservation_Array[i];
			}
			
			delete[] reservation_Array;
			
			reservation_Array = new const Reservation * [reservation_Arr_Size + 1];
			
			for (auto i = 0u; i < reservation_Arr_Size; ++i) {
				reservation_Array[i] = temp[i];
			}
			
			reservation_Array[reservation_Arr_Size] = &res;
			
			++reservation_Arr_Size;
			
			
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool match = false;
		auto i = 0u;
		for (; i < reservation_Arr_Size; ++i)
		{
			if (reservation_Array[i] == &res) {
				match = true;
				break;
			}
		}

		if (match) {
			const sdds::Reservation* temp[20];
			--reservation_Arr_Size;
			for (auto u = 0u; u < i; ++u) {
				temp[u] = reservation_Array[u];
			}

			for (auto u = i; u < reservation_Arr_Size; ++u) {
				temp[u] = reservation_Array[u + 1];
			}
			delete[] reservation_Array;
			reservation_Array = new const Reservation * [reservation_Arr_Size];
			for (auto u = 0u; u < reservation_Arr_Size; ++u) {
				 reservation_Array[u]= temp[u];
			}
			
			

		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		setEmpty();
		*this = src;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
		if(this != &src){
			reservation_Arr_Size = src.reservation_Arr_Size;

			delete[] reservation_Array;

			reservation_Array = new const Reservation * [reservation_Arr_Size];

			for (auto i = 0u; i < reservation_Arr_Size; ++i) {
				reservation_Array[i] = src.reservation_Array[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) {
		setEmpty();
		*this = std::move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) {
		if (this != &src) {

			
			reservation_Arr_Size = src.reservation_Arr_Size;
			
			delete[] reservation_Array;
			
			reservation_Array = src.reservation_Array;

			src.reservation_Array = nullptr;

			src.reservation_Arr_Size = 0u;
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& consend) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;

		if (consend.reservation_Array != nullptr && consend.reservation_Arr_Size > 0u) {
			for (auto u = 0u; u < consend.reservation_Arr_Size; ++u) {
				if(consend.reservation_Array[u] != nullptr)
				os << *consend.reservation_Array[u];
			}
		}
		else {
			os << "There are no confirmations to send!" << std::endl;

		}
		os << "--------------------------" << std::endl;
		return os;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] reservation_Array;
		reservation_Array = nullptr;
	}
}