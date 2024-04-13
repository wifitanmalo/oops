#ifndef RECEPTION_H
#define RECEPTION_H

#include <iomanip>
#include <iostream>
#include <vector>
#include "Room.h"
using namespace std;


class Reception : public Room
{
    public:
        Reception();
        virtual ~Reception();
        // setters
        void set_change(float, float);
        void set_income(float, float);
        // getter
        float get_change();
        // methods
        void fill_rooms();
        void show_rooms();
        void assign_room();
        void check_room();
        void unassign_room();
    private:
        float change;
        bool exist=false, available=true;
    protected:
        vector<Reception> income;
};


#endif // RECEPTION_H
