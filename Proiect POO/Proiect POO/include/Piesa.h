#ifndef PIESA_H
#define PIESA_H

#include <iostream>
#include <cmath>

using namespace std;

class Piesa
{

protected:
    int x, y;
    bool alb;
public:
    Piesa(int x, int y, bool alb)
    {
        this->x = x;
        this->y = y;
        this->alb = alb;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    bool isAlb()
    {
        return alb;
    }

    void setX(int x)
    {
        this->x = x;
    }

    void setY(int y)
    {
        this->y = y;
    }

    virtual bool isMoveValid(int x, int y) = 0;

    virtual ~Piesa() {}
    virtual void afisare() = 0;
};

#endif // PIESA_H

