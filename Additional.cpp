#include "Additional.h"

Month::Month()
{
    day1=30;
    day2=31;
    day3=29;
    day4=28;
}

void Month::setMonth(int mon)
{
    month = mon;
}

int Month::getMonth()
{
    return month;
}
/*
* Jan = 0
* Feb = 1
* Mar = 2
* Apr = 3
* May = 4
* Jun = 5
* Jul = 6 
* Aug = 7 
* Sep = 8
* Oct = 9
* Nov = 10
* Dec = 11
*/
int Month::getDays(int isLeap)
{
    daysInMonth=0;
    if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month==11)
        daysInMonth = day1;
    else if (month == 3 || month == 5 ||month == 8 ||month == 10)
        daysInMonth = day2;
    else if (month == 1 && isLeap==1)
        daysInMonth = day3;
    else if(month == 1 && isLeap==0)
        daysInMonth = day4;
    return daysInMonth;
}

Month Month::operator= (const Month &i_mon)
{
    Month t_mon;
    t_mon.month = i_mon.month;
    t_mon.daysInMonth  = i_mon.daysInMonth;
    return t_mon;
}

void Month::setCurDate(int date)
{
    curDate = date;
}
int Month::getCurDate()
{
    return curDate;
}

Year::Year()
{
    Month mon;
}

int Year::isLeapYear()
{
    if (year%4 == 0)
        return 1;
    return 0;
}

void Year::setYear(int year)
{
    this->year = year;
}

int Year::getYear()
{
    return year;
}

int Year::getYearMonth()
{
    return mon.getMonth();
}

void Year::setCurDate(int i_date)
{
    mon.setCurDate(i_date);
}

int Year::getCurDate()
{
    return mon.getCurDate();
}

void Year::setYearMonth(int i_mon)
{
    mon.setMonth(i_mon);
}
