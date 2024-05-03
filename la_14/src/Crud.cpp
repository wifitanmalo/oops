#include "Crud.h"


Bill bill;
Bill bought;


Crud::Crud()
{
    //ctor
}


Crud::~Crud()
{
    //dtor
}


void Crud::create(int data, int loop, bool exist)
{
    switch(data)
    {
        case 1: Customer::create(exist); break;
        case 2: Product::create(exist); break;
        case 3:
        {
            bill.set_id();
            for(int c=0; c<customers.size(); c++)
            {
                if(bill.get_id() == customers[c].get_id())
                {
                    bill.set_billy();
                    bought.set_billy();
                    bill.set_total(0, 0, 0);
                    bill.set_totalpoints(0, 0, 0);
                    while(loop == 1)
                    {
                        system("cls");
                        exist = false;
                        cout << "Hi, " << customers[c].get_name() << "! What you wanna buy?" << endl;
                        bought.set_id();
                        for(int p=0; p<products.size(); p++)
                        {
                            if(bought.get_id() == products[p].get_id())
                            {
                                bought.set_amount();
                                if(bought.get_amount() > products[p].get_amount())
                                {
                                    cout << "----- exceeds stock -----" << endl;
                                }
                                else
                                {
                                    system("cls");
                                    bought.set_productnumber(1, bought.get_productnumber());
                                    bill.set_productnumber(1, bought.get_productnumber());
                                    bill.set_total(bill.get_total(), products[p].get_price(), bought.get_amount());
                                    bill.set_totalpoints(bill.get_points(), products[p].get_points(), bought.get_amount());
                                    products[p].stock_reduce(products[p].get_amount(), bought.get_amount());
                                    bought_products.push_back(bought);
                                    cout << "Want to do add something else?" << endl;
                                    cout << "1. Yes" << endl;
                                    cout << "0. No" << endl << endl;
                                    cout << "Select your choice: "; cin >> option;
                                    switch(option)
                                    {
                                        case 1: break;
                                        default:
                                        {
                                            while(true)
                                            {
                                                bill.set_cash();
                                                bill.set_change(bill.get_cash(), bill.get_total());
                                                if(bill.get_change() < 0)
                                                {
                                                    cout << "----- not enough cash -----" << endl;
                                                }
                                                else
                                                {
                                                    bill.set_date();
                                                    bill.set_increasepoints(0, bill.get_points());
                                                    customers[c].set_increasepoints(customers[c].get_points(), bill.get_points());
                                                    bills.push_back(bill);
                                                    cout << "- Bill ID: " << bill.get_billy() << endl;
                                                    cout << "----- purchase completed successfully -----" << endl;
                                                    break;
                                                }
                                            }
                                            loop = 0;
                                        }; break;
                                    }
                                }
                                exist = true;
                                break;
                            }
                        }
                        if(!exist)
                        {
                            cout << "----- not founded -----" << endl;
                            system("pause");
                        }
                    }
                    break;
                }
            }
            if(!exist)
            {
                cout << "----- not founded -----" << endl;
            }
        }; break;
    }
}


void Crud::read(int data, int loop, bool exist)
{
    switch(data)
    {
        case 1: Customer::read(exist); break;
        case 2: Product::read(exist); break;
        case 3:
        {
            bill.set_number("- Bill ID: ");
            for(int b=0; b<bills.size(); b++)
            {
                if(bill.get_number() == bills[b].get_billy())
                {
                    for(int p=0; p<products.size(); p++)
                    {
                        for(int bp=0; bp<bought_products.size(); bp++)
                        {
                            if((bought_products[bp].get_billy() == bills[b].get_billy())
                                && (bought_products[bp].get_id() == products[p].get_id()))
                            {
                                cout << bought_products[bp].get_id() << " / " << products[p].get_name() << " / $" << products[p].get_price() << "x" << bought_products[bp].get_amount() << endl;
                            }
                        }
                    }
                    for(int c=0; c<customers.size(); c++)
                    {
                        if(customers[c].get_id() == bills[b].get_id())
                        {
                            exist = true;
                            cout << "**** SUBTOTAL/TOTAL >>>> $" << bills[b].get_total() << endl;
                            cout << "     CASH: $" << bills[b].get_cash() << endl;
                            cout << "     CHANGE: $" << bills[b].get_change() << endl;
                            cout << "------------------------------------" << endl;
                            cout << "PURCHASE DATE: " << bills[b].get_date() << endl;
                            cout << "DEAR CUSTOMER: " << customers[c].get_name() << " (" << bills[b].get_id() << ")" << endl;
                            cout << "EARNED POINTS: " << bills[b].get_points() << endl;
                            cout << "***** THANKS FOR YOUR PURCHASE *****" << endl;
                            break;
                        }
                    }
                    break;
                }
            }
        }; break;
    }
}


void Crud::update(int data, int loop, bool exist)
{
    switch(data)
    {
        case 1: Customer::update(exist); break;
        case 2: Product::update(exist); break;
        case 3:
        {
            bill.set_number("- Bill ID: ");
            for(int b=0; b<bills.size(); b++)
            {
                if(bill.get_number() == bills[b].get_billy())
                {
                    bill.set_id();
                    for(int c=0; c<customers.size(); c++)
                    {
                        if(bill.get_id() == customers[c].get_id())
                        {
                            bill.set_total(0, 0, 0);
                            bill.set_totalpoints(0, 0, 0);
                            for(int l=0; l<bills[b].get_productnumber(); l++)
                            {
                                for(int d=0; d<bought_products.size(); d++)
                                {
                                    if(bought_products[d].get_billy() == bills[b].get_billy())
                                    {
                                        bought_products.erase(bought_products.begin()+d);
                                    }
                                }
                            }
                            while(loop == 1)
                            {
                                system("cls");
                                exist = false;
                                cout << "Hi, " << customers[c].get_name() << "! What you wanna buy?" << endl;
                                bought.set_id();
                                for(int p=0; p<products.size(); p++)
                                {
                                    if(bought.get_id() == products[p].get_id())
                                    {
                                        bought.set_amount();
                                        if(bought.get_amount() > products[p].get_amount())
                                        {
                                            cout << "----- exceeds stock -----" << endl;
                                        }
                                        else
                                        {
                                            system("cls");
                                            bought.set_productnumber(1, bought.get_productnumber());
                                            bill.set_productnumber(1, bought.get_productnumber());
                                            bill.set_total(bill.get_total(), products[p].get_price(), bought.get_amount());
                                            bill.set_totalpoints(bill.get_points(), products[p].get_points(), bought.get_amount());
                                            products[p].stock_reduce(products[p].get_amount(), bought.get_amount());
                                            bought_products.push_back(bought);
                                            cout << "Want to do add something else?" << endl;
                                            cout << "1. Yes" << endl;
                                            cout << "0. No" << endl << endl;
                                            cout << "Select your choice: "; cin >> option;
                                            switch(option)
                                            {
                                                case 1: break;
                                                default:
                                                {
                                                    while(true)
                                                    {
                                                        bill.set_cash();
                                                        bill.set_change(bill.get_cash(), bill.get_total());
                                                        if(bill.get_change() < 0)
                                                        {
                                                            cout << "----- not enough cash -----" << endl;
                                                        }
                                                        else
                                                        {
                                                            bill.set_date();
                                                            bill.set_increasepoints(0, bill.get_points());
                                                            customers[c].set_increasepoints(customers[c].get_points(), bill.get_points());
                                                            bills[b] = bill;
                                                            cout << "----- bill " << bill.get_billy() << "updated successfully -----" << endl;
                                                            break;
                                                        }
                                                    }
                                                    loop = 0;
                                                }; break;
                                            }
                                        }
                                        exist = true;
                                        break;
                                    }
                                }
                                if(!exist)
                                {
                                    cout << "----- not founded -----" << endl;
                                    system("pause");
                                }
                            }
                            break;
                        }
                    }
                    break;
                }
            }
        }; break;
    }
}


void Crud::d_elete(int data, int loop, bool exist)
{
    switch(data)
    {
        case 1: Customer::d_elete(exist); break;
        case 2: Product::d_elete(exist); break;
        case 3:
        {
            bill.set_number("- Bill ID");
            for(int b=0; b<bills.size(); b++)
            {
                if(bill.get_number() == bills[b].get_billy())
                {
                    int deleted = bill.get_number();
                    bills.erase(bills.begin()+b);
                    cout << "----- bill #" << deleted << " deleted succesfully -----" << endl;
                    exist = true;
                    break;
                }
            }
        }; break;
    }
}
