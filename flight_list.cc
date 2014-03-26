#include "flight_list.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "util.h"
#include "hub_list.h"

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
			vector<string> data = util::split(line,',');
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
void flight_list::print(){
	FlightNode* current = list_->head();
	while(current->next!=NULL){
		cout << current->flightNumber << "\n";
		current=current->next;
	}
}