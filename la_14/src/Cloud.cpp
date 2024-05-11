#include "Cloud.h"


Cloud::Cloud()
{
    //ctor
}


Cloud::~Cloud()
{
    //dtor
}


void Cloud::set_name(string message)
{
    fflush(stdin);
    cout << message; getline(cin, name);
}


string Cloud::get_name()
{
    return name;
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


void Cloud::set_id(string message)
{
    set_number(message);
    id = to_string(static_cast<long>(number));
}


string Cloud::get_id()
{
    return id;
}


void Cloud::set_amount(string message)
{
    set_number(message);
    amount = number;
}


int Cloud::get_amount()
{
    return amount;
}


void Cloud::set_date(string message)
{
    set_number(message);
    date = to_string(static_cast<long>(number));
}


string Cloud::get_date()
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


void Cloud::stock_reduce(int stock_amount, int amount_bought)
{
    amount = stock_amount-amount_bought;
}


int Cloud::get_points()
{
    return points;
}


void Cloud::set_exist(bool value)
{
    exist = value;
}


bool Cloud::get_exist()
{
    return exist;
}


void Cloud::existence(string id, string file)
{
    exist = false;
    ifstream read(file);
    while(getline(read, line))
    {
        string registered_id = line.substr(0, line.find(','));
        if(id == registered_id)
        {
            exist = true;
        }
    }
    read.close();
}


void Cloud::not_founded(bool exist)
{
    if(!exist)
    {
        cout << "----- not founded -----" << endl;
    }
}
