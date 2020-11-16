#include<iostream>
#include <cstdlib>
#include<string>
#include<chrono>
#include "Additional.h"
using namespace std;

int Inp_year;
int Inp_mon;
int Inp_date;
string cur_date;
const int per100 = 5;

const int Mon=0;
const int Tue=1;
const int Wed=2;
const int Thu=3;
const int Fri=4;
const int Sat=5;
const int Sun=6;

void getEnvVariables()
{
    if(getenv("INP_DATE"))
    {
        string cur_date_temp(getenv("INP_DATE"));
        cur_date = cur_date_temp;
    }
}

int isLeap(int year)
{
    if(year%4==0)
        return 1;
    return 0;
}

int getDays(int isLeap, int month)
{
    int daysInMonth=0;
    const int day1 = 31;
    const int day2 = 30;
    const int day3 = 29;
    const int day4 = 28;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month==12)
        daysInMonth = day1;
    else if (month == 4 || month == 6 ||month == 9 ||month == 11)
        daysInMonth = day2;
    else if (month == 2 && isLeap==1)
        daysInMonth = day3;
    else if(month == 2 && isLeap==0)
        daysInMonth = day4;
    return daysInMonth;
}

int findFirstDayOfMonth(int yr, int mon)
{
    int temp_yr  = yr-1;
    int numOFYrsLeft = temp_yr%400;
    int numOfOddDays=0;
    if(numOFYrsLeft/100 > 0)
    {
        numOfOddDays = numOFYrsLeft/100 * per100;
        numOFYrsLeft = numOFYrsLeft%100;
    }
    int numOfLeapYears = numOFYrsLeft /4;
    int numOfRegYears = numOFYrsLeft - numOfLeapYears;
    numOfOddDays = numOfOddDays + numOfLeapYears*2 + numOfRegYears*1;
    
    int numOfDaysOfThisYear = 0;
    int isLeapyr = isLeap(yr);
    for(int i=1;i<mon;i++)
    {
        numOfDaysOfThisYear = numOfDaysOfThisYear + getDays(isLeapyr,i);
    }
    int totalOddDays = numOfOddDays + numOfDaysOfThisYear;
    int day = totalOddDays%7;
    return day;
}

string PrintMonth(int month)
{
    string mon;
    switch(month)
    {
        case 1:
            mon = "Jan " ;
            break;
        case 2:
            mon = "Feb " ;
            break;
        case 3:
            mon = "Mar " ;
            break;
        case 4:
            mon = "Apr " ;
            break;
        case 5:
            mon = "May " ;
            break;
        case 6:
            mon = "Jun " ;
            break;
        case 7:
            mon = "Jul " ;
            break;
        case 8:
            mon = "Aug " ;
            break;
        case 9:
            mon = "Sep " ;
            break;
        case 10:
            mon = "Oct " ;
            break;
        case 11:
            mon = "Nov " ;
            break;
        case 12:
            mon = "Dec " ;
            break;
        default:
            cout << "Undefined " ;
            break;
    }
    return mon;
}

string PrintDay(int day)
{
    string d;
    switch(day)
    {
        case 0:
            d= "Mon ";
            break;
        case 1:
            d=  "Tue ";
            break;
        case 2:
            d=  "Wed ";
            break;
        case 3:
            d=  "Thu ";
            break;
        case 4:
            cout << "Fri ";
            break;
        case 5:
            d=  "Sat ";
            break;
        case 6:
            d= "Sun ";
            break;
        default:
            cout << "Undefined ";
            break;
    }
    return d;
}

void printHeader(int mon, int year)
{
    cout << "**************************************" << endl;
    cout << PrintMonth(mon) << ", " << year << endl;
    cout << "**************************************" << endl;
    for(int i=0;i<7;i++)
    {
        cout << PrintDay(i) ;
    }
    cout << endl;
    
}

void printBody(int mon, int year,  int startDay)
{
    int totalDays = getDays(isLeap(year), mon);
    //cout << totalDays << endl;
    //cout << "starting day : " << PrintDay(startDay) << " " <<startDay<< endl;
    int numOfLines;
    if ((totalDays + startDay)%7 !=0)
    {
        numOfLines = (totalDays + startDay)/7 +1;
    }
    else
    {
        numOfLines = (totalDays + startDay)/7;
    }
    int count=0;
    int blankDays = startDay;
    int numDays = 1;
    for(int j=0;j<=(totalDays + startDay);j++)
    {
        if(count==7)
        {
            cout << endl;
            count =1;
        }
        else
            count++;
        
        if(blankDays > 0)
        {
            cout << "    ";
            blankDays--;
        }
        else if(numDays <= totalDays)
        {
            if(numDays/10>0)
                cout << " " <<numDays<< " ";
            else
                cout << "  " <<numDays<< " ";
            numDays++;
        }
    }
}

void printFooter()
{
    cout << endl<<"**************************************" << endl;
}

void printCalender(int mon, int year, int startDay)
{
    printHeader(mon, year);
    printBody(mon,year,startDay);
    printFooter();
}

int main()
{
    cout << "This is a Calender Application" << endl;
    getEnvVariables();
    if(cur_date.empty())
    {
        cur_date = "18690115";
    }
    if(!cur_date.empty())
    {
        /*Setup input values for processing Starts*/
        Year inp_year;
        int inp_date = stoi(cur_date);
        inp_year.setYear(inp_date/10000);
        
        inp_date = inp_date%10000;
        inp_year.setYearMonth(inp_date/100);
        
        inp_date = inp_date%100;
        inp_year.setCurDate(inp_date);
        /*Setup input values for processing Ends*/
        
        int day = findFirstDayOfMonth(inp_year.getYear(), inp_year.getYearMonth());
        printCalender(inp_year.getYearMonth(),inp_year.getYear(), day);
        
    }
    return 0;
}
