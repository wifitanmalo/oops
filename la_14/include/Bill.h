#ifndef BILL_H
#define BILL_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include "Customer.h"
#include "Product.h"
using namespace std;


class Bill
{
    public:
        Bill();
        ~Bill();
        // setters
        void set_billy();
        void set_amount();
        void set_subtotal(float, float, int);
        void set_cash();
        void set_change(float, float);
        // get setters
        string get_billy();
        string get_subtotal();
        string get_cash();
        string get_change();
        // crud
        void create(int);
        void read(string, string, bool);
        void update(int);
        void d_elete();
        // methods
        void sales_report(int, int);
        void products_report();
    private:
        Customer paypal;
        Product bought;
        int option, earned;
        stringstream print_line;
        string billy, chopped, subtotal, cash, change;
        string name, customer_name, id, price, amount, points, date, line, deleted;
};


#endif // BILL_H
