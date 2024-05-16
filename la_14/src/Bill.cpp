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
    int counter = 0;
    ifstream read("bills.csv", ios::in);
    if(read.is_open())
    {
        while(getline(read, line))
        {
            stringstream bills(line);
            getline(bills, id, ',');
            if(id != "")
            {
                counter = stoi(id) + 1;
                billy = to_string(static_cast<int>(counter));;
            }
            else
            {
                billy = "1";
                break;
            }
        }
    }
    else
    {
        cout << "----- bills.csv error -----" << endl;
    }
}


string Bill::get_billy()
{
    return billy;
}


void Bill::set_amount()
{
    bought.Cloud::set_amount("- Amount to buy: ");
}


void Bill::set_subtotal(float current_total, float price, int amount)
{
    paypal.number = current_total + (price*amount);
    subtotal = to_string(paypal.number);
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
    paypal.number = cash-total;
    change = to_string(paypal.number);
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
                if(paypal.get_id() == id)
                {
                    customer_name = name;
                    data << bill.get_billy() << "," << id << "," << customer_name << ",";
                    break;
                }
            }
            customer_list.close();
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
                    if(stoi(bought.get_amount()) > stoi(amount) || stoi(bought.get_amount()) == 0)
                    {
                        cout << "----- invalid stock -----" << endl;
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
                                        earned = stoi(paypal.get_points());
                                        paypal.Cloud::set_date("- Purchase date: ");
                                        data << bill.get_subtotal() << "," << bill.get_cash() << "," << bill.get_change() << "," << earned << "," << paypal.get_date() << endl;
                                        paypal.update_points(paypal.get_id(), earned);
                                        cout << "----- purchase completed successfully -----" << endl << endl;
                                        bill.read("printed.txt", bill.get_billy(), true);
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


void Bill::read(string file, string searched, bool reset)
{
    if(reset)
    {
        print_line.str("");
    }
    ifstream invoices("bills.csv", ios::in);
    ifstream products("bought.csv", ios::in);
    ofstream print(file, ios::out);
    if(invoices.is_open() && products.is_open() && print.is_open())
    {
        print_line << setw(4) << "ID" << setw(16) << "NAME" << setw(16) << "PRICE" << setw(8) << "AMOUNT" << endl;
        while(getline(products, line))
        {
            stringstream item(line);
            getline(item, billy, ',');
            if(searched == billy)
            {
                getline(item, id,',');
                getline(item, name,',');
                getline(item, price,',');
                getline(item, amount,',');
                if(name.size() > 15)
                {
                    for(int i=0; i<15; i++)
                    {
                        chopped += name[i];
                    }
                    print_line << setw(4) << id << setw(16) << chopped << setw(17) << "$"+price << setw(7) << "x"+amount << endl;
                }
                else
                {
                    print_line << setw(4) << id << setw(16) << name << setw(17) << "$"+price << setw(7) << "x"+amount << endl;
                }
            }
        }
        while(getline(invoices, line))
        {
            stringstream bills(line);
            getline(bills, billy, ',');
            if(searched == billy)
            {
                getline(bills, id,',');
                getline(bills, name,',');
                getline(bills, subtotal,',');
                getline(bills, cash,',');
                getline(bills, change,',');
                getline(bills, points,',');
                getline(bills, date,',');
                print_line << "**** SUBTOTAL/TOTAL >>>> $" << subtotal << endl
                << "     CASH: $" << cash << endl
                << "     CHANGE: $" << change << endl
                << "--------------------------------------------" << endl
                << "PURCHASE DATE: " << date << endl
                << "DEAR CUSTOMER: " << name << " (" << id << ")" << endl
                << "EARNED POINTS: " << points << endl
                << "BILL ID: " << billy << endl
                << "********* THANKS FOR YOUR PURCHASE *********\n\n\n" << endl;
                break;
            }
        }
        cout << print_line.str();
        print << print_line.str();
        invoices.close();
        products.close();
        print.close();
    }
    else
    {
        cout << "----- bills.csv error -----" << endl;
    }
}


/*
void Bill::order()
{
    int position, current;
    for(int i=0; the_vector.size(); i++)
    {
        position = i;
        current = the_vector[i];
        while((position>0) && (the_vector[position-1] > current))
        {
            the_vector[position] = the_vector[position-1];
            position--;
        }

        the_vector[position] = current;
    }
    for(int i=0; the_vector.size(); i++)
    {
        cout << "nigger: " << the_vector[i] << endl;
    }
}
*/

void Bill::update(int loop)
{
    d_elete();
    system("cls");
    create(1);
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
                    cout << "----- bill #" << deleted << " deleted succesfully -----" << endl;
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


void Bill::sales_report(int the_beg, int the_end)
{
    string day, month, year;
    stringstream total;
    float income = 0;
    system("cls");
    ifstream invoices("bills.csv", ios::in);
    ofstream report("sales_report.txt", ios::app);
    if(invoices.is_open() && report.is_open())
    {
        if(the_beg == the_end)
        {
            total << "----- " << the_end << " -----" << endl;
        }
        else
        {
            total << "--------------- " << the_beg << " to " << the_end << " ---------------" << endl;
        }
        while(getline(invoices, line))
        {
            stringstream bills(line);
            getline(bills, billy, ',');
            getline(bills, id, ',');
            getline(bills, name, ',');
            getline(bills, subtotal, ',');
            getline(bills, cash, ',');
            getline(bills, change, ',');
            getline(bills, points, ',');
            getline(bills, date, ',');
            stringstream time;
            time << date;
            for(int i=0; i<3; i++)
            {
                getline(time, day, '/');
                getline(time, month, '/');
                getline(time, year, '/');
            }
            if(stoi(year) >= the_beg && stoi(year) <= the_end)
            {
                income += stof(subtotal);
                read("sales_report.txt", billy, false);
            }
        }
        total << "   ******** TOTAL INCOME: $" << income << " ********" << endl << endl;
        report << total.str();
        cout << total.str();
        invoices.close();
        report.close();
        print_line.str("");
    }
    else
    {
        cout << "----- sales_report.txt error -----" << endl;
    }
}


void Bill::products_report()
{
    stringstream data;
    ifstream products("products.csv", ios::in);
    ifstream invoices("bills.csv", ios::in);
    ofstream report("products_report.txt", ios::out);
    if(products.is_open() && invoices.is_open() && report.is_open())
    {
        data << "----- out of stock products -----" << endl;
        while(getline(products, line))
        {
            stringstream item(line);
            getline(item, id,',');
            getline(item, name,',');
            getline(item, price,',');
            getline(item, amount,',');
            if(amount == "0")
            {
                data << "- " << name << " (" << id << ")" << endl;
            }
        }
        report << data.str();
        cout << data.str();
        products.close();
        invoices.close();
        report.close();
    }
    else
    {
        cout << "----- products_report.txt error -----" << endl;
    }
}
