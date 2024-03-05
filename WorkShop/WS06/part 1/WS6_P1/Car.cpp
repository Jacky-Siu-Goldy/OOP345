
#include <iomanip>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
namespace sdds {
	Car::Car(std::istream& input)
	{
		std::string t_maker, t_condition, t_topSpeed, temp;
		input.clear();
		int old_position = input.tellg();
		getline(input, temp);
		input.seekg(old_position, std::ios::beg);

		getline(input, m_maker, ',');
		t_maker = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);

		getline(input, m_condition, ',');
		t_condition = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);

		if (temp.find(',') != std::string::npos)
			getline(input, t_topSpeed, ',');
		else
			getline(input, t_topSpeed);
		

		trim(m_maker);
		trim(t_maker);
		
		trim(t_condition);

		if (t_condition == "n" || t_condition == "")
		{
			m_condition = "new";
		}
		else if (t_condition == "u")
		{
			m_condition = "used";
		}
		else if (t_condition == "b")
		{
			m_condition = "broken";
		}
		else
		{
			throw "Invalid Record!";
		}

		try
		{
			m_topSpeed = std::stod(t_topSpeed);
		}
		catch (...)
		{
			throw "Invalid Record!";
		}

	}

	std::string Car::condition() const {
		return m_condition;
	}

	double Car::topSpeed() const {
		return m_topSpeed;
	}

	void Car::display(std::ostream& out)const {
		out << "| " << std::setw(10) << std::right << m_maker << " | "<< std::setw(6) << std::left << m_condition;
		out << " | " << std::setw(6) << std::setprecision(2) << std::fixed << topSpeed() << " |";
	}

}