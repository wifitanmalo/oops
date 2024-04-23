#ifndef CRUD_H
#define CRUD_H

#include <iostream>
#include "Customer.h"
#include "Product.h"
#include "Bill.h"
using namespace std;


class Crud : public Customer, Product, Bill
{
    public:
        Crud();
        virtual ~Crud();
        void create(int, int, bool);
        void read(int, int, bool);
        void update(int, int, bool);
        void d_elete(int, int, bool);
    private:
        int option;
};


#endif // CRUD_H
