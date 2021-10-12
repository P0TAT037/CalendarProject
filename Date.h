#pragma once

#include <string>
#include <iostream>

using namespace std;

int getDate(char dtype);

string getDay();

string monthName();

string monthName(int i);

int monthDaysNum(int m);

int const DAY = getDate('d');
int const MONTH = getDate('m');
int const YEAR = getDate('y');
string const DAYNAME = getDay();

class Date {
private:
    int day;
    int year = 2021;

    struct month
    {
        string name = monthName(number);
        int number = MONTH;
        int days = monthDaysNum(MONTH);
    };

public:
    month month;
    char sign = ' ';

    Date(int d, int m, int y)
    {
        while ((d > monthDaysNum(MONTH)) || (d <= 0)) {
            cout << "please enter a valid day number..." << endl;
            cin >> d;
        }
        day = d;
        while ((m > 12) || (m <= 0)) {
            cout << "please enter a month number..." << endl;
            cin >> m;
        }
        month.number = m;
        month.name = monthName(m);
        year = y;
    }

    Date(int d, int m)
    {
        while ((d > monthDaysNum(MONTH)) || (d <= 0)) {
            cout << "please enter a valid day number..." << endl;
            cin >> d;
        }
        day = d;

        while ((m > 12) || (m <= 0)) {
            cout << "please enter a valid month number..." << endl;
            cin >> m;
        }
        month.number = m;
        month.name = monthName(m);
    }

    Date();

    void set(int d, int m)
    {
        while ((d > monthDaysNum(MONTH)) || (d <= 0))
        {
            cout << "please enter a valid day number..." << endl;
            cin >> d;
        }
        day = d;

        while ((m > 12) || (m <= 0))
        {
            cout << "please enter a valid month number..." << endl;
            cin >> m;
        }
        month.number = m;
        month.name = monthName(m);
    }

    void set(int d, int m, int y)
    {
        while ((d > monthDaysNum(MONTH)) || (d <= 0))
        {
            cout << "please enter a valid day number..." << endl;
            cin >> d;
        }
        day = d;
        while ((m > 12) || (m <= 0))
        {
            cout << "please enter a month number..." << endl;
            cin >> m;
        }
        month.number = m;
        month.name = monthName(m);
        year = y;
    }

    int get(char r);

    Date operator+(int d)
    {
        Date dd;
        int n = month.number;
        int tmp = day + d;

        if (tmp <= monthDaysNum(n))
        {
            dd.set(tmp, n);
            day += d;
            return dd;
        }
        else
        {
            while (tmp > monthDaysNum(n))
            {
                tmp -= monthDaysNum(n);
                n++;
            }
            dd.set(tmp, n);
            day = tmp;
            month.number = n;
            return dd;
        }

    }

    Date operator=(Date const& obj)
    {
        Date d;
        d.day = obj.day;
        d.month.number = obj.month.number;
        d.year = obj.year;
        return d;
    }
};



void DateAfter(int n);

int sat(int d);

void display();

