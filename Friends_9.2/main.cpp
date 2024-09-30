#include <iostream>
#include <vector>
using namespace std;

class Person {
    public:
    // initializes name data
    Person(string name) : name(name) {}
    
    /*
        Person = Class Name 
        p = Objects in the Person Class
    */

    void befriend(Person* p);
    void unfriend(Person* p);
    string get_friend_names() const;
    int get_friend_count() const;
    
    private:
    // Vector to store pointers to friend objects 
    vector <Person*> friends;
    string name;
    
};

    // Requires Person class to add pointers in private friends vector.
void Person :: befriend(Person* p){
    friends.push_back(p); 

}

void Person :: unfriend(Person* p){
    // Loop through vector to delete matching memory addess.
    for (int friendCount = 0; friendCount < friends.size(); ++friendCount) {
        // cout << "I want to unfriend: " << friends[friendCount] << endl;
        if (friends[friendCount] == p) {
            friends.erase(friends.begin() + friendCount);
            // cout << "Unfriended: " << p << endl;
        }
    }
}

string Person :: get_friend_names() const {
    string friend_names;
    // only loops if vector is not empty
    for(const Person* friendPointer : friends){
        friend_names += friendPointer->name + ", ";
    }
    if(!friend_names.empty()){
        friend_names.pop_back();
        friend_names.pop_back();
    }
 
    return friend_names;
}

int Person :: get_friend_count() const{
    cout << "Current friend count: ";
   return friends.size();
}

int main()
{
    // Create person objects
    Person me("Me");
    Person mike("Mike");
    Person sam("Sam");

    // use the memory address of mike and sam to log idividual objects as friends in my vector space.
    me.befriend(&mike);
    me.befriend(&sam);
    cout << me.get_friend_names() << endl;
    cout << me.get_friend_count() << endl;
    me.unfriend(&mike);
    cout << me.get_friend_names() << endl;
    cout << me.get_friend_count() << endl;

    return 0;
}