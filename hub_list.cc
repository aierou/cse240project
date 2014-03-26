#include "hub_list.h"

#include <iostream>
#include <fstream>
#include <vector>

#include "util.h"

using namespace std;

namespace{
const string kHubFile="Hub.csv";
}
hub_list::hub_list() : 
	list_(new linked_list<HubNode>(new HubNode()))
{

	HubNode* current=list_->head();

	string line;
	ifstream hubs (kHubFile);
	if (hubs.is_open()){
		int i=0;
		while (getline(hubs,line)){
			if(i++!=0){
				current=list_->push(new HubNode());
			}
			vector<string> data = util::split(line,',');
			current->name=data.at(0);
			current->location=data.at(1);
		}

		hubs.close();
	}else{
		cout << "Unable to open file";
	}
}
hub_list::~hub_list(){
	delete list_;
}
HubNode* hub_list::findHubByName(string name){
	HubNode* current=list_->head();
	while(current!=NULL){
		if(name.compare(current->name)==0){
			return current;
		}
		current=current->next;
	}
	return NULL;
}