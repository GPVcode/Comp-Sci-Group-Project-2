#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip> 

using namespace std;

class Clock {
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
        ostringstream oss;
        oss << get_hours() << ":" << (get_minutes() < 10 ? "0" : "") << get_minutes();
        return oss.str();
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
        // mktime(local_time);

        // Format the time as a string
        ostringstream oss;
        oss << put_time(local_time, "%H:%M");
        return oss.str();
    }
};

int main() {
    Clock localClock;
    cout << "Local Time: " << localClock.get_time() << endl;

    WorldClock wc(3); // Create a WorldClock with a 3-hour offset
    cout << "World time (3 hours ahead): " << wc.get_time() << endl;

    return 0;
}