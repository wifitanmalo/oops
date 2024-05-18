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
        virtual void set_name(string);
        virtual void set_id(string);
        virtual void set_date(string);
        virtual void set_amount(string);
        void set_exist(string, string);
        // getters
        string get_name();
        double get_number();
        string get_id();
        string get_date();
        string get_amount();
        string get_points();
        bool get_exist();


        void eyefind(string, string, int);
        virtual void d_elete(string, string);
        // method
        void open_error(string);
        void succes(int, int, string);
        void not_founded(bool);
        // public variables
        double number;
        string message, name, id, date, price, amount, points, line, old, deleted;
    private:
        bool exist;
};


#endif // CLOUD_H
