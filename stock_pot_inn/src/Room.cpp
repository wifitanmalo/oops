#include "Room.h"


Room::Room()
{
    //ctor
}


Room::~Room()
{
    //dtor
}


void Room::set_floor()
{
    set_number("- Floor number: ");
    floor = number;
}


int Room::get_floor()
{
    return floor;
}


void Room::set_room()
{
    set_number("- Room number: ");
    room = number;
}


int Room::get_room()
{
    return room;
}


void Room::set_total(int floor)
{
    switch(floor)
    {
        case 1: total = 32000; break;
        case 2: total = 43000; break;
        case 3: total = 52000; break;
        case 4: total = 65000; break;
    }
}


float Room::get_total()
{
    return total;
}
