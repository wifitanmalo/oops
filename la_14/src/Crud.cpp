#include "Crud.h"


Crud::Crud()
{
    //ctor
}


Crud::~Crud()
{
    //dtor
}


void Crud::create(int data, int loop)
{
    switch(data)
    {
        case 1: user.create(); break;
        case 2: merchandise.create(); break;
        case 3: sales.create(loop); break;
    }
}


void Crud::read(int data)
{
    int the_beg, the_end;
    switch(data)
    {
        case 1: user.read(); break;
        case 2: merchandise.read(); break;
        case 3:
        {
            cout << "1. Read a bill" << endl;
            cout << "2. Sales report" << endl;
            cout << "3. Products report" << endl << endl;
            merchandise.Cloud::set_amount("Select your choice: ");
            system("cls");
            switch(stoi(merchandise.get_amount()))
            {
                case 1:
                {
                    user.Cloud::set_id("- Bill ID: ");
                    user.set_exist(user.get_id(), "bills.csv");
                    if(user.get_exist())
                    {
                         sales.read("printed.txt", user.get_id(), true);
                    }
                    else
                    {
                        user.not_founded(user.get_exist());
                    }
                }; break;
                case 2:
                {
                    user.Cloud::set_amount("- Start year: ");
                    the_beg = stoi(user.get_amount());
                    user.Cloud::set_amount("- End year: ");
                    the_end = stoi(user.get_amount());
                    if(the_beg > the_end)
                    {
                        sales.sales_report(the_end, the_beg);
                    }
                    else
                    {
                        sales.sales_report(the_beg, the_end);
                    }
                }; break;
                case 3: sales.products_report(); break;
                default: cout << "----- invalid option -----" << endl; break;
            }
        }; break;
    }
}


void Crud::update(int data, int loop)
{
    switch(data)
    {
        case 1: user.update(); break;
        case 2: merchandise.update(); break;
        case 3: sales.update(loop); break;
    }
}


void Crud::d_elete(int data)
{
    switch(data)
    {
        case 1: user.d_elete(); break;
        case 2: merchandise.d_elete(); break;
        case 3: sales.d_elete(); break;
    }
}
