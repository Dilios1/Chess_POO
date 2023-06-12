#ifndef REGINA_H
#define REGINA_H
#include <iostream>
#include <cmath>
#include "TablaDeJoc.h"
#include "Piesa.h"




class Regina : public Piesa
{
public:
    Regina(int x, int y, bool alb, TablaDeJoc* tabla) : Piesa(x, y, alb),  tabla(tabla) {}

    bool isMoveValid(int x, int y) override
    {

        int dx = x - getX();
        int dy = y - getY();

        // daca mutarea e in diagonala
        if (std::abs(dx) == std::abs(dy))
        {
            int stepX = dx > 0 ? 1 : -1;
            int stepY = dy > 0 ? 1 : -1;
            int currX = getX() + stepX;
            int currY = getY() + stepY;

            while (currX != x && currY != y)
            {
                if (tabla->getPiesa(currX, currY) != nullptr)
                {
                    return false;
                }
                currX += stepX;
                currY += stepY;
            }

            return true;
        }

        // daca mutarea e in sus/jos sau stanga/dreapta
        if (dx == 0 || dy == 0)
        {
            int step = dx != 0 ? dx / std::abs(dx) : dy / std::abs(dy);
            int currX = getX() + step;
            int currY = getY() + step;

            while (currX != x || currY != y)
            {
                if (tabla->getPiesa(currX, currY) != nullptr)
                {
                    return false;
                }
                currX += step;
                currY += step;
            }

            return true;
        }

        return false;
    }

    void afisare() override
    {
        if (alb)
        {
            std::cout << "Q";
        }
        else
        {
            std::cout << "q";
        }
    }
private:
    TablaDeJoc* tabla;
};

#endif // REGINA_H

