#include "Appointment.h"
#include <iostream>

class Onetime : public Appointment
{
public:
    // constructor
    Onetime(string description, int year, int month, int day, int hour, int minute) : Appointment(description, year, month, day, hour, minute){}

    bool occurs_on(int month, int day, int year) override{
        // compare input data with existing data in this object.
        return (this-> month == month && this->day == day && this->year == year);
    }
private:

};

