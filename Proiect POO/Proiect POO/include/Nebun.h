#ifndef NEBUN_H
#define NEBUN_H
#include <iostream>
#include <cmath>
#include "Piesa.h"





class Nebun :public Piesa
{
public:
    Nebun(int x, int y, bool alb, TablaDeJoc* tabla) : Piesa(x, y, alb),   tabla(tabla) {}

    bool isMoveValid(int x, int y) override
    {
        if (std::abs(x - getX()) == std::abs(y - getY()))
        {
            int dirX = (x > getX()) ? 1 : -1;
            int dirY = (y > getY()) ? 1 : -1;

            for (int i = getX() + dirX, j = getY() + dirY;
                    i != x || j != y;
                    i += dirX, j += dirY)
                    //Se verifică dacă diferența pe axa X este aceeași ca diferența pe axa Y. Dacă acest lucru este adevărat, înseamnă că mutarea piesei de tip Nebun respectă regulile deplasării specifice acestui tip de piesă.
            {
                if (tabla->getPiesa(i, j) != nullptr)
                {
                    return false;
                }
            }

            return true;
        }

        return false;
    }

    void afisare() override
    {
        if (alb)
        {
            std::cout << "N";
        }
        else
        {
            std::cout << "n";
        }
    }
private:
    TablaDeJoc* tabla;
};

#endif // NEBUN_H
