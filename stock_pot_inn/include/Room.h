#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "Customer.h"
using namespace std;


class Room : public Customer
{
    public:
        Room();
        virtual ~Room();
        // setters
        void set_floor();
        void set_room();
        void set_total(int);
        // getters
        int get_floor();
        int get_room();
        float get_total();
    private:
        int floor, room;
    protected:
        string floors[4] = {" Piso #4", " Piso #3", " Piso #2", " Piso #1"};
        string rooms[4] = {"1", "2", "3", "4"};
        string rooms_array[5][5];
        float total;
        vector<Room> reservations;
};


#endif // ROOM_H
