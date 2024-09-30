#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Appointment{
public:
    Appointment(string description, int year, int month, int day, int hour, int minute) : description(description), year(year), month(month), day(day), hour(hour), minute(minute){}
    
    virtual bool occurs_on(int month, int day, int year) = 0;
    
    void display() const {
        cout << description << " at " << hour << ":" << (minute < 10 ? "0" : "") << minute << endl; // add 0 if minute under 10, otherwise blank for numbers in tenth place.
    }
protected:
    string description;
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

#endif

// an appointment has description, date, and time.