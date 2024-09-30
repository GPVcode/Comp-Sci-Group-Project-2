#include "Appointment.h"
#include <iostream>

using namespace std;

class Daily : public Appointment{
public:
    // constructor - only description, hour and minute needs to be updated for daily appointments.
    Daily(string description, int hour, int minute) : Appointment(description, 0, 0, 0, hour, minute){}

    // Daily occuring appointments will always render true 
    bool occurs_on(int month, int day, int year) override{
        return true;
    }
private:
};
