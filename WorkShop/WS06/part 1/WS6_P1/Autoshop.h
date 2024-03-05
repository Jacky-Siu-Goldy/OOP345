#ifndef _SDDS_AUTOSHOP_H
#define _SDDS_AUTOSHOP_H

#include <vector>
#include "Vehicle.h"
#include "Car.h"
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
	};
}
#endif
