#ifndef TURA_H
#define TURA_H
#include <iostream>
#include <cmath>
#include "Piesa.h"
#include "TablaDeJoc.h"




class Tura : public Piesa
{
public:
    Tura(int x, int y, bool alb, TablaDeJoc* tabla) : Piesa(x, y, alb), tabla(tabla) {}

    bool isMoveValid(int x, int y) override
    {
        //
        if (x == getX() || y == getY())
        {
            int dirX = (x > getX()) ? 1 : -1;
            int dirY = (y > getY()) ? 1 : -1;
            //Calculeaza directia de deplasare x mai mare = mutare in dreapta, y mai mare = mutare in sus, in caz contrat este in jos.

            for (int i = getX() + dirX, j = getY() + dirY;
                    i != x || j != y;
                    i += dirX, j += dirY)
                    //Directia de deplasare in functie de coordonatele destinatiei.
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
            std::cout << "T";
        }
        else
        {
            std::cout << "t";
        }
    }
private:
    TablaDeJoc* tabla;
};

#endif // TURA_H
