#ifndef CLOUD_H
#define CLOUD_H

#include<iostream>
#include <fstream>
#include <sstream>
#include<vector>
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
        virtual void set_amount(string);
        void set_points();
        void set_increasepoints(int, int);
        void set_totalpoints(int, int, int);
        void stock_reduce(int, int);
        // getters
        string get_name();
        double get_number();
        string get_id();
        string get_date();
        int get_amount();
        int get_points();
        // method
        string codigo, name, id, date, searched;
        void not_founded(bool);
        void set_exist(bool);
        bool get_exist();
        void existence(string, string);
    private:
        string message;
        int amount, points;
        bool exist;
    protected:
        double number;
        string line, old, deleted;
};


#endif // CLOUD_H
