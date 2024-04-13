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
        crud_menu(data);
    }
    else
    {
        cout << "----- See you space, cowboy -----\n"; exit(0);
    }
}


void Menu::crud_menu(int data)
{
    system("cls");
    cout << "1. Create" << endl;
    cout << "2. Read" << endl;
    cout << "3. Update" << endl;
    cout << "4. Delete" << endl;
    cout << "\nSelect your choice: "; cin >> option;
    if(option==1)
    {
        create(data);
    }
    else if((option==2) || (option==3) || (option==4))
    {
        rudy(data, option);
    }
    else
    {
        cout << "----- See you space, cowboy -----\n"; exit(0);
    }
}
