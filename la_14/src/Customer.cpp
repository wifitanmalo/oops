#include "Customer.h"


Customer customer;


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
    Cloud::set_name("- Customer name: ");
}


void Customer::set_date()
{
    Cloud::set_date("- Birthday: ");
}


void Customer::create(bool exist)
{
    customer.set_name();
    customer.set_customerid();
    for(int c=0; c<customers.size(); c++)
    {
        if(customer.get_customerid() == customers[c].get_customerid())
        {
            cout << "----- customer already exists -----" << endl;
            exist = true;
            break;
        }
    }
    if(!exist)
    {
        customer.set_date();
        customer.set_increasepoints(0, 0);
        customers.push_back(customer);
        cout << "----- customer '" << customer.get_name() << "' created succesfully -----" << endl;
    }
}


void Customer::read(bool exist)
{
    customer.set_customerid();
    for(int c=0; c<customers.size(); c++)
    {
        if(customer.get_customerid() == customers[c].get_customerid())
        {
            exist = true;
            cout << "NAME: " << customers[c].get_name() << endl;
            cout << "BIRTHDAY: " << customers[c].get_date() << endl;
            cout << "ACCUMULATED POINTS: " << customers[c].get_points() << endl;
            break;
        }
    }
    not_founded(exist);
}


void Customer::update(bool exist)
{
    customer.set_customerid();
    for(int a=0; a<customers.size(); a++)
    {
        if(customer.get_customerid() == customers[a].get_customerid())
        {
            old = customer.get_name();
            customer.set_name();
            customer.set_customerid();
            for(int b=0; b<customers.size(); b++)
            {
                if((customer.get_customerid() == customers[b].get_customerid())
                    && (customer.get_customerid() != customers[a].get_customerid()))
                {
                    exist = true;
                    cout << "----- customer already exists -----" << endl;
                    break;
                }
            }
            if(!exist)
            {
                customer.set_date();
                customer.set_increasepoints(customers[a].get_points(), 0);
                customers[a] = customer;
                cout << "----- customer '" << old << "' updated to '" << customer.get_name() << "' -----" << endl;
            }
            exist = true;
            break;
        }
    }
    not_founded(exist);
}


void Customer::d_elete(bool exist)
{
    customer.set_customerid();
    for(int c=0; c<customers.size(); c++)
    {
        if(customer.get_customerid() == customers[c].get_customerid())
        {
            exist = true;
            deleted = customers[c].get_name();
            customers.erase(customers.begin()+c);
            cout << "----- customer '" << deleted << "' deleted succesfully -----" << endl;
            break;
        }
    }
    not_founded(exist);
}
