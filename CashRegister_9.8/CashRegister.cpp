#include "CashRegister.h"
#include <iostream> 
#include <iomanip>
#include <vector> 

using namespace std;

void CashRegister::clear(){
    //Go through each item in the itemPrice vector and erase them
    while (itemPrice.size() > 0) {
        itemPrice.erase(itemPrice.begin());
    }
    //Go through each item in the tax_itemPrice vector and erase them
    while (tax_itemPrice.size() > 0){
        tax_itemPrice.erase(tax_itemPrice.begin());
    }
    //Go through each item in the centPrice vector and erase them
    while (centPrice.size() > 0){
        centPrice.erase(centPrice.begin());
    }
    //Go through each item in the tax_centPrice vector and erase them
    while (tax_centPrice.size() > 0){
        tax_centPrice.erase(tax_centPrice.begin());
    }
}

void CashRegister::add_item(double price){
    //Expand the itemPrice and centPrice vectors with a new item and price
    itemPrice.push_back(price);
    centPrice.push_back(price * 100);
}

double CashRegister::get_total() const{
    /*Output the total price of:
    Non-Taxed items and their cent value 
    Taxed items and their cent value
    The combined price of Taxed and Non-Taxed items 
    */
    double noTax = 0.0;
    double taxPrice = 0.0;
    int centTotal = 0;
    int tax_centTotal = 0;
    
    //Add up the cost for each item that isn't taxed and cent value
    for (int itemCount = 0; itemCount < itemPrice.size(); itemCount++) {
        noTax += itemPrice[itemCount];
        centTotal = centTotal + (itemPrice[itemCount] * 100);
    }
    //Add up the cost for each taxed item and cent value
    for(int tax_itemCount = 0; tax_itemCount < tax_itemPrice.size(); tax_itemCount ++){
        taxPrice += tax_itemPrice[tax_itemCount];
        tax_centTotal = tax_centTotal + (tax_itemPrice[tax_itemCount] * 100);
    }
    //Output
    double totalCost = noTax + taxPrice; 
    cout << endl <<  "Total Standard Price: $" << noTax << endl;
    cout << "Total Taxed Price: $" << fixed << setprecision(2) << taxPrice << endl;
    cout << "Total Standard Cents: " << centTotal << " cents" << endl;
    cout << "Total Taxed Cents: " << tax_centTotal << " cents" << endl;
    cout << "Total Cost: $";

    return totalCost;
}

int CashRegister :: get_count() const{
    //Return the total amount of items in the vector (Both taxed and non-taxed)
    cout << endl << "Total Number of Items: ";
    int total_size = itemPrice.size() + tax_itemPrice.size();
    
    //Prevent unknown output when vectors are empty 
    if (total_size == 0) {
        return 0;
    } 
    else {
        return total_size;
    }
}

void CashRegister :: display_all() const{
    //Displays each individual item and it's cost 
    int itemNumber = 1;
    //Displays each non-taxed item and the cost
    cout << endl << "Items: " << endl;
    for(int itemCount = 0; itemCount < itemPrice.size(); itemCount++){
       cout << "Item #" << itemNumber << " $" << itemPrice[itemCount] << endl; 
       itemNumber ++;
    }
    //Displays each taxed item and the cost
    itemNumber = 1;
    cout << endl << "Taxed Items: " << endl;
    for(int itemCount = 0; itemCount < tax_itemPrice.size(); itemCount++){
       cout << "Item #" << itemNumber << " $" << tax_itemPrice[itemCount] << endl; 
       itemNumber ++;
    }
}

void CashRegister :: add_taxable_item(double price){
    //Add the taxable item to the variable tax_itemPrice and it's cent value to centPrice
    double taxedPrice = price + (price * tax);
    
    tax_itemPrice.push_back(taxedPrice);
    centPrice.push_back(taxedPrice * 100);
}

double CashRegister :: get_total_tax() const{
    double tax_totalPrice = 0.0;
    //Loop that find the amount of tax that was charged for each item and adds it to the tax_totalPrice variable
    for(int itemCount = 0; itemCount < tax_itemPrice.size(); itemCount ++){
        double price = tax_itemPrice[itemCount];
        tax_totalPrice += (price - (price / (1 + tax)));
    }
    if (tax_itemPrice.size() == 0) {
    cout << endl << "Total Amount Taxed: $0";
    return 0;
    }
    else{
    cout << endl << "Total Amount Taxed: $";
        return tax_totalPrice;
    }

}