#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<vector>
#include "Cloud.h"
using namespace std;


class Customer : public Cloud
{
    public:
        Customer();
        virtual ~Customer();
    protected:
        vector<Customer> customers;
};

#endif // CUSTOMER_H
