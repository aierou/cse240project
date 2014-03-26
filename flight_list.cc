#include "flight_list.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

namespace{
const string kFlightFile="Flight.csv";
}
flight_list::flight_list() : 
	list_(new linked_list<FlightNode>(new FlightNode()))
{

	FlightNode* current=list_->head();

	string line;
	ifstream flights (kFlightFile);
	if (flights.is_open()){
		int i=0;
		while (getline(flights,line)){
			if(i++!=0){
				current=list_->push(new FlightNode());
			}
			vector<string> data = split(line,',');
			current->flightNumber=data.at(0);
			current->price=atof(data.at(1).c_str());
			//current->source=findHubByName(&data.at(2));
			//current->destination=findHubByName(&data.at(3));
			current->departure=Date_Time(0,0,0,0,0);
			current->duration=stoi(data.at(5));
			current->flightCompany=data.at(6);
		}

		flights.close();
	}else{
		cout << "Unable to open file";
	}
}
flight_list::~flight_list(){
	delete list_;
}
//TODO: this should be in its own class
vector<string> flight_list::split(string search, char splitter){
	vector<string> ret;
	unsigned int left=0;
	for(unsigned int i=0;i<search.length();i++){
		if(search.at(i)==splitter){
			ret.push_back(search.substr(left,i-left));
			left=++i;
		}
	}
	ret.push_back(search.substr(left,search.length()));
	return ret;
}
void flight_list::print(){
	FlightNode* current = list_->head();
	while(current->next!=NULL){
		cout << current->flightNumber << "\n";
		current=current->next;
	}
}