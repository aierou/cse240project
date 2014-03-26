#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Date_Time.h"
#include "FlightNode.h"
#include "flight_list.h"

using namespace std;

HubNode* hubHead;
flight_list flights;

//TODO: Organize everything in classes

vector<string> split(string search, char splitter){
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
HubNode* loadHubs(){
	HubNode* hubHead = new HubNode();
	HubNode* current=hubHead;

	string line;
	ifstream flights ("Hub.csv");
	if (flights.is_open()){
		int i=0;
		while (getline(flights,line)){
			if(i++!=0){
				current->next=new HubNode();
				current=current->next;
			}
			vector<string> data = split(line,',');
			current->name=data.at(0);
			current->location=data.at(1);
		}
		current->next=NULL;

		flights.close();
	}else{
		cout << "Unable to open file";
	}
	return hubHead;
}
HubNode* findHubByName(string* name){
	HubNode* current=hubHead;
	while(current!=NULL){
		if(name->compare(current->name)==0){
			return current;
		}
		current=current->next;
	}
	return NULL;
}
void printFlightsFromHub(HubNode* hub){
	FlightNode* current=flights.list()->head();
	while(current!=NULL){
		if(current->source==hub){
			cout << current->flightNumber << "\n";
		}
		current=current->next;
	}
}
void printFlights(){
	HubNode* current=hubHead;
	while(current!=NULL){
		cout << "flights from " << current->name << ":\n";
		printFlightsFromHub(current);
		current=current->next;
	}
}
void unloadHubs(HubNode* node){
	if(node==NULL)return;
	unloadHubs(node->next);
	delete node;
}
void unloadFlights(FlightNode* node){
	if(node==NULL)return;
	unloadFlights(node->next);
	delete node;
}
int main(){
	hubHead=loadHubs();

	flights.print(); //For testing purposes

	unloadHubs(hubHead);
	return 0;
}