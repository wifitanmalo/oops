#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
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
        void set_date();
        // getters
        float get_price();
        // CRUD methods
        void create(bool);
        void read(bool);
        void update(bool);
        void d_elete(bool);
    private:
        float price;
    protected:
        vector<Product> products;
};

#endif // PRODUCT_H
