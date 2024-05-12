#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Crud.h"
using namespace std;


class Menu
{
    public:
        Menu();
        ~Menu();
        void menu();
        void crud_menu(int, int);
    private:
        Crud crud;
        int data, option;
};


#endif // MENU_H
