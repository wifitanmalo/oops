#ifndef CLOUD_H
#define CLOUD_H

#include<iostream>
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
        long get_id();
        long get_date();
        int get_amount();
        int get_points();
        // method
        void not_founded(bool);
    private:
        string message, name;
        long id, date;
        int amount, points;
    protected:
        double number;
        string old, deleted;
};


#endif // CLOUD_H
