#include "Bill.h"


Bill bill;


Bill::Bill()
{
    //ctor
}


Bill::~Bill()
{
    //dtor
}


void Bill::set_billy()
{
    billy++;
}


int Bill::get_billy()
{
    return billy;
}


void Bill::set_amount()
{
    bought.Cloud::set_amount("- Amount to buy: ");
}


void Bill::set_subtotal(float current_total, float price, int amount)
{
    number = current_total + (price*amount);
    subtotal = to_string(number);
}


string Bill::get_subtotal()
{
    return subtotal;
}


void Bill::set_cash()
{
    paypal.set_number("- Cash: $");
    cash = to_string(paypal.get_number());
}


string Bill::get_cash()
{
    return cash;
}


void Bill::set_change(float cash, float total)
{
    number = cash-total;
    change = to_string(number);
}


string Bill::get_change()
{
    return change;
}


void Bill::create(int loop)
{
    paypal.set_id();
    paypal.set_exist(paypal.get_id(), "customers.csv");
    if(paypal.get_exist())
    {
        bill.set_billy();
        bill.set_subtotal(0, 0, 0);
        paypal.set_totalpoints(0, 0, 0);
        ofstream data("bills.csv", ios::app);
        ofstream shopping_cart("bought.csv", ios::app);
        ifstream customer_list("customers.csv");
        ifstream product_list("products.csv");
        if(data.is_open()
           && shopping_cart.is_open()
           && customer_list.is_open()
           && product_list.is_open())
        {
            while(getline(customer_list, line))
            {
                stringstream customers(line);
                getline(customers, id, ',');
                getline(customers, name, ',');
                getline(customers, deleted, ',');
                getline(customers, points, ',');
                if(paypal.get_id() == id)
                {
                    customer_name = name;
                    current = points;
                    data << bill.get_billy() << "," << id << "," << customer_name << ",";
                    break;
                }
            }
            while(loop == 1)
            {
                system("cls");
                cout << "Hi, " << customer_name << "! What you wanna buy?" << endl;
                bought.set_id();
                bought.set_exist(bought.get_id(), "products.csv");
                if(bought.get_exist())
                {
                    while(getline(product_list, line))
                    {
                        stringstream products(line);
                        getline(products, id,',');
                        if(bought.get_id() == id)
                        {
                            getline(products, name,',');
                            getline(products, price,',');
                            getline(products, amount,',');
                            getline(products, points,',');
                            break;
                        }
                    }
                    product_list.close();


                    bought.set_amount();
                    if(stoi(bought.get_amount()) > stoi(amount))
                    {
                        cout << "----- exceeds stock -----" << endl;
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        ifstream original("products.csv");
                        ofstream reduced("reduced.csv");
                        if(original.is_open() && reduced.is_open())
                        {
                            while(getline(original, line))
                            {
                                stringstream products(line);
                                getline(products, id,',');
                                if(bought.get_id() == id)
                                {
                                    getline(products, name,',');
                                    getline(products, price,',');
                                    getline(products, amount,',');
                                    getline(products, points,',');
                                    getline(products, deleted,',');
                                    shopping_cart << bill.get_billy() << "," << bought.get_id() << ","
                                    << name << "," << price << "," << bought.get_amount() << endl;
                                    bill.set_subtotal(stof(bill.get_subtotal()), stof(price), stoi(bought.get_amount()));
                                    paypal.set_totalpoints(stoi(paypal.get_points()), stoi(points), stoi(bought.get_amount()));
                                    bought.reduce(stoi(amount), stoi(bought.get_amount()));
                                    reduced << id << "," << name << "," << price << ","
                                    << bought.get_amount() << "," << points << "," << deleted << endl;
                                }
                                else
                                {
                                    reduced << line << endl;
                                }
                            }
                            original.close();
                            reduced.close();
                            remove("products.csv");
                            rename("reduced.csv", "products.csv");
                        }
                        else
                        {
                            cout << "----- products.csv error -----" << endl;
                        }
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
                                    bill.set_change(stof(bill.get_cash()), stof(bill.get_subtotal()));
                                    if(stof(bill.get_change()) < 0)
                                    {
                                        cout << "----- not enough cash -----" << endl;
                                    }
                                    else
                                    {
                                        paypal.Cloud::set_date("- Purchase date: ");
                                        // paypal.set_increasepoints(stoi(current), stoi(paypal.get_points()));
                                        cout << "- Bill ID: " << bill.get_billy() << endl;
                                        cout << "----- purchase completed successfully -----" << endl;
                                        break;
                                    }
                                }
                                loop = 0;
                            }; break;
                        }
                    }
                }
                else
                {
                    paypal.not_founded(bought.get_exist());
                    system("pause");
                }
            }
            data << bill.get_subtotal() << "," << bill.get_cash() << "," << bill.get_change() << "," << paypal.get_points() << endl;
            customer_list.close();
        }
        else
        {
            cout << "----- bills.csv error -----" << endl;
        }
    }
    else
    {
        paypal.not_founded(paypal.get_exist());
    }
}


void Bill::read()
{
    /*
    cout << "**** SUBTOTAL/TOTAL >>>> $" << bills[b].get_total() << endl;
    cout << "     CASH: $" << bills[b].get_cash() << endl;
    cout << "     CHANGE: $" << bills[b].get_change() << endl;
    cout << "------------------------------------" << endl;
    cout << "PURCHASE DATE: " << bills[b].get_date() << endl;
    cout << "DEAR CUSTOMER: " << customers[c].get_name() << " (" << bills[b].get_id() << ")" << endl;
    cout << "EARNED POINTS: " << bills[b].get_points() << endl;
    cout << "***** THANKS FOR YOUR PURCHASE *****" << endl;
    break;
    */
}


void Bill::update(int loop)
{
    /*
    for(int b=0; b<bills.size(); b++)
    {
        if(bill.get_id() == bills[b].get_billy())
        {
            bill.set_id("- Customer ID: ");
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
                        bill.set_id("- Product ID: ");
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
    */
}


void Bill::d_elete()
{
    string file;
    paypal.set_id();
    paypal.set_exist(paypal.get_id(), "bills.csv");
    if(paypal.get_exist())
    {
        for(int loop=0; loop<2; loop++)
        {
            switch(loop)
            {
                case 0: file = "bills.csv"; break;
                case 1: file = "bought.csv"; break;
            }
            ifstream original(file);
            ofstream updated("updated.csv");
            if(original.is_open() && updated.is_open())
            {
                while(getline(original, line))
                {
                    stringstream bills(line);
                    getline(bills, id, ',');
                    if(paypal.get_id() == id)
                    {
                        deleted = id;
                    }
                    else
                    {
                        updated << line << endl;
                    }
                }
                original.close();
                updated.close();
                if(loop == 0)
                {
                    remove("bills.csv");
                    rename("updated.csv", "bills.csv");
                }
                else
                {
                    remove("bought.csv");
                    rename("updated.csv", "bought.csv");
                    cout << "----- bill #" << deleted << "' deleted succesfully -----" << endl;
                }
            }
            else
            {
                cout << "----- bills.csv error -----" << endl;
            }
        }
    }
    else
    {
        paypal.not_founded(paypal.get_exist());
    }
}
