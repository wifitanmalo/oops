#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "Crud.h"
using namespace std;


class Menu : public Crud
{
    public:
        Menu();
        ~Menu();
        void menu();
        void crud_menu(int, int, bool);
    private:
       int data, option;
};


#endif // MENU_H
