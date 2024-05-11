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
    price = number;
}


float Product::get_price()
{
    return price;
}


void Product::set_amount()
{
    Cloud::set_amount("- Stock amount: ");
}


void Product::set_date()
{
    Cloud::set_date("- Expiration date: ");
}


void Product::create(bool exist)
{
    product.set_name();
    product.set_id();
    /*
    for(int p=0; p<products.size(); p++)
    {
        if(product.get_id() == products[p].get_id())
        {
            exist = true;
            cout << "----- product already exists -----" << endl;
            break;
        }
    }
    if(!exist)
    {
        product.set_price();
        product.set_amount();
        product.set_points();
        product.set_date();
        products.push_back(product);
        cout << "----- product '" << product.get_name() << "' created succesfully -----" << endl;
    }
    */
}


void Product::read(bool exist)
{
    /*
    int product_number = 1;
    for(int p=0; p<products.size(); p++)
    {
        exist = true;
        cout <<  "---" << product_number++ << "---" << endl;
        cout << "NAME: " << products[p].get_name()<< endl;
        cout << "ID: " <<products[p].get_id()<< endl;
        cout << "PRICE: $" << products[p].get_price()<< endl;
        cout << "STOCK AMOUNT: " << products[p].get_amount()<< endl;
        cout << "PURCHASE POINTS: " << products[p].get_points()<< endl;
        cout << "EXPIRATION DATE: " << products[p].get_date() << endl << endl;
    }
    not_founded(exist);
    */
}


void Product::update(bool exist)
{
    product.set_id();
    /*
    for(int a=0; a<products.size(); a++)
    {
        if(product.get_id() == products[a].get_id())
        {
            Product::old = product.get_name();
            product.set_name();
            product.set_id();
            for(int b=0; b<products.size(); b++)
            {
                if((product.get_id() == products[b].get_id())
                    && (product.get_id() != products[a].get_id()))
                {
                    exist = true;
                    cout << "----- product already exists -----" << endl;
                    break;
                }
            }
            if(!exist)
            {
                product.set_price();
                product.set_amount();
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
    */
}


void Product::d_elete(bool exist)
{
    product.set_id();
    /*
    for(int p=0; p<products.size(); p++)
    {
        if(product.get_id() == products[p].get_id())
        {
            products.erase(products.begin()+p);
            cout << "----- product '" << products[p].get_name() << "' deleted succesfully -----" << endl;
            exist = true;
            break;
        }
    }
    not_founded(exist);
    */
}
