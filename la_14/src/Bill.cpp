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

// function to define the next bill ID based on the last one created
void Bill::set_billy()
{
    int counter = 0;
    ifstream read("bills.csv", ios::in);
    if(read.is_open())
    {
        while(getline(read, line))
        {
            stringstream bills(line);
            getline(bills, bought.id, ',');
            if(bought.id != "")
            {
                counter = stoi(bought.id) + 1;
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
        bought.open_error("bills.csv");
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

// function to calculate the total of the bill
void Bill::set_subtotal(float current_total, float price, int amount)
{
    paypal.number = current_total + (price*amount); // add to the current subtotal the product of the price and the amount purchased
    subtotal = to_string(paypal.number);
}


string Bill::get_subtotal()
{
    return subtotal;
}

// function to enter the customer cash
void Bill::set_cash()
{
    paypal.set_number("- Cash: $");
    cash = to_string(paypal.get_number());
}


string Bill::get_cash()
{
    return cash;
}

// function to calculate the change of the purchase
void Bill::set_change(float cash, float total)
{
    paypal.number = cash-total; // subtract the cash the total to the subtotal of the purchase
    change = to_string(paypal.number);
}


string Bill::get_change()
{
    return change;
}

// function that print in a file the bills over a timelapse and calculate the income earned in that period
void Bill::sales_report(int the_beg, int the_end)
{
    string dd, mm, yyyy;
    float income = 0;
    stringstream total;
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
            getline(bills, bought.id, ',');
            getline(bills, bought.name, ',');
            getline(bills, subtotal, ',');
            getline(bills, cash, ',');
            getline(bills, change, ',');
            getline(bills, bought.points, ',');
            getline(bills, bought.date, ',');
            stringstream time;
            time << bought.date;
            for(int i=0; i<3; i++)
            {
                getline(time, dd, '/');
                getline(time, mm, '/');
                getline(time, yyyy, '/');
            }
            if(stoi(yyyy) >= the_beg && stoi(yyyy) <= the_end) // verify that the year is not out of the range
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
        print_line.str(""); // clean the stringstream
    }
    else
    {
        bought.open_error("sales_report.txt");
    }
}

// function that print in a file the out of stock products
void Bill::products_report()
{
    stringstream data;
    ifstream products("products.csv", ios::in);
    ifstream invoices("bills.csv", ios::in);
    ofstream report("products_report.txt", ios::out);
    if(products.is_open() && invoices.is_open() && report.is_open())
    {
        bought.exist = false;
        data << "----- out of stock -----" << endl;
        while(getline(products, line))
        {
            stringstream item(line);
            getline(item, bought.id,',');
            getline(item, bought.name,',');
            getline(item, bought.price,',');
            getline(item, bought.amount,',');
            if(bought.amount == "0")
            {
                data << "- ID: " << bought.id << " - " << bought.name << endl;
                bought.exist = true;
            }
        }
        if(!bought.exist)
        {
            data << "- None" << endl;
        }
        report << data.str(); // add the out of stock products to the products_report.csv
        cout << data.str(); // print the out of stock
        products.close();
        invoices.close();
        report.close();
        low_demand();
    }
    else
    {
        paypal.open_error("products_report.txt");
    }
}

// function that calculates the average of sells and write in the file the lower ones
void Bill::low_demand()
{
    int sold_amount=0;
    vector<string> sales;
    ifstream read("bought.csv", ios::in);
    ofstream report("products_report.txt", ios::app);
    if(read.is_open() && report.is_open())
    {
        while(getline(read, line))
        {
            stringstream item(line);
            getline(item, billy,',');
            getline(item, bought.id,',');
            getline(item, bought.name,',');
            getline(item, bought.price,',');
            getline(item, bought.amount,',');
            bought.set_exist(bought.id, "bought.csv");
            if(bought.get_exist())
            {
                selled = "- ID: " + bought.id + " - " + bought.name + "x" + bought.amount;
            }
            else
            {
                selled = "- ID: " + bought.id + " - " + bought.name + "x0"; // if the product is not in bought.csv, it's added to the vector with 0 amount
            }
            sales.push_back(selled);
        }
        for(int a=0; a<sales.size(); a++)
        {
            for(int b=a+1; b<sales.size(); b++)
            {
                stringstream one;
                one << sales[a];
                getline(one, bought.name, 'x');
                getline(one, bought.amount, 'x');
                stringstream two;
                two << sales[b];
                getline(two, paypal.name, 'x');
                getline(two, paypal.amount, 'x');
                if(bought.name == paypal.name)
                {
                    earned = stoi(bought.amount) + stoi(paypal.amount);
                    sold_amount += earned;
                    sales[a] = bought.name + "x" + to_string(static_cast<int>(earned));
                    sales.erase(sales.begin()+b);
                }
            }
        }
        average = sold_amount / sales.size();
        print_line << "\n----- low demand -----" << endl;
        for(int i=0; i<sales.size(); i++)
        {
            stringstream low;
            low << sales[i];
            getline(low, bought.name, 'x');
            getline(low, bought.amount, 'x');
            if(stoi(bought.amount) < average)
            {
                print_line << sales[i] << endl;
            }
        }
        report << print_line.str(); // add the low demand products to products_report.txt
        cout << print_line.str();
        read.close();
        report.close();
    }
    else
    {
        bought.open_error("products_report.txt");
    }
}

// function that ask for a customer ID and then ask for
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
                getline(customers, billy, ',');
                getline(customers, paypal.name, ',');
                if(paypal.get_id() == billy)
                {
                    client = paypal.name;
                    data << bill.get_billy() << "," << billy << "," << client << ",";
                    break;
                }
            }
            customer_list.close();
            while(loop == 1)
            {
                system("cls");
                cout << "Hi, " << client << "! What are you buying?" << endl;
                bought.set_id();
                bought.set_exist(bought.get_id(), "products.csv");
                if(bought.get_exist())
                {
                    while(getline(product_list, line))
                    {
                        stringstream products(line);
                        getline(products, billy, ',');
                        if(bought.get_id() == billy)
                        {
                            getline(products, bought.name, ',');
                            getline(products, bought.price, ',');
                            getline(products, bought.amount, ',');
                            getline(products, bought.points, ',');
                            break;
                        }
                    }
                    product_list.close();
                    bought.set_amount();
                    if(stoi(bought.get_amount()) > stoi(bought.amount) || stoi(bought.get_amount()) == 0) // verify that the amount is not higher than the product stock
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
                                getline(products, billy,',');
                                if(bought.get_id() == billy) // line to update
                                {
                                    getline(products, bought.name,',');
                                    getline(products, bought.price,',');
                                    getline(products, bought.amount,',');
                                    getline(products, bought.points,',');
                                    getline(products, bought.date,',');
                                    shopping_cart << bill.get_billy() << "," << bought.get_id() << ","
                                    << bought.name << "," << bought.price << "," << bought.get_amount() << endl; // add the product to the bought.csv file

                                    bill.set_subtotal(stof(bill.get_subtotal()), stof(bought.price), stoi(bought.get_amount())); // set the total to pay
                                    paypal.set_totalpoints(stoi(paypal.get_points()), stoi(bought.points), stoi(bought.get_amount())); // set the total points earned
                                    bought.reduce(stoi(bought.amount), stoi(bought.get_amount())); // set the stock - amount buyed

                                    reduced << billy << ","
                                    << bought.name << ","
                                    << bought.price << ","
                                    << bought.get_amount() << ","
                                    << bought.points << ","
                                    << bought.date << endl; // update the stock to the reduced one in the product
                                }
                                else // normal line
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
                            bought.open_error("products.csv");
                        }
                        cout << "Want to do add something else?" << endl; // ask to add another product/finish shopping
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
                                    if(stof(bill.get_change()) < 0) // verify the cash is not lower than the subtotal
                                    {
                                        cout << "----- not enough cash -----" << endl;
                                    }
                                    else
                                    {
                                        earned = stoi(paypal.get_points());
                                        paypal.Cloud::set_date("- Purchase date: ");

                                        data << bill.get_subtotal() << ","
                                        << bill.get_cash() << ","
                                        << bill.get_change() << ","
                                        << earned << ","
                                        << paypal.get_date() << endl; // add the data to bills.csv file

                                        paypal.update_points(paypal.get_id(), earned); // update the customer points to the increased ones
                                        bill.read("printed.txt", bill.get_billy(), true); // print the bill in the printed.txt file
                                        paypal.success(3, 2);
                                        break;
                                    }
                                }
                                loop = 0; // end the loop of the added products
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
            paypal.open_error("bills.csv");
        }
    }
    else
    {
        paypal.not_founded(paypal.get_exist());
    }
}

// function to read a bill and write it in a .txt file to print
void Bill::read(string file, string searched, bool reset)
{
    if(reset)
    {
        print_line.str(""); // clean the stringstream
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
                getline(item, bought.id, ',');
                getline(item, bought.name, ',');
                getline(item, bought.price, ',');
                getline(item, bought.amount, ',');
                if(bought.name.size() > 15)
                {
                    for(int i=0; i<15; i++) // if the name has more than 15 characters it will be cut off
                    {
                        chopped += bought.name[i];
                    }
                    print_line << setw(4) << bought.id << setw(16) << chopped << setw(17) << "$"+bought.price << setw(7) << "x"+bought.amount << endl;
                }
                else
                {
                    print_line << setw(4) << bought.id << setw(16) << bought.name << setw(17) << "$"+bought.price << setw(7) << "x"+bought.amount << endl;
                }
            }
        }
        while(getline(invoices, line))
        {
            stringstream bills(line);
            getline(bills, billy, ',');
            if(searched == billy)
            {
                getline(bills, bought.id,',');
                getline(bills, bought.name,',');
                getline(bills, subtotal,',');
                getline(bills, cash,',');
                getline(bills, change,',');
                getline(bills, bought.points,',');
                getline(bills, bought.date,',');
                print_line << "**** SUBTOTAL/TOTAL >>>> $" << subtotal << endl
                << "     CASH: $" << cash << endl
                << "     CHANGE: $" << change << endl
                << "--------------------------------------------" << endl
                << "PURCHASE DATE: " << bought.date << endl
                << "DEAR CUSTOMER: " << bought.name << " (" << bought.id << ")" << endl
                << "EARNED POINTS: " << bought.points << endl
                << "BILL ID: " << billy << endl
                << "********* THANKS FOR YOUR PURCHASE *********\n\n\n" << endl;
                break;
            }
        }
        cout << print_line.str();
        print << print_line.str(); // add the bill on the printed.txt file
        invoices.close();
        products.close();
        print.close();
    }
    else
    {
        paypal.open_error("bills.csv");
    }
}

// nothing here yet...
void Bill::update(int loop)
{
    cout << "----- under construction -----" << endl;
}

// function that ask for an id and calls the Cloud d_elete() to delete the bill/products of the bill
void Bill::d_elete()
{
    paypal.Cloud::set_id("- Bill ID: ");
    paypal.set_exist(paypal.get_id(), "bills.csv");
    if(paypal.get_exist())
    {
        paypal.Cloud::d_elete("bills.csv", paypal.get_id());
        paypal.Cloud::d_elete("bought.csv", paypal.get_id());
        paypal.success(3, 4);
    }
    else
    {
        paypal.not_founded(paypal.get_exist());
    }
}
