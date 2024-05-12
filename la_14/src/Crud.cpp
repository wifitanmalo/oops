#include "Crud.h"


Crud::Crud()
{
    //ctor
}


Crud::~Crud()
{
    //dtor
}


void Crud::create(int data, int loop)
{
    switch(data)
    {
        case 1: c.create(); break;
        case 2: p.create(); break;
        case 3: b.create(loop); break;
    }
}


void Crud::read(int data, int loop)
{
    switch(data)
    {
        case 1: c.read(); break;
        case 2: p.read(); break;
        case 3: b.read(); break;
    }
}


void Crud::update(int data, int loop)
{
    switch(data)
    {
        case 1: c.update(); break;
        case 2: p.update(); break;
        case 3: b.update(loop); break;
    }
}


void Crud::d_elete(int data, int loop)
{
    switch(data)
    {
        case 1: c.d_elete(); break;
        case 2: p.d_elete(); break;
        case 3: b.d_elete(); break;
    }
}
