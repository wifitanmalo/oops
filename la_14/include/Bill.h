#ifndef BILL_H
#define BILL_H

#include<iostream>
#include<vector>
#include "Cloud.h"
using namespace std;


class Bill : public Cloud
{
    public:
        Bill();
        ~Bill();
        // setters
        void set_id(string);
        void set_billy();
        void set_amount();
        void set_productnumber(int, int);
        void set_total(float, float, int);
        void set_cash();
        void set_change(float, float);
        void set_date();
        // get setters
        int get_billy();
        int get_productnumber();
        float get_total();
        float get_cash();
        float get_change();
    private:
        int billy=0, product_number;
        float total, cash, change;
    protected:
        vector<Bill> bills, bought_products;
};


#endif // BILL_H
