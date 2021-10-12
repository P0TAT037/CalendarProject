#pragma once

#include "Date.h"

class Holiday :Date {
private:
    Date Day;
    string name;

public:
    int get(char r);
    string Get();
    Holiday();

    Holiday(int d, int m, int y, string n)
    {
        Day.set(d, m, y);
        name = n;
    }

    Holiday(int d, int m, string n)
    {
        Day.set(d, m);
        name = n;
    }
    int daysLeft();
};

void showHolidays();