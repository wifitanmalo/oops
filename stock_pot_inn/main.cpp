#include <iostream>
#include "Hotel.h"
using namespace std;


int main()
{
    Hotel hotel;
    hotel.fill_rooms();
    hotel.show_rooms();
    while(true)
    {
        hotel.menu();
        system("pause");
        system("cls");
        hotel.show_rooms();
    }
    return 0;
}
