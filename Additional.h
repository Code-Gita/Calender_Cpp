#ifndef _ADD_H
#define _ADD_H
#include<string>
#include<iostream>
using namespace std;

class Month
{
private:
    int month;
    int curDate;
    int daysInMonth;
    int day1;
    int day2;
    int day3;
    int day4;

public:
    Month();
    Month(const Month &m)
    {
        Month m2;
        m2.month = m.month;
        m2.curDate = m.curDate;
        *this = m2;
    }
    Month(const Month &&m)
    {
        month = m.month;
        curDate = m.curDate;
    }
    void setMonth(int mon);
    int getMonth();
    void setCurDate(int date);
    int getCurDate();
    int getDays(int isLeap);
    Month operator= (const Month &i_mon);
};

class Year
{
private:
    int year;
    Month mon;
public:
    Year();
    int isLeapYear();
    void setYear(int i_year);
    int getYear();
    void setYearMonth(int i_mon);
    int getYearMonth();
    void setCurDate(int i_date);
    int getCurDate();
};
#endif
