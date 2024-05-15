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
        crud_menu(data, 1);
    }
    else
    {
        cout << "----- See you space, cowboy -----\n"; exit(0);
    }
}


void Menu::crud_menu(int data, int loop)
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
        case 1: crud.create(data, loop); break;
        case 2: crud.read(data); break;
        case 3: crud.update(data, loop); break;
        case 4: crud.d_elete(data); break;
        default: cout << "----- see you space, cowboy -----" << endl; exit(0); break;
    }
}
