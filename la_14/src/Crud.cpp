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
    switch(data)
    {
        case 1: user.read(); break;
        case 2: merchandise.read(); break;
        case 3:
        {
            cout << "1. Read a bill" << endl;
            cout << "2. Sales report" << endl << endl;
            merchandise.Cloud::set_amount("Select your choice: ");
            switch(stoi(merchandise.get_amount()))
            {
                case 1:
                {
                    user.Cloud::set_id("- Bill ID: ");
                    user.set_exist(user.get_id(), "bills.csv");
                    if(user.get_exist())
                    {
                         sales.read(user.get_id(), 1);
                    }
                    else
                    {
                        user.not_founded(user.get_exist());
                    }
                }; break;
                case 2: sales.read("uwu", 2); break;
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
