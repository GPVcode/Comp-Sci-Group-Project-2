#include "Appointment.h"

using namespace std;

class Weekly : public Appointment{
public:
    // constructor - input date represents start of weekly appointments that came from main
    Weekly(string description, int year, int month, int day, int hour, int minute) : Appointment(description, year, month, day, hour, minute){}
    bool occurs_on(int input_month, int input_day, int input_year) override {
    // First, check if the input date is the same as the starting date
    int current_year = year;
    int current_month = month;
    int current_day = day;


    // Continue adding 7 days until we match or surpass the input date
    while (current_year < input_year || 
           (current_year == input_year && current_month < input_month) ||
           (current_year == input_year && current_month == input_month && current_day < input_day)) {
        
        // Get the number of days in the current month
        int days_in_month = get_days_in_month(current_month, current_year);
        current_day += 7; // Add 7 days

        // If the day exceeds the number of days in the current month, adjust the month
        if (current_day > days_in_month) {
            current_day -= days_in_month; // Carry over the extra days to the next month
            current_month++;  // Move to the next month

            // If month exceeds 12, move to the next year
            if (current_month > 12) {
                current_month = 1; // Reset month to January
                current_year++;     // Increment the year
            }
        }
    }

    // return true;
    // Check if the current date matches the input date
    return (current_year == input_year && current_month == input_month && current_day == input_day);
}

       
private:
    // helper function to figure out number of days in month
    int get_days_in_month(int month, int year){
        int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        if (month == 2 && is_leap_year(year)) {
            return 29;
        }

        return days_in_month[month];
    }

    // Check if a year is a leap year
    bool is_leap_year(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    
};

