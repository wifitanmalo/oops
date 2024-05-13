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


void Customer::set_totalpoints(int current_points, int earned, int booster)
{
    number = current_points + (earned*booster);
    points = to_string(static_cast<int>(number));
}


void Customer::set_increase(int customer_points, int total)
{
    number = customer_points+total;
    points = to_string(static_cast<int>(number));
}


void Customer::create()
{
    customer.set_name();
    customer.set_id();
    customer.set_exist(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        cout << "----- customer already exists -----" << endl;
    }
    else
    {
        ofstream create("customers.csv", ios::app);
        if (create.is_open())
        {
            customer.set_date();
            customer.set_increase(0, 0);
            create << customer.get_id() << "," << customer.get_name() << "," << customer.get_date() << "," << customer.get_points() << endl;
            cout << "----- customer '" << customer.get_name() << "' created succesfully -----" << endl;
        }
        else
        {
            cout << "----- customers.csv error -----" << endl;
        }
    }
}


void Customer::read()
{
    customer.set_id();
    customer.set_exist(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        ifstream read("customers.csv", ios::in);
        if(read.is_open())
        {
            while(getline(read, line))
            {
                stringstream customers(line);
                getline(customers, id,',');
                getline(customers, name,',');
                getline(customers, date,',');
                getline(customers, points,',');
                if(customer.get_id().compare(id) == 0)
                {
                    cout << "NAME: " << name << endl;
                    cout << "BIRTHDAY: " << date << endl;
                    cout << "ACCUMULATED POINTS: " << points << endl;
                    break;
                }
            }
            read.close();
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


void Customer::update()
{
    customer.set_id();
    customer.set_exist(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        ifstream original("customers.csv");
        ofstream updated("updated.csv");
        if(original.is_open() && updated.is_open())
        {
            while(getline(original, line))
            {
                stringstream customers(line);
                getline(customers, id, ',');
                getline(customers, name, ',');
                getline(customers, date, ',');
                getline(customers, points, ',');
                if(customer.get_id() == id)
                {
                    old = name;
                    customer.set_name();
                    customer.set_id();
                    customer.set_exist(customer.get_id(), "customers.csv");
                    if(customer.get_exist() && customer.get_id() != id)
                    {
                        updated << line << endl;
                        cout << "----- customer already exists -----" << endl;
                    }
                    else
                    {
                        customer.set_date();
                        customer.set_increase(stoi(points), 0);
                        updated << customer.get_id() << "," << customer.get_name() << "," << customer.get_date() << "," << customer.get_points() << endl;
                        cout << "----- customer '" << old << "' updated to '" << customer.get_name() << "' -----" << endl;
                    }
                }
                else
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
            cout << "----- customers.csv error -----" << endl;
        }
    }
    else
    {
        not_founded(customer.get_exist());
    }
}


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
        if(searched == id)
        {
            number = stoi(points) + add;
            updated << id << "," << name << "," << date << "," << to_string(static_cast<int>(number)) << endl;
        }
        else
        {
            updated << line << endl;
        }
    }
    original.close();
    updated.close();
    remove("customers.csv");
    rename("updated.csv", "customers.csv");
}


void Customer::d_elete()
{
    customer.set_id();
    customer.set_exist(customer.get_id(), "customers.csv");
    if(customer.get_exist())
    {
        ifstream original("customers.csv");
        ofstream updated("updated.csv");
        if(original.is_open() && updated.is_open())
        {
            while(getline(original, line))
            {
                stringstream customers(line);
                getline(customers, id, ',');
                getline(customers, name, ',');
                if(customer.get_id() == id)
                {
                    deleted = name;
                }
                else
                {
                    updated << line << endl;
                }
            }
            original.close();
            updated.close();
            remove("customers.csv");
            rename("updated.csv", "customers.csv");
            cout << "----- customer '" << deleted << "' deleted succesfully -----" << endl;
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
