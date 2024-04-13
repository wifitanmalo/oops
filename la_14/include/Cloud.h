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
        void set_number(string);
        void set_customerid();
        void set_productid();
        void set_name();
        void set_date();
        void set_points();
        void set_increasepoints(int, int);
        void set_totalpoints(int, int, int);
        // getters
        double get_number();
        long get_customerid();
        long get_productid();
        string get_name();
        long get_date();
        int get_points();
    private:
        string message, name;
        long customer_id, product_id, date;
        int points;
    protected:
        double number;
};


#endif // CLOUD_H
