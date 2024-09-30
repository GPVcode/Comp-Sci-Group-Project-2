#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip> 

using namespace std;

class Clock {
private: 
    int alarm_hour = -1;   
    int alarm_minute = -1;
public:
    int get_hours() {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        return local_time->tm_hour;
    }

    int get_minutes() {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        return local_time->tm_min;
    }

    string get_time() {
        int current_hour = get_hours();
        int current_minute = get_minutes();

        // Check if current time matches or exceeds the alarm
        if (alarm_hour != -1 && alarm_minute != -1) {
            if (current_hour > alarm_hour || (current_hour == alarm_hour && current_minute >= alarm_minute)) {
                cout << "Alarm! Time is " << current_hour << ":" ;
                // Fill in 0 if the minute is less than 10
                if (current_minute < 10) {
                    cout << "0";  
                    }
                cout << current_minute << endl;
            }
        }
        
        ostringstream oss;
        oss << get_hours() << ":" << (get_minutes() < 10 ? "0" : "") << get_minutes();
        return oss.str();
    }
    
    void set_alarm(int hour, int minute) {
        //Set an alarm with (hour,minute)
        alarm_hour = hour;
        alarm_minute = minute;
        cout << "Alarm set for " << alarm_hour << ":";
        // Fill in 0 if the minute is less than 10
        if(minute < 10){
            cout << "0";
        }
        cout << alarm_minute << endl;
    }
};

class WorldClock : public Clock {
private:
    int offset; // Time zone offset in hours

public:
    WorldClock(int offset) : offset(offset) {}

    string get_time() {
        // Get current time in the base timezone
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);

        // Calculate world time with offset
        local_time->tm_hour += offset;

        // Normalize the time structure 
        mktime(local_time);

        // Format the time as a string
        ostringstream oss;
        oss << put_time(local_time, "%H:%M");
        return oss.str();
    }
};

int main() {
    Clock localClock;
    localClock.set_alarm(10, 06);
    cout << "Local Time: " << localClock.get_time() << endl;

    WorldClock wc(3); // Create a WorldClock with a 3-hour offset
    wc.set_alarm(21, 14);
    cout << "World time (3 hours ahead): " << wc.get_time() << endl;
    return 0;
}