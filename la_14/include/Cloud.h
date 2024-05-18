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
        void set_number(string);
        virtual void set_id(string);
        void set_exist(string, string);
        virtual void set_name(string);
        virtual void set_date(string);
        virtual void set_amount(string);
        // getters
        double get_number();
        string get_id();
        bool get_exist();
        string get_name();
        string get_date();
        string get_amount();
        string get_points();
        // methods
        void open_error(string);
        void eyefind(string, string, int);
        void not_founded(bool);
        void success(int, int, string);
        // crud
        virtual void d_elete(string, string);
        // public variables
        double number;
        string message, name, id, date, price, amount, points, line, old, deleted;
    private:
        bool exist;
};


#endif // CLOUD_H
