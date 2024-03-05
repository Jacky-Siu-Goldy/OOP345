// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>
#include <iostream>
#include "Workstation.h"
namespace sdds {
	class LineManager {
		std::vector<Workstation*> activeLine;//-the collection of workstations for the current assembly line
		size_t m_cntCustomerOrder; //-the total number of CustomerOrder objects
		size_t filled;
		Workstation* m_firstStation; //-points to the first active station on the current line
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);//-this constructor receives the name of 
		//file that identifies the active stations on the assembly line (example: AssemblyLine.txt) and the collection of workstations
		//available;
		void setEmpty();
		//The file contains the linkage between workstation pairs. The format of each record in the file is WORKSTATION|NEXT_WORKSTATION .
		//The records themselves are not in any particular order.
		
		//This function stores the workstation in order received from the file in the activeLine instance variable. It loads the contents of the file, 
		//stores the address of the next workstation in each element of the collection, identifies the first station in the assembly line and stores
		//its address in the m_firstStation attribute. This function also updates the attribute that holds the total number of orders in the pending queue.
		//if something goes wrong the constructor reports an error.

		//Note: to receive full marks, use STL algorithms throughtout this function, except for iterating through the file records (one while loop);
		//marks will be deducted if you use any of for, while or do-while loops except for iterating through the file records
		
		void linkStations(); //-this modifier reorders the workstations present in the instance variable activeLine (loaded by the constructor)
		// and stores the reordered collection in the same instance variable. The elements in the reordered collection start with the first station
		//proceeds to the next, amd so forth until the end of the line.

		bool run(std::ostream& os);//this modifier performs one iteration of operation on all of the workstation in the current assembly line by
		//doing the following:

		//Keep tract of the current iteration number(use a local variable)
	    //insert into stream os the iteration number (how many times this function has been called by the client) 
		//in the format Line Manager Iteration: Count<endl>
		//If the pending queue has a CustomerOrder object, move the order at the front of the queue to the m_firstStation of the activeLine
		//and remove it from the queue. This function moves only one order to the line in a single iteration.
		//for each station on the line, execute one fill operation
		//for each station on the line, attempts to move a CustomerOrder down the line
		// return true if all Customer order (m_cntCustomerOrder) have been filled, otherwise return false.
	
		void display(std::ostream& os) const; //-this query displays all active stations on the assembly line in their current order
	};
}
#endif
