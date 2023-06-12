#ifndef PION_H
#define PION_H
#include <iostream>
#include <cmath>
#include "TablaDeJoc.h"
#include "Piesa.h"





class Pion :public Piesa
{
    bool primaMutare;
public:
    Pion(int x, int y, bool alb, TablaDeJoc* tabla) :
        Piesa(x, y, alb),
        tabla(tabla),
        primaMutare(false)
    {
    }

    bool isMoveValid(int x, int y) override
    {

        // Verifică dacă există alte piese în pozițiile (x+1, y-1) și (x-1, y-1)
        if (x == getX() + 1 && (y == getY() - 1 || y == getY() + 1))
        {
            if (tabla->existaPiesa(x, y) && tabla->getPiesa(x, y)->isAlb() != isAlb())
            {
                // Verifică dacă mutarea este pe verticală
                if (getX() == x)
                {
                    // Verifică dacă este o mutare înainte pe verticală pentru piesele albe
                    if (isAlb() && y == getY() - 1 && !tabla->existaPiesa(x, y))
                    {
                        return true;
                    }

                    // Verifică dacă este o mutare înainte pe verticală pentru piesele negre
                    if (!isAlb() && y == getY() + 1 && !tabla->existaPiesa(x, y))
                    {
                        return true;
                    }
                }
                // Verifică dacă este o mutare pe diagonală pentru a captura o piesă de culoare opusă
                if (x == getX() + 1 && (y == getY() - 1 || y == getY() + 1))
                {
                    if (tabla->existaPiesa(x, y) && tabla->getPiesa(x, y)->isAlb() != isAlb())
                    {
                        return true;
                    }
                }

                // Nu s-a îndeplinit nicio condiție de mutare validă, returnează false
                return false;
            }

        }

        if(primaMutare)
        {
            primaMutare = false;
            if(getX() == x)
            {
                if(getY() + 1 == y) return true;
                if(getY() + 2 == y) return true;
                return false;
            }
            return false;
        }
        else return getX() == x && getY() + 1 == y;
    }

    void afisare() override
    {
        if (alb)
        {
            std::cout << "P";
        }
        else
        {
            std::cout << "p";
        }
    }
private:
    TablaDeJoc* tabla;
};

#endif // PION_H

