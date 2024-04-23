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


void Product::set_price()
{
    set_number("- Price: $");
    price = number;
}


float Product::get_price()
{
    return price;
}


void Product::set_stock()
{
    set_number("- Stock amount: ");
    stock = number;
}


int Product::get_stock()
{
    return stock;
}


void Product::set_reduce(int stock_amount, int amount_bought)
{
    stock = stock_amount-amount_bought;
}


void Product::create(bool exist)
{
    product.set_name();
    product.set_productid();
    for(int p=0; p<products.size(); p++)
    {
        if(product.get_productid() == products[p].get_productid())
        {
            exist = true;
            cout << "----- product already exists -----" << endl;
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


void Product::read(bool exist)
{
    int product_number = 1;
    for(int p=0; p<products.size(); p++)
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
    not_founded(exist);
}


void Product::update(bool exist)
{
    product.set_productid();
    for(int a=0; a<products.size(); a++)
    {
        if(product.get_productid() == products[a].get_productid())
        {
            Product::old = product.get_name();
            product.set_name();
            product.set_productid();
            for(int b=0; b<products.size(); b++)
            {
                if((product.get_productid() == products[b].get_productid())
                    && (product.get_productid() != products[a].get_productid()))
                {
                    exist = true;
                    cout << "----- product already exists -----" << endl;
                    break;
                }
            }
            if(!exist)
            {
                product.set_price();
                product.set_stock();
                product.set_points();
                product.set_date();
                products[a] = product;
                cout << "----- product '" << Product::old << "' updated to '" << product.get_name() << "' -----" << endl;
            }
            exist = true;
            break;
        }
    }
    not_founded(exist);
}


void Product::d_elete(bool exist)
{
    product.set_productid();
    for(int p=0; p<products.size(); p++)
    {
        if(product.get_productid() == products[p].get_productid())
        {
            products.erase(products.begin()+p);
            cout << "----- product '" << products[p].get_name() << "' deleted succesfully -----" << endl;
            exist = true;
            break;
        }
    }
    not_founded(exist);
}
