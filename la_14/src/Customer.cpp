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


void Customer::set_id()
{
    Cloud::set_id("- Customer ID: ");
}


void Customer::set_date()
{
    Cloud::set_date("- Birthday: ");
}


void Customer::create(bool exist)
{
    customer.set_name();
    customer.set_id();
    searched = customer.get_id();
    customer.existence(searched, "customers.csv");
    if(customer.get_exist())
    {
        cout << "----- customer already exists -----" << endl;
    }
    else
    {
        ofstream file("customers.csv", ios::app);
        if (file.is_open())
        {
            customer.set_date();
            customer.set_increasepoints(0, 0);
            file << customer.get_id() << "," << customer.get_name() << "," << customer.get_date() << "," << customer.get_points() << endl;
            cout << "----- customer '" << customer.get_name() << "' created succesfully -----" << endl;
        }
        else
        {
            cout << "----- customers.csv error -----" << endl;
        }
    }
}


void Customer::read(bool exist)
{
    customer.set_id();
    customer.existence(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        ifstream file("customers.csv", ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                stringstream customers(line);
                getline(customers, id,',');
                getline(customers, name,',');
                getline(customers, date,',');
                //getline(customers, cedula,',');
                if(customer.get_id().compare(id) == 0)
                {
                    cout << "NAME: " << name << endl;
                    cout << "BIRTHDAY: " << date << endl;
                    cout << "ACCUMULATED POINTS: " << endl;
                    break;
                }
            }
            file.close();
        }
        else
        {
            cout << "----- customers.csv error -----" << endl;
        }
    }
    else
    {
        not_founded(customer.get_exist());
    }
}


void Customer::update(bool exist)
{
    customer.set_id();
    customer.existence(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        ifstream original("customers.csv");
        ofstream temporary("temporary.csv");
        if(original.is_open() && temporary.is_open())
        {
            while(getline(original, line))
            {
                stringstream update(line);
                getline(update, id, ',');
                getline(update, name, ',');
                getline(update, date, ',');
                if(customer.get_id() == id)
                {
                    old = name;
                    customer.set_name();
                    customer.set_id();
                    customer.set_date();
                    customer.set_increasepoints(0, 0);
                    temporary << customer.get_id() << "," << customer.get_name() << "," << customer.get_date() << "," << customer.get_points() << endl;
                }
                else
                {
                    temporary << line << endl;
                }
            }
            original.close();
            temporary.close();
            remove("customers.csv");
            rename("temporary.csv", "customers.csv");
            cout << "----- customer '" << old << "' updated to '" << customer.get_name() << "' succesfully -----" << endl;
        }
        else
        {
            cout << "----- .csv error -----" << endl;
        }
    }
    else
    {
        not_founded(customer.get_exist());
    }
}


void Customer::d_elete(bool exist)
{
    customer.set_id();
    customer.existence(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        ifstream original("customers.csv");
        ofstream temporary("temporary.csv");
        if(original.is_open() && temporary.is_open())
        {
            while(getline(original, line))
            {
                stringstream to_delete(line);
                getline(to_delete, id, ',');
                getline(to_delete, name, ',');
                getline(to_delete, date, ',');
                if(customer.get_id() == id)
                {
                    deleted = name;
                }
                else
                {
                    temporary << line << endl;
                }
            }
            original.close();
            temporary.close();
            remove("customers.csv");
            rename("temporary.csv", "customers.csv");
            cout << "----- customer '" << deleted << "' deleted succesfully -----" << endl;
        }
        else
        {
            cout << "----- .csv error -----" << endl;
        }
    }
    else
    {
        not_founded(customer.get_exist());
    }
}
