#include "Bill.h"


Bill::Bill()
{
    //ctor
}


Bill::~Bill()
{
    //dtor
}


void Bill::set_amount()
{
    set_number("- Amount to buy: ");
    amount = number;
}


int Bill::get_amount()
{
    return amount;
}


void Bill::set_productnumber(int number, int current)
{
    product_number = number+current;
}


int Bill::get_productnumber()
{
    return product_number;
}


void Bill::set_total(float current_total, float price, int amount)
{
    total = current_total + (price*amount);
}


float Bill::get_total()
{
    return total;
}


void Bill::set_cash()
{
    set_number("- Cash: $");
    cash = number;
}


float Bill::get_cash()
{
    return cash;
}


void Bill::set_change(float cash, float total)
{
    change = cash-total;
}


float Bill::get_change()
{
    return change;
}


void Bill::set_billy()
{
    billy++;
}


int Bill::get_billy()
{
    return billy;
}