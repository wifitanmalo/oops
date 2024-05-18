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

// function to enter the price of a product
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


// function to enter the amount of points for purchase
void Product::set_points()
{
    set_number("- Points: ");
    points = to_string(static_cast<int>(number));
}

// function to reduce an buyed amount of the total stock
void Product::reduce(int stock_amount, int amount_bought)
{
    number = stock_amount-amount_bought;
    amount = to_string(static_cast<int>(number));
}


void Product::set_date()
{
    Cloud::set_date("- Manufacturing date: ");
}

// function that ask for an id and verify that does not exist to create the product
void Product::create()
{
    product.set_id();
    product.set_exist(product.get_id(), "products.csv");
    if(product.get_exist())
    {
        cout << "----- product already exists -----" << endl;
    }
    else
    {
        ofstream create("products.csv", ios::app);
        if(create.is_open())
        {
            product.set_name();
            product.set_price();
            product.set_amount();
            product.set_points();
            product.set_date();
            create << product.get_id() << "," << product.get_name() << "," << product.get_price() << ","
            << product.get_amount() << "," << product.get_points() << "," << product.get_date() << endl;
            succes(2, 1, product.get_name());
        }
        else
        {
            open_error("products.csv");
        }
    }
}

// function to print the products list
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
        open_error("products.csv");
    }

}

// function that ask for an id and verify that does not exist or it's the same to update the product
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
                    product.set_id();
                    product.set_exist(product.get_id(), "products.csv");
                    if(product.get_exist() && product.get_id() != id)
                    {
                        updated << line << endl;
                        cout << "----- product already exists -----" << endl;
                    }
                    else
                    {
                        product.set_name();
                        product.set_price();
                        product.set_amount();
                        product.set_points();
                        product.set_date();
                        updated << product.get_id() << "," << product.get_name() << "," << product.get_price() << ","
                        << product.get_amount() << "," << product.get_points() << "," << product.get_date() << endl;
                        succes(2, 3, product.get_name());
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
            open_error("products.csv");
        }
    }
    else
    {
        not_founded(product.get_exist());
    }
}

// function that ask for an ID and calls the Cloud d_elete() to delete the product
void Product::d_elete()
{
    product.set_id();
    product.set_exist(product.get_id(), "products.csv");
    if(product.get_exist())
    {
        Cloud::d_elete("products.csv", product.get_id());
        succes(2, 4, deleted);
    }
    else
    {
        not_founded(product.get_exist());
    }
}
