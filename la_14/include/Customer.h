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
        void set_id();
        void set_date();
        // crud
        void create(bool);
        void read(bool);
        void update(bool);
        void d_elete(bool);
};

#endif // CUSTOMER_H
