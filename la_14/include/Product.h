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
        void set_stock();
        void set_price();
        void set_reduce(int, int);
        // getters
        int get_stock();
        float get_price();
        // CRUD methods
        void create(bool);
        void read(bool);
        void update(bool);
        void d_elete(bool);
    private:
        float price;
        int stock;
    protected:
        vector<Product> products;
};

#endif // PRODUCT_H
