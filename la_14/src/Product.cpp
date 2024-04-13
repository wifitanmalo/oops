#include "Product.h"


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
