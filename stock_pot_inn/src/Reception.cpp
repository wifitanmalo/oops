#include "Reception.h"

Customer customer;
Room roomie;
Reception reception;


Reception::Reception()
{
    //ctor
}


Reception::~Reception()
{
    //dtor
}


void Reception::set_income(float current, float add)
{
    total = current+add;
}


void Reception::set_change(float cash, float total)
{
    change = cash-total;
}


float Reception::get_change()
{
    return change;
}


void Reception::fill_rooms()
{
    reception.set_income(0, 0);
    income.push_back(reception);
    for(int f=0; f<5; f++)
    {
        for(int r=0; r<5; r++)
        {
            if((f==0) && (r>0))
            {
                rooms_array[f][r] = rooms[r-1];
            }
            if((f>0) && (r==0))
            {
                rooms_array[f][r] = floors[f-1];
            }
            if((f>0) && (r>0))
            {
                rooms_array[f][r] = "O";
            }
        }
    }
}


void Reception::show_rooms()
{
    for(int f=0; f<5; f++)
    {
        for(int r=0; r<5; r++)
        {
            cout << setw(8) << rooms_array[f][r] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}


void Reception::assign_room()
{
    roomie.set_id();
    for(int r=0; r<reservations.size(); r++)
    {
        if(roomie.get_id() == reservations[r].get_id())
        {
            cout << "----- customer '" << reservations[r].get_name() << "' is already in a room -----" << endl;
            exist = true;
            break;
        }
    }
    if(!exist)
    {
        roomie.set_name();
        roomie.set_floor();
        roomie.set_room();
        roomie.set_total(roomie.get_floor());
        for(int r; r<reservations.size(); r++)
        {
            if( (roomie.get_floor() == reservations[r].get_floor())
               && (roomie.get_room() == reservations[r].get_room()))
            {
                cout << "----- room unavailable -----" << endl;
                available = false;
                break;
            }
        }
        if(available == true)
        {
            rooms_array[5-roomie.get_floor()][roomie.get_room()] = "X";
            reservations.push_back(roomie);
            cout << "----- room assigned succesfully -----" << endl;
        }
    }
    available = true;
    exist = false;
}


void Reception::check_room()
{
    customer.set_id();
    for(int r=0; r<reservations.size(); r++)
    {
        if(customer.get_id() == reservations[r].get_id())
        {
            exist = true;
            cout << "CUSTOMER NAME: " << reservations[r].get_name() << endl;
            cout << "ROOM: #" << reservations[r].get_room() << endl;
            cout << "FLOOR: #" << reservations[r].get_floor() << endl;
            cout << "**** AMOUNT TO PAY >>>> $" << reservations[r].get_total() << endl;
            break;
        }
    }
    if(!exist)
    {
        cout << "----- not founded -----" << endl;
    }
    exist = false;
}


void Reception::unassign_room()
{
    customer.set_id();
    for(int r=0; r<reservations.size(); r++)
    {
        if(customer.get_id() == reservations[r].get_id())
        {
            while(true)
            {
                customer.set_cash();
                reception.set_change(customer.get_cash(), reservations[r].get_total());
                if(reception.get_change() < 0)
                {
                    cout << "----- not enough cash -----" << endl;
                }
                else
                {
                    rooms_array[5-reservations[r].get_floor()][reservations[r].get_room()] = "O";
                    reception.set_income(income[0].get_total(), reservations[r].get_total());
                    income[0] = reception;
                    reservations.erase(reservations.begin()+r);
                    cout << "- Change: $" << reception.get_change() << endl;
                    cout << "----- room successfully unassigned -----" << endl;
                    break;
                }
            }
            exist = true;
            break;
        }
    }
    if(!exist)
    {
        cout << "----- not founded -----" << endl;
    }
    exist = false;
}
