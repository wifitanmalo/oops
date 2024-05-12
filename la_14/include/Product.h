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
        void set_price();
        void set_amount();
        void reduce(int, int);
        void set_date();
        // getter
        string get_price();
        // crud
        void create();
        void read();
        void update();
        void d_elete();
        string price;
};


#endif // PRODUCT_H
