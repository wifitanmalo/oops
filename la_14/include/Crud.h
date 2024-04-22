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
        void c_reate(int, int, bool);
        void r_ead(int, int, bool);
        void u_pdate(int, int, bool);
        void d_elete(int, int, bool);
        void not_founded(bool);
    private:
        int option;
        string old, deleted;
};


#endif // CRUD_H
