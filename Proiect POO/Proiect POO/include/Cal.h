#ifndef CAL_H
#define CAL_H
#include <iostream>
#include <cmath>
#include "Piesa.h"
#include "TablaDeJoc.h"




class Cal : public Piesa
{
public:
    Cal(int x, int y, bool alb, TablaDeJoc* tabla) : Piesa(x, y, alb), tabla(tabla) {}

    bool isMoveValid(int x, int y) override
    {

        int dx = std::abs(x - getX());
        int dy = std::abs(y - getY());

        return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
        //Se verifica daca dist pe axa X este de 2 si pe axa Y este de 1 sau invers.
    }

    void afisare() override
    {
        if (alb)
        {
            std::cout << "C";
        }
        else
        {
            std::cout << "c";
        }
    }
private:
    TablaDeJoc* tabla;
};
#endif // CAL_H
