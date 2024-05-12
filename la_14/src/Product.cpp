#include "Product.h"


Product product;


Product::Product()
{
    //ctor
}

Product::~Product()
{
    //dtor
}


void Product::set_name()
{
    Cloud::set_name("- Product name: ");
}


void Product::set_id()
{
    Cloud::set_id("- Product ID: ");
}



void Product::set_price()
{
    set_number("- Price: $");
    price = to_string(number);
}


string Product::get_price()
{
    return price;
}


void Product::set_amount()
{
    Cloud::set_amount("- Stock amount: ");
}


void Product::reduce(int stock_amount, int amount_bought)
{
    number = stock_amount-amount_bought;
    amount = to_string(static_cast<int>(number));
}


void Product::set_date()
{
    Cloud::set_date("- Manufacturing date: ");
}


void Product::create()
{
    product.set_name();
    product.set_id();
    product.set_exist(product.get_id(), "products.csv");
    if(product.get_exist())
    {
        cout << "----- product already exists -----" << endl;
    }
    else
    {
        ofstream file("products.csv", ios::app);
        if (file.is_open())
        {
            product.set_price();
            product.set_amount();
            product.set_points();
            product.set_date();
            file << product.get_id() << "," << product.get_name() << "," << product.get_price() << ","
            << product.get_amount() << "," << product.get_points() << "," << product.get_date() << endl;
            cout << "----- product '" << product.get_name() << "' created succesfully -----" << endl;
        }
        else
        {
            cout << "----- products.csv error -----" << endl;
        }
    }
}


void Product::read()
{
    int product_number = 1;
    ifstream read("products.csv", ios::in);
    if(read.is_open())
    {
        while(getline(read, line))
        {
            stringstream products(line);
            getline(products, id,',');
            getline(products, name,',');
            getline(products, price,',');
            getline(products, amount,',');
            getline(products, points,',');
            getline(products, date,',');
            cout <<  "---" << product_number++ << "---" << endl;
            cout << "NAME: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "PRICE: $" << price << endl;
            cout << "STOCK AMOUNT: " << amount << endl;
            cout << "PURCHASE POINTS: " << points << endl;
            cout << "MANUFACTURING DATE: " << date << endl << endl;
        }
        read.close();
    }
    else
    {
        cout << "----- products.csv error -----" << endl;
    }
}


void Product::update()
{
    product.set_id();
    product.set_exist(product.get_id(), "products.csv");
    if(product.get_exist())
    {
        ifstream original("products.csv");
        ofstream updated("updated.csv");
        if(original.is_open() && updated.is_open())
        {
            while(getline(original, line))
            {
                stringstream products(line);
                getline(products, id,',');
                getline(products, name,',');
                getline(products, price,',');
                getline(products, amount,',');
                getline(products, points,',');
                getline(products, date,',');
                if(product.get_id() == id)
                {
                    old = name;
                    product.set_name();
                    product.set_id();
                    product.set_exist(product.get_id(), "products.csv");
                    if(product.get_exist() && product.get_id() != id)
                    {
                        updated << line << endl;
                        cout << "----- product already exists -----" << endl;
                    }
                    else
                    {
                        product.set_price();
                        product.set_amount();
                        product.set_points();
                        product.set_date();
                        updated << product.get_id() << "," << product.get_name() << "," << product.get_price() << ","
                        << product.get_amount() << "," << product.get_points() << "," << product.get_date() << endl;
                        cout << "----- product '" << old << "' updated to '" << product.get_name() << "' -----" << endl;
                    }
                }
                else
                {
                    updated << line << endl;
                }
            }
            original.close();
            updated.close();
            remove("products.csv");
            rename("updated.csv", "products.csv");
        }
        else
        {
            cout << "----- products.csv error -----" << endl;
        }
    }
    else
    {
        not_founded(product.get_exist());
    }
}


void Product::d_elete()
{
    product.set_id();
    product.set_exist(product.get_id(), "products.csv");
    if(product.get_exist())
    {
        ifstream original("products.csv");
        ofstream updated("updated.csv");
        if(original.is_open() && updated.is_open())
        {
            while(getline(original, line))
            {
                stringstream products(line);
                getline(products, id, ',');
                getline(products, name, ',');
                if(product.get_id() == id)
                {
                    deleted = name;
                }
                else
                {
                    updated << line << endl;
                }
            }
            original.close();
            updated.close();
            remove("products.csv");
            rename("updated.csv", "products.csv");
            cout << "----- product '" << deleted << "' deleted succesfully -----" << endl;
        }
        else
        {
            cout << "----- products.csv error -----" << endl;
        }
    }
    else
    {
        not_founded(product.get_exist());
    }
}
