#ifndef BILL_H
#define BILL_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include "Customer.h"
#include "Product.h"
using namespace std;


class Bill
{
    public:
        Bill();
        ~Bill();
        // setters
        void set_id();
        void set_amount();
        void set_subtotal(float, float, int);
        void set_cash();
        void set_change(float, float);
        // get setters
        string get_billy();
        string get_subtotal();
        string get_cash();
        string get_change();
        // methods
        void sales_report(int, int);
        void products_report();
        void low_demand();
        // crud
        void create(int);
        void read(string, string, bool);
        void update(int);
        void d_elete();
    private:
        Customer paypal;
        Product bought;
        int earned;
        string line, billy, chopped, subtotal, cash, change;
        stringstream print_line;
};


#endif // BILL_H
