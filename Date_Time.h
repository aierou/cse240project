#ifndef DATE_TIME_H_
#define DATE_TIME_H_

#include <string>

class Date_Time{
	int minutes;
	int hours;
	int day;
	int month;
	int year;

   public:
	void addMinutes(int min);
	std::string toString();
	Date_Time();
	Date_Time(int minutes,int hours,int day,int month,int year);
	~Date_Time();
};
#endif // DATE_TIME_H_