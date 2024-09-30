#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include <vector>

using namespace std;

class CashRegister{
    public:
    CashRegister(double taxRate = 0.0) : tax(taxRate) {}
    void clear();
    void add_item(double price);
    double get_total() const;
    int get_count() const;
    void display_all() const;
    void add_taxable_item(double price);
    double get_total_tax() const;
    
    private:
    //Vector for normal items
    vector<double> itemPrice;
    vector<int> centPrice;
    //Vector for taxed items
    vector<double> tax_itemPrice;
    vector<int> tax_centPrice;
    double tax;
    
};



#endif