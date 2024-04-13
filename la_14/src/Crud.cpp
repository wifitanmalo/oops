#include "Crud.h"

Customer customer;
Product product;
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


void Crud::create(int data)
{
    if(data == 1) // create a CUSTOMER --------------------------------------------------------------------------------
    {
        customer.set_name();
        customer.set_customerid();
        for(int c=0; c<customers.size(); c++)
        {
            if(customer.get_customerid() == customers[c].get_customerid())
            {
                cout << "----- customer already exists -----" << endl;
                exist = true;
                break;
            }
        }
        if(!exist)
        {
            customer.set_date();
            customer.set_increasepoints(0, 0);
            customers.push_back(customer);
            cout << "----- customer '" << customer.get_name() << "' created succesfully -----" << endl;
        }
    }
    else if(data == 2) // create a PRODUCT --------------------------------------------------------------------------------
    {
        product.set_name();
        product.set_productid();
        for(int p=0; p<products.size(); p++)
        {
            if(product.get_productid() == products[p].get_productid())
            {
                cout << "----- product already exists -----" << endl;
                exist = true;
                break;
            }
        }
        if(!exist)
        {
            product.set_price();
            product.set_stock();
            product.set_points();
            product.set_date();
            products.push_back(product);
            cout << "----- product '" << product.get_name() << "' created succesfully -----" << endl;
        }
    }
    else if(data == 3) // create a BILL --------------------------------------------------------------------------------
    {
        bill.set_customerid();
        for(int c=0; c<customers.size(); c++)
        {
            if(bill.get_customerid() == customers[c].get_customerid())
            {
                bill.set_billy();
                bought.set_billy();
                bill.set_total(0, 0, 0);
                bill.set_totalpoints(0, 0, 0);
                while(loop == 1)
                {
                    system("cls");
                    cout << "Hi, " << customers[c].get_name() << "! What you wanna buy?" << endl;
                    bought.set_productid();
                    for(int p=0; p<products.size(); p++)
                    {
                        if(bought.get_productid() == products[p].get_productid())
                        {
                            bought.set_amount();
                            if(bought.get_amount() > products[p].get_stock())
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
                                products[p].set_reduce(products[p].get_stock(), bought.get_amount());
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
    }
    loop = 1;
    exist = false;
}


void Crud::rudy(int data, int option)
{
    system("cls");
    if(data == 1) // customer --------------------------------------------------------------------------------
    {
        customer.set_customerid();
        for(int c=0; c<customers.size(); c++)
        {
            if(customer.get_customerid() == customers[c].get_customerid())
            {
                exist = true;
                if(option == 2) // read
                {
                    cout << "NAME: " << customers[c].get_name() << endl;
                    cout << "BIRTHDAY: " << customers[c].get_date() << endl;
                    cout << "ACCUMULATED POINTS: " << customers[c].get_points() << endl;
                }
                else if(option == 3) // update
                {
                    old = customer.get_name();
                    customer.set_name();
                    customer.set_customerid();
                    customer.set_date();
                    customer.set_increasepoints(customers[c].get_points(), 0);
                    customers[c] = customer;
                    cout << "----- customer '" << old << "' updated to '" << customer.get_name() << "' -----" << endl;
                }
                else if(option == 4) // delete
                {
                    deleted = customers[c].get_name();
                    customers.erase(customers.begin()+c);
                    cout << "----- customer '" << deleted << "' deleted succesfully -----" << endl;
                }
                break;
            }
        }
    }
    else if(data == 2) // products --------------------------------------------------------------------------------
    {
        int product_number = 1;
        for(int p=0; p<products.size(); p++)
        {
            if(option==2) // products list
            {
                exist = true;
                cout <<  "---" << product_number++ << "---" << endl;
                cout << "NAME: " << products[p].get_name()<< endl;
                cout << "ID: " <<products[p].get_productid()<< endl;
                cout << "PRICE: $" << products[p].get_price()<< endl;
                cout << "STOCK AMOUNT: " << products[p].get_stock()<< endl;
                cout << "PURCHASE POINTS: " << products[p].get_points()<< endl;
                cout << "EXPIRATION DATE: " << products[p].get_date() << endl << endl;
            }
            else
            {
                product.set_productid();
                if(product.get_productid() == products[p].get_productid())
                {
                    exist = true;
                    if(option == 3) // update
                    {
                        old = product.get_name();
                        product.set_name();
                        product.set_productid();
                        product.set_price();
                        product.set_stock();
                        product.set_points();
                        product.set_date();
                        products[p] = product;
                        cout << "----- product '" << old << "' updated to '" << product.get_name() << "' -----" << endl;
                    }
                    else if(option == 4) // delete
                    {
                        deleted = product.get_name();
                        products.erase(products.begin()+p);
                        cout << "----- product '" << deleted << "' deleted succesfully -----" << endl;
                    }
                    break;
                }
            }
        }
    }
    else if(data == 3) // bill --------------------------------------------------------------------------------
    {
        bill.set_number("- Bill ID: ");
        for(int b=0; b<bills.size(); b++)
        {
            if(bill.get_number() == bills[b].get_billy())
            {
                if(option == 2) // read
                {
                    for(int p=0; p<products.size(); p++)
                    {
                        for(int bp=0; bp<bought_products.size(); bp++)
                        {
                            if((bought_products[bp].get_billy() == bills[b].get_billy())
                                && (bought_products[bp].get_productid() == products[p].get_productid()))
                            {
                                cout << bought_products[bp].get_productid() << " / " << products[p].get_name() << " / $" << products[p].get_price() << "x" << bought_products[bp].get_amount() << endl;
                            }
                        }
                    }
                    for(int c=0; c<customers.size(); c++)
                    {
                        if(customers[c].get_customerid() == bills[b].get_customerid())
                        {
                            cout << "**** SUBTOTAL/TOTAL >>>> $" << bills[b].get_total() << endl;
                            cout << "     CASH: $" << bills[b].get_cash() << endl;
                            cout << "     CHANGE: $" << bills[b].get_change() << endl;
                            cout << "------------------------------------" << endl;
                            cout << "PURCHASE DATE: " << bills[b].get_date() << endl;
                            cout << "DEAR CUSTOMER: " << customers[c].get_name() << " (" << bills[b].get_customerid() << ")" << endl;
                            cout << "EARNED POINTS: " << bills[b].get_points() << endl;
                            cout << "***** THANKS FOR YOUR PURCHASE *****" << endl;
                            exist = true;
                            break;
                        }
                    }
                }
                else if(option == 3) // update
                {
                    bill.set_customerid();
                    for(int c=0; c<customers.size(); c++)
                    {
                        if(bill.get_customerid() == customers[c].get_customerid())
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
                                cout << "Hi, " << customers[c].get_name() << "! What you wanna buy?" << endl;
                                bought.set_productid();
                                for(int p=0; p<products.size(); p++)
                                {
                                    if(bought.get_productid() == products[p].get_productid())
                                    {
                                        bought.set_amount();
                                        if(bought.get_amount() > products[p].get_stock())
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
                                            products[p].set_reduce(products[p].get_stock(), bought.get_amount());
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
                }
                else if(option == 4) // delete
                {
                    int deleted = bill.get_number();
                    bills.erase(bills.begin()+b);
                    cout << "----- bill #" << deleted << " deleted succesfully -----" << endl;
                    exist = true;
                }
                break;
            }
        }
    }
    if(!exist)
    {
        cout << "----- not founded -----" << endl;
    }
    loop = 1;
    exist = false;
}
