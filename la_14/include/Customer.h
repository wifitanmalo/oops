#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include "Cloud.h"
using namespace std;


class Customer : public Cloud
{
    public:
        Customer();
        virtual ~Customer();
        // setters
        void set_name();
        void set_date();

        void create(bool);
        void read(bool);
        void update(bool);
        void d_elete(bool);
    protected:
        vector<Customer> customers;
};

#endif // CUSTOMER_H
