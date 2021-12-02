#include "Vector_2D.h"

Vector_2D::Vector_2D(double x, double y)
{
    x_ = x;
    y_ = y;
}

double Vector_2D::Getx()
{
    return x_;
}

double Vector_2D::Gety()
{
    return y_;
}

Vector_2D::~Vector_2D()
{
    //dtor
}
