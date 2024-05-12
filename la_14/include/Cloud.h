#ifndef CLOUD_H
#define CLOUD_H

#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;


class Cloud
{
    public:
        Cloud();
        virtual ~Cloud();
        // setters
        virtual void set_name(string);
        void set_number(string);
        virtual void set_id(string);
        virtual void set_date(string);
        void set_price();
        virtual void set_amount(string);
        void set_points();
        void set_increasepoints(int, int);
        void set_totalpoints(int, int, int);
        void stock_reduce(int, int);
        void set_exist(string, string);
        // getters
        string get_name();
        double get_number();
        string get_id();
        string get_date();
        string get_price();
        string get_amount();
        string get_points();
        bool get_exist();
        // method
        void not_founded(bool);
    private:
        bool exist;
    protected:
        double number;
        string message, name, id, date, price, amount, points, line, old, deleted;
};


#endif // CLOUD_H
