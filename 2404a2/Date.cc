/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;
#include "Date.h"

Date::Date(int d, int m, int y)
{ 


  day= (d >= 0) ? d : 0;
  month = (m >= 0) ? m : 0;
  year = (y >= 0) ? y : 0;

}
Date&   Date::operator+=(int numDays){
	this->day += numDays;

	while(day>MAX_DAY ){
		this->month++;
		this->day -=MAX_DAY ;
	}
	while(month>MAX_MONTH ){
		this->year ++ ;
		this->month-=MAX_MONTH;
	}
	return *this;
}
Date   Date::operator+(int numDays){
	 Date day1 = Date(day, month, year);
	 	day1 += numDays;
	 	return day1;




}
bool   Date::operator>(Date& other){
	if(this->year> other.year){
		return true;
	}
	if(this->year ==other.year && this->month> other.month){
		return true;
	}
	if (this->year ==other.year && this->month == other.month && this->day>other.day)
	{
		return true;
	}
	return false;

}

void Date::toString(string& outStr){

	
	stringstream ss;
	ss<< day << "/" << month << "/" << year;

	outStr = ss.str();

	}