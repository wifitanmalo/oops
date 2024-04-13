#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<vector>
#include "Cloud.h"
using namespace std;


class Product : public Cloud
{
    public:
        Product();
        ~Product();
        void set_stock();
        void set_price();
        void set_reduce(int, int);
        int get_stock();
        float get_price();
    private:
        float price;
        int stock;
    protected:
        vector<Product> products;
};

#endif // PRODUCT_H
