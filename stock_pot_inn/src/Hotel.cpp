#include "Hotel.h"


Hotel::Hotel()
{
    //ctor
}


Hotel::~Hotel()
{
    //dtor
}


void Hotel::menu()
{
    cout << "***** Welcome to the Stock Pot In *****" << endl;
    cout << "1. Assign room" << endl;
    cout << "2. Check room" << endl;
    cout << "3. Unassign room" << endl;
    cout << "4. Total income" << endl << endl;
    cout << "Enter your choice: "; cin >> option;
    switch(option)
    {
        case 1: assign_room(); break;
        case 2: check_room(); break;
        case 3: unassign_room();  break;
        case 4: cout << "- TOTAL INCOME: $" << income[0].get_total() << endl; break;
        default: cout << "----- see you space, cowboy -----"; exit(0); break;
    }
}
