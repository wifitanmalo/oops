#include "Cloud.h"


Cloud::Cloud()
{
    //ctor
}


Cloud::~Cloud()
{
    //dtor
}

// function to enter a positive number
void Cloud::set_number(string message)
{
    while(true)
    {
        cout << message; cin >> number;
        if(number < 0) // verify that the number is not negative
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

// function to enter an id
void Cloud::set_id(string message)
{
    set_number(message);
    id = to_string(static_cast<long>(number));
}


string Cloud::get_id()
{
    return id;
}

// function to search an id in a file an drops true/false based on the existence
void Cloud::set_exist(string id, string file)
{
    exist = false;
    ifstream read(file);
    if(read.is_open())
    {
        while(getline(read, line))
        {
            string registered = line.substr(0, line.find(',')); // verify if the id is in the line
            if(id == registered)
            {
                exist = true;
            }
        }
        read.close();
    }
    else
    {
        open_error(file);
    }
}


bool Cloud::get_exist()
{
    return exist;
}

// function to enter a name
void Cloud::set_name(string message)
{
    fflush(stdin); // clean the memory buffer
    cout << message; getline(cin, name);
}


string Cloud::get_name()
{
    return name;
}

// function to enter an amount of stock/to buy
void Cloud::set_amount(string message)
{
    set_number(message);
    amount = to_string(static_cast<int>(number));
}


string Cloud::get_amount()
{
    return amount;
}

// function to enter a date that verifies if is valid
void Cloud::set_date(string message)
{
    int dd, mm, yyyy, limit;
    date = "0";
    while(true)
    {
        cout << message << endl;
        set_number("DD: "); dd = number;
        set_number("MM: "); mm = number;
        set_number("YYYY: "); yyyy = number;
        switch(mm)
        {
            case 1: limit = 31; break; // january
            case 2: // february
            {
                limit = 28;
                if(yyyy%4 == 0) // leap-year
                {
                    limit = 29;
                }
            }; break;
            case 3: limit = 31; break; // march
            case 4: limit = 30; break; // april
            case 5: limit = 31; break; // may
            case 6: limit = 30; break; // june
            case 7: limit = 31; break; // july
            case 8: limit = 31; break; // august
            case 9: limit = 30; break; // september
            case 10: limit = 31; break; // october
            case 11: limit = 30; break; // november
            case 12: limit = 31; break; // december
        }
        if((dd>limit) || (mm>12)) // verify that the day/month is not higher than the limit
        {
            system("cls");
            cout << "----- invalid date -----" << endl;
        }
        else
        {
            date = to_string(dd) + "/" + to_string(mm) + "/" + to_string(yyyy); // save the date in the format DD/MM/YYYY
            break;
        }
    }
}


string Cloud::get_date()
{
    return date;
}


string Cloud::get_points()
{
    return points;
}

// ask for an id and replace the file without the deleted item
void Cloud::d_elete(string file, string searched)
{
    ifstream original(file);
    ofstream updated("updated.csv", ios::app);
    if((original.is_open()) && (updated.is_open()))
    {
        while(getline(original, line))
        {
            stringstream to_delete(line);
            getline(to_delete, id, ',');
            getline(to_delete, name, ',');
            if(searched == id)
            {
                continue; // ignores the line to delete
            }
            else
            {
                updated << line << endl;
            }
        }
        original.close();
        updated.close();
        remove(file.c_str());
        rename("updated.csv", file.c_str());
    }
    else
    {
        open_error(file);
    }
}

// error message that shows when the file can not be open
void Cloud::open_error(string file)
{
    cout << "----- " + file + " error -----" << endl;
}

// search an id and save the item data
void Cloud::eyefind(string file, string searched, int option)
{
    ifstream seek(file, ios::in);
    if(seek.is_open())
    {
        while(getline(seek, line))
        {
            stringstream token(line);
            getline(token, id,',');
            if((id == searched) && (option == 1)) // customer data
            {
                getline(token, name,',');
                getline(token, date,',');
                getline(token, points,',');
                break;
            }
        }
        seek.close();
    }
    else
    {
        open_error(file);
    }
}

// message that shows when the id does not exist
void Cloud::not_founded(bool exist)
{
    if(!exist)
    {
        cout << "----- not founded -----" << endl;
    }
}

// succes message that shows when somethings ends well
void Cloud::success(int option, int crud)
{
    string type;
    switch(option)
    {
        case 1: type = "customer"; break;
        case 2: type = "product"; break;
        case 3: type = "bill"; break;
    }
    switch(crud)
    {
        case 1: cout << "----- " << type << " created succesfully -----" << endl; break;
        case 3: cout << "----- " << type << " updated succesfully -----" << endl; break;
        case 4: cout << "----- " << type << " deleted succesfully -----" << endl; break;
    }
}
