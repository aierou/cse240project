#ifndef FLIGHT_LIST_H_
#define FLIGHT_LIST_H_

#include "FlightNode.h"
#include "linked_list.h"
#include <vector>
#include <string>

class flight_list{
	linked_list<FlightNode>* list_;
  public:
	flight_list();
	~flight_list();
	void print();
	linked_list<FlightNode>* list(){return list_;}
	std::vector<std::string> split(std::string search, char splitter);
};

#endif // FLIGHT_LIST_H_