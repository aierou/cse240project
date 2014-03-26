#ifndef HUB_LIST_H_
#define HUB_LIST_H_

#include "HubNode.h"
#include "linked_list.h"
#include <string>

class hub_list{
	linked_list<HubNode>* list_;
  public:
	HubNode* findHubByName(std::string name);
	hub_list();
	~hub_list();
	linked_list<HubNode>* list(){return list_;}
};

#endif // HUB_LIST_H_