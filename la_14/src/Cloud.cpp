#include "Cloud.h"


Cloud::Cloud()
{
    //ctor
}


Cloud::~Cloud()
{
    //dtor
}


void Cloud::set_number(string message)
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



double Cloud::get_number()
{
    return number;
}


void Cloud::set_customerid()
{
    set_number("- Customer ID: ");
    customer_id = number;
}


long Cloud::get_customerid()
{
    return customer_id;
}


void Cloud::set_productid()
{
    set_number("- Product ID: ");
    product_id = number;
}


long Cloud::get_productid()
{
    return product_id;
}


void Cloud::set_name()
{
    fflush(stdin);
    cout << "- Name: "; getline(cin, name);
}


string Cloud::get_name()
{
    return name;
}


void Cloud::set_date()
{
    set_number("- Date: ");
    date = number;
}


long Cloud::get_date()
{
    return date;
}


void Cloud::set_points()
{
    set_number("- Points: ");
    points = number;
}


void Cloud::set_totalpoints(int current_points, int earned, int booster)
{
    points = current_points + (earned*booster);
}


void Cloud::set_increasepoints(int customer_points, int total)
{
    points = customer_points+total;
}


int Cloud::get_points()
{
    return points;
}


void Cloud::not_founded(bool exist)
{
    if(!exist)
    {
        cout << "----- not founded -----" << endl;
    }
}
