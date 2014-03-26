#include "Date_Time.h"


Date_Time::Date_Time(int minutes,int hours,int day,int month,int year) : 
	minutes(minutes),
	hours(hours),
	day(day),
	month(month),
	year(year)
{
	
}

Date_Time::~Date_Time(){

}
void Date_Time::addMinutes(int min){
	minutes+=min;
}
std::string Date_Time::toString(){
	return "";
}