#include "Customer.h"


Customer::Customer()
{
    //ctor
}


Customer::~Customer()
{
    //dtor
}


void Customer::set_name()
{
    fflush(stdin);
    cout << "- Customer name: "; getline(cin, name);
}


string Customer::get_name()
{
    return name;
}

void Customer::set_number(string message)
{
    while(true)
    {
        cout << message; cin >> number;
        if(number < 1)
        {
            cout << "----- negative numbers not allowed" << endl;
        }
        else
        {
            break;
        }
    }
}


void Customer::set_id()
{
    set_number("- Customer ID: ");
    id = number;
}


long Customer::get_id()
{
    return id;
}


void Customer::set_cash()
{
    set_number("- Cash: $");
    cash = number;
}


float Customer::get_cash()
{
    return cash;
}
