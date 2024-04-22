#include "Menu.h"


Menu::Menu()
{
    //ctor
}


Menu::~Menu()
{
    //dtor
}


void Menu::menu()
{
    cout << "***** Welcome to La 14 ***** "<<endl;
    cout << "1. Customer" << endl;
    cout << "2. Product" << endl;
    cout << "3. Bill" << endl;
    cout<<"\nSelect the data type to operate on: "; cin >> data;
    if((data==1) || (data==2) || (data==3))
    {
        crud_menu(data, 1, false);
    }
    else
    {
        cout << "----- See you space, cowboy -----\n"; exit(0);
    }
}


void Menu::crud_menu(int data, int loop, bool exist)
{
    system("cls");
    cout << "1. Create" << endl;
    cout << "2. Read" << endl;
    cout << "3. Update" << endl;
    cout << "4. Delete" << endl;
    cout << "\nSelect your choice: "; cin >> option;
    system("cls");
    switch(option)
    {
        case 1: c_reate(data, loop, exist); break;
        case 2: r_ead(data, loop, exist); break;
        case 3: u_pdate(data, loop, exist); break;
        case 4: d_elete(data, loop, exist); break;
        default: cout << "----- See you space, cowboy -----\n"; exit(0); break;
    }
}
