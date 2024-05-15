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
        void set_points();
        void set_exist(string, string);
        // getters
        string get_name();
        double get_number();
        string get_id();
        string get_date();
        string get_amount();
        string get_points();
        bool get_exist();
        // method
        void not_founded(bool);
        double number;
        string message, name, id, date, amount, points, line, old, deleted;
    private:
        bool exist;
};


#endif // CLOUD_H
