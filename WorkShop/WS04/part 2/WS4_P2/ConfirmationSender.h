#ifndef SDDS_CONFIRMATIONSENDER_H__
#define SDDS_CONFIRMATIONSENDER_H__
#include "Restaurant.h"
namespace sdds {
	class ConfirmationSender {
		const sdds::Reservation** reservation_Array;
		size_t reservation_Arr_Size;
	public:
		ConfirmationSender();
		void setEmpty();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& consend);
		~ConfirmationSender();
	};
}
#endif