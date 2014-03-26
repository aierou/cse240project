#ifndef FLIGHT_LIST_H_
#define FLIGHT_LIST_H_

#include "FlightNode.h"
#include "linked_list.h"

class flight_list{
	linked_list<FlightNode>* list_;
  public:
	flight_list();
	~flight_list();
	void print();
	linked_list<FlightNode>* list(){return list_;}
};

#endif // FLIGHT_LIST_H_