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


void Customer::set_id()
{
    Cloud::set_id("- Customer ID: ");
}


void Customer::set_name()
{
    Cloud::set_name("- Customer name: ");
}


void Customer::set_date()
{
    Cloud::set_date("- Birthday: ");
}

// function to calculate the total points of each purchase
void Customer::set_totalpoints(int current_points, int earned, int booster)
{
    number = current_points + (earned*booster); // add to the current points the product of the earned points and the amount purchased
    points = to_string(static_cast<int>(number));
}

// function that ask for an id and verify that does not exist to create the customer
void Customer::create()
{
    customer.set_id();
    customer.set_exist(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        cout << "----- customer already exists -----" << endl;
    }
    else
    {
        ofstream create("customers.csv", ios::app);
        if(create.is_open())
        {
            customer.set_name();
            customer.set_date();
            customer.set_totalpoints(0, 0, 0);

            create << customer.get_id() << ","
            << customer.get_name() << ","
            << customer.get_date() << ","
            << customer.get_points() << endl; // add the new customer to customers.csv file

            success(1, 1);
            create.close();
        }
        else
        {
            open_error("customers.csv");
        }
    }
}

// function that ask for an ID to print the customer data
void Customer::read()
{
    customer.set_id();
    customer.set_exist(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        Cloud::eyefind("customers.csv", customer.get_id(), 1);
        cout << "NAME: " << name << endl;
        cout << "BIRTHDAY: " << date << endl;
        cout << "ACCUMULATED POINTS: " << points << endl;
    }
    else
    {
        not_founded(customer.get_exist());
    }
}

// function that ask for an id and verify that does not exist or it's the same to update the customer
void Customer::update()
{
    customer.set_id();
    customer.set_exist(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        ifstream original("customers.csv");
        ofstream updated("updated.csv", ios::app);
        if(original.is_open() && updated.is_open())
        {
            while(getline(original, line))
            {
                stringstream customers(line);
                getline(customers, id,',');
                getline(customers, name,',');
                getline(customers, date,',');
                getline(customers, points,',');
                if(customer.get_id() == id) // line to update
                {
                    customer.set_id();
                    customer.set_exist(customer.get_id(), "customers.csv");
                    if(customer.get_exist() && customer.get_id() != id) // if the id is different, verify that it does not exist
                    {
                        updated << line << endl;
                        cout << "----- customer already exists -----" << endl;
                    }
                    else // id is the same
                    {
                        customer.set_name();
                        customer.set_date();

                        updated << customer.get_id() << ","
                        << customer.get_name() << ","
                        << customer.get_date() << ","
                        << points << endl; // add the updated customer to the updated.csv file

                        success(1, 3);
                    }
                }
                else // normal line
                {
                    updated << line << endl;
                }
            }
            original.close();
            updated.close();
            remove("customers.csv");
            rename("updated.csv", "customers.csv");
        }
        else
        {
            open_error("customers.csv");
        }
    }
    else
    {
        not_founded(customer.get_exist());
    }

}

// function to update the customers points
void Customer::update_points(string searched, int add)
{
    ifstream original("customers.csv");
    ofstream updated("updated.csv");
    while(getline(original, line))
    {
        stringstream customers(line);
        getline(customers, id, ',');
        getline(customers, name, ',');
        getline(customers, date, ',');
        getline(customers, points, ',');
        if(searched == id) // line to update
        {
            number = stoi(points) + add;

            updated << id << ","
            << name << ","
            << date << ","
            << to_string(static_cast<int>(number)) << endl; // add the customer with the updated points to updated.csv file
        }
        else // normal line
        {
            updated << line << endl;
        }
    }
    original.close();
    updated.close();
    remove("customers.csv");
    rename("updated.csv", "customers.csv");
}

// function that ask for an ID and calls the Cloud d_elete() to delete the customer
void Customer::d_elete()
{
    customer.set_id();
    customer.set_exist(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        Cloud::d_elete("customers.csv", customer.get_id());
        success(1, 4);
    }
    else
    {
        not_founded(customer.get_exist());
    }
}
