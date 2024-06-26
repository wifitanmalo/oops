#ifndef PRODUCT_H
#define PRODUCT_H

#include <iomanip>
#include "Cloud.h"

class Product : public Cloud
{
    public:
        Product();
        ~Product();
        // setters
        void set_id();
        void set_name();
        void set_price();
        void set_points();
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
};


#endif // PRODUCT_H
