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
        void set_customerid();
        void set_productid();

        virtual void set_date(string);

        void set_points();
        void set_increasepoints(int, int);
        void set_totalpoints(int, int, int);
        // getters
        string get_name();
        double get_number();
        long get_customerid();
        long get_productid();
        long get_date();
        int get_points();
        // method
        void not_founded(bool);
    private:
        string message, name;
        long customer_id, product_id, date;
        int points;
    protected:
        double number;
        string old, deleted;
};


#endif // CLOUD_H
