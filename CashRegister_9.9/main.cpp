#include "CashRegister.h"
#include <iostream> 
#include <vector> 
#include <typeinfo> 

using namespace std;


int main()
{
    CashRegister register1(0.0725);
    register1.add_item(9.95);
    register1.add_item(100);
    cout << register1.get_count() << endl;
    cout << register1.get_total() << endl;
    register1.add_taxable_item(9.95);
    register1.add_taxable_item(100);
    cout << register1.get_count() << endl;
    cout << register1.get_total() << endl;
    cout << register1.get_total_tax() << endl;
    register1.display_all();

    
    cout << register1.get_sales_count() << endl;
    cout << register1.get_sales_total() << endl;

    register1.clear();
    register1.display_all();
    register1.reset_sales();
}