#ifndef REGE_H
#define REGE_H
#include <iostream>
#include <cmath>
#include "Piesa.h"
#include "TablaDeJoc.h"





class Rege : public Piesa
{

public:
    Rege(int x, int y, bool alb, TablaDeJoc* tabla) : Piesa(x, y, alb), tabla(tabla) {}

    bool isMoveValid(int x, int y) override
    {

        int dx = std::abs(x - getX());
        int dy = std::abs(y - getY());

        // regele poate fi mutat cu o casuta in orice directie
        if (dx <= 1 && dy <= 1)
        {
            // se verifica daca destinatia este goala sau ocupata de o piesa a adversarului
            Piesa* piesa = tabla->getPiesa(x, y);
            return piesa == nullptr || piesa->isAlb() != alb;
        }

        return false;
    }

    void afisare() override
    {
        if (alb)
        {
            std::cout << "R";
        }
        else
        {
            std::cout << "r";
        }
    }
private:
    TablaDeJoc* tabla;
};

#endif // REGE_H

