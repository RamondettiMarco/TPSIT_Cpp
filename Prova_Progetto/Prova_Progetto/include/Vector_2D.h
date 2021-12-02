#ifndef VECTOR_2D_H
#define VECTOR_2D_H


class Vector_2D
{
    public:
        Vector_2D(double x, double y);
        double Getx();
        double Gety();
        void Setx(double x);
        void Sety(double y);
        virtual ~Vector_2D();
    protected:
    private:
        double x_;
        double y_;
};

#endif // VECTOR_2D_H
