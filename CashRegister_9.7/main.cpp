#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class CashRegister{
    
    public:
    void clear();
    void add_item(double price);
    double get_total() const;
    int get_count() const;
    void display_all() const;
    
    private:
    vector <double> itemPrice;
    
};

void CashRegister :: clear(){
    // Go through each item in the itemPrice variable and erases them
    while (itemPrice.size() > 0) {
        itemPrice.erase(itemPrice.begin());
    }
}

void CashRegister :: add_item(double price){
    // Expand the itemPrice variable with a new item and price
    itemPrice.push_back(price);
}

double CashRegister :: get_total() const{
    // Return the total price of all items
    double totalPrice = 0.00;
    // Total price in cents (integer format)
    int total_price_in_cents = 0;

    for(int itemCount = 0; itemCount < itemPrice.size(); itemCount ++){
        totalPrice += itemPrice[itemCount];
    }
    cout << "Total price in cents: ";

    // converts total price to cents and stores the number as an integer
    total_price_in_cents = totalPrice * 100;

    // Prevent unknown output when vectors are empty
    if(itemPrice.size() == 0){
        return 0;
    }
    else{
        return total_price_in_cents;
    }
}

int CashRegister :: get_count() const{
    // Return the total amount of items in the vector 
    cout << "Total Number of Items: ";
    // Prevent unknown output when vectors are empty 
    if(itemPrice.size() == 0){
        return 0;
    }
    else{
        return itemPrice.size();
    }
}

void CashRegister :: display_all() const{
    int itemNumber = 1;
    for(int itemCount = 0; itemCount < itemPrice.size(); itemCount++){
       cout << "Item #" << itemNumber << " " << itemPrice[itemCount] << endl; 
       itemNumber ++;
    }
}


int main()
{
    CashRegister register1;
    register1.add_item(9.95);
    register1.add_item(100);
    cout << register1.get_count() << endl;
    cout << register1.get_total() << endl;
    register1.display_all();
    register1.clear();
    cout << register1.get_count() << endl;
    cout << register1.get_total() << endl;
}