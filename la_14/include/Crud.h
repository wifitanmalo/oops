#ifndef CRUD_H
#define CRUD_H


#include <iostream>
#include <vector>
#include "Customer.h"
#include "Product.h"
#include "Bill.h"
using namespace std;


class Crud : public Customer, Product, Bill
{
    public:
        Crud();
        virtual ~Crud();
        void create(int);
        void rudy(int, int);
    private:
        int option, loop=1;
        string old, deleted;
        bool exist=false;
};


#endif // CRUD_H
