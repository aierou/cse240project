#ifndef HUBNODE_H_
#define HUBNODE_H_

#include <string>
#include "FlightNode.h"

class FlightNode;

class HubNode{

public:
	std::string name;
	std::string location;
	HubNode* next;
	HubNode();
	~HubNode();
};

#endif