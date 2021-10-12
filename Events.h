#pragma once

#include <vector>
#include "Date.h"


class Event :Date {
private:
    Date Day;
    string location, name;

public:
    int get(char r);

    string Get(char r);

    Event();

    Event(int d, int m, int y, string n, string l)
    {
        Day.set(d, m, y);
        location = l;
        name = n;
    }

    Event(int d, int m, string n, string l)
    {
        Day.set(d, m);
        location = l;
        name = n;
    }

    void set(int d, int m, int y, string n, string l);

    void set(int d, int m, string n, string l)
    {
        Day.set(d, m);
        location = l;
        name = n;
    }

    int daysLeft();

    string Horoscope();
};

void generateDays(Date Days[35]);

void generateEvents();

void addEvent();

void showEvents();

string getHoro();

void Horo();

