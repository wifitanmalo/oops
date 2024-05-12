#ifndef BILL_H
#define BILL_H

#include<iostream>
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

        void set_total(float, float, int);
        void set_cash();
        void set_change(float, float);

        void set_date();
        // get setters
        int get_billy();
        string get_total();
        string get_cash();
        string get_change();
        // crud
        void create(int);
        void read();
        void update(int);
        void d_elete();
    private:
        int billy=0, option;
        string total, cash, change;
};


#endif // BILL_H
