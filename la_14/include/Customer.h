#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Cloud.h"

class Customer : public Cloud
{
    public:
        Customer();
        virtual ~Customer();
        // setters
        void set_id();
        void set_name();
        void set_date();
        void set_totalpoints(int, int, int);
        // crud
        void create();
        void read();
        void update();
        void update_points(string, int);
        void d_elete();
};

#endif // CUSTOMER_H
