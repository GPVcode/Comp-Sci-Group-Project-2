#include "Appointment.h"
#include <iostream>
#include <vector>
#include "Onetime.cpp"
#include "Daily.cpp"
#include "Weekly.cpp"
#include "Monthly.cpp"
using namespace std;

int main(){
    vector <Appointment*> appointments;

    appointments.push_back(new Onetime("Haircut", 2024, 9, 30, 10, 30));
    appointments.push_back(new Daily("Daily Gym Training", 7, 0));
    appointments.push_back(new Weekly("Weekly Tutoring", 2024, 9, 30, 6, 0));
    appointments.push_back(new Monthly("Monthly Rent Due", 1, 12, 0));

    int inputMonth, inputDay, inputYear;
    cout << "Find appointments by date (MM DD YYYY): ";
    cin >> inputMonth >> inputDay >> inputYear;

    // Check all appointments for the given date
    cout << "Appointments on " << inputMonth << "-" << inputDay << "-" << inputYear << ": " << endl;
    
    for (int i = 0; i < appointments.size(); i++) {
        // Get appointment at index i
        Appointment* appt = appointments[i];
        // display the appointments on this day.
        if(appt -> occurs_on(inputMonth, inputDay, inputYear)){
            appt->display();
        }
    }

    // Get appointment at each index in our vector and free up memory
    for (int i = 0; i < appointments.size(); i++) { 
        Appointment* appt = appointments[i];
        delete appt;  
    }

    return 0;

    };