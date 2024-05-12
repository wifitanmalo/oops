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
            cout << "----- negative numbers not allowed -----" << endl;
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
    amount = to_string(static_cast<int>(number));
}


string Cloud::get_amount()
{
    return amount;
}


void Cloud::set_date(string message)
{
    int dd, mm, yyyy, limit;
    while(true)
    {
        cout << message << endl;
        set_number("DD: "); dd = number;
        set_number("MM: "); mm = number;
        set_number("YYYY: "); yyyy = number;
        switch(mm)
        {
            case 1: limit = 31; break;
            case 2:
            {
                limit = 28;
                if(yyyy%4 == 0)
                {
                    limit = 29;
                }
            }; break;
            case 3: limit = 31; break;
            case 4: limit = 30; break;
            case 5: limit = 31; break;
            case 6: limit = 30; break;
            case 7: limit = 31; break;
            case 8: limit = 31; break;
            case 9: limit = 30; break;
            case 10: limit = 31; break;
            case 11: limit = 30; break;
            case 12: limit = 31; break;
        }
        if((dd > limit) || (mm > 12))
        {
            system("cls");
            cout << "----- invalid date -----" << endl;
        }
        else
        {
            date = to_string(dd) + to_string(mm) + to_string(yyyy);
            break;
        }
    }
}


string Cloud::get_date()
{
    return date;
}


void Cloud::set_price()
{
    set_number("- Price: $");
    price = number;
}


string Cloud::get_price()
{
    return price;
}


void Cloud::set_points()
{
    set_number("- Points: ");
    points = to_string(static_cast<int>(number));
}


void Cloud::set_totalpoints(int current_points, int earned, int booster)
{
    number = current_points + (earned*booster);
    points = to_string(static_cast<int>(number));
}


void Cloud::set_increasepoints(int customer_points, int total)
{
    number = customer_points+total;
    points = to_string(static_cast<int>(number));
}


void Cloud::stock_reduce(int stock_amount, int amount_bought)
{
    number = stock_amount-amount_bought;
    amount = to_string(static_cast<int>(number));
}


string Cloud::get_points()
{
    return points;
}


void Cloud::set_exist(string id, string file)
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


bool Cloud::get_exist()
{
    return exist;
}


void Cloud::not_founded(bool exist)
{
    if(!exist)
    {
        cout << "----- not founded -----" << endl;
    }
}
