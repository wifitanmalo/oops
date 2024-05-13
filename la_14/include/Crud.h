#ifndef CRUD_H
#define CRUD_H

#include <iostream>
#include "Customer.h"
#include "Product.h"
#include "Bill.h"
using namespace std;


class Crud
{
    public:
        Crud();
        virtual ~Crud();
        void create(int, int);
        void read(int);
        void update(int, int);
        void d_elete(int);
    private:
        Customer c;
        Product p;
        Bill b;
};


#endif // CRUD_H
