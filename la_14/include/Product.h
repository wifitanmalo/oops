#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "Cloud.h"
using namespace std;


class Product : public Cloud
{
    public:
        Product();
        ~Product();
        // setters
        void set_name();
        void set_id();
        void set_amount();
        void set_date();
        // getters
        // crud
        void create();
        void read();
        void update();
        void d_elete();
};


#endif // PRODUCT_H
