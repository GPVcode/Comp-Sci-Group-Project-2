#include "Appointment.h"
#include <iostream>

using namespace std;

class Monthly : public Appointment {
public:
    // constructor - month and year aren't necessary for monthly ongoing payment.
    Monthly(string description, int day, int hour, int minute) : Appointment(description, 0, 0, day, hour, minute) {}

    bool occurs_on(int month, int day, int year) override {
        return (this->day == day);  // Occurs on the same day every month
    }
};
