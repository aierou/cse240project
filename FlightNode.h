#ifndef FLIGHTNODE_H_
#define FLIGHTNODE_H_

#include <string>

#include "Date_Time.h"
#include "HubNode.h"

class HubNode;

class FlightNode{

  public:
	Date_Time departure;
	std::string flightNumber;
	double price;
	std::string flightCompany;
	int duration;
	HubNode* source;
	HubNode* destination;
	FlightNode* next;
	FlightNode();
	~FlightNode();
};

#endif // FLIGHTNODE_H_