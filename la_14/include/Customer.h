#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
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
        void create();
        void read();
        void update();
        void d_elete();
};

#endif // CUSTOMER_H
