#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;


class Customer
{
    public:
        Customer();
        virtual ~Customer();
        // setters
        void set_name();
        void set_number(string);
        void set_id();
        void set_cash();
        // getters
        string get_name();
        long get_id();
        float get_cash();
    private:
        string name, message;
        long id;
        float cash;
    protected:
        double number;
};


#endif // CUSTOMER_H
