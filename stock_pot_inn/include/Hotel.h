#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include "Reception.h"
using namespace std;


class Hotel : public Reception
{
    public:
        Hotel();
        virtual ~Hotel();
        void menu();
    private:
        int option;
};


#endif // HOTEL_H
