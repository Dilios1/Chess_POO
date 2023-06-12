#ifndef TABLADEJOC_H
#define TABLADEJOC_H
#include <iostream>
#include <cmath>
#include "Piesa.h"



using namespace std;


class TablaDeJoc
{
private:
    Piesa* piesa[8][8];
public:
    TablaDeJoc()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                piesa[i][j] = nullptr;
            }
        }
    }

    void afisareTabla()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (piesa[i][j] != nullptr)
                {
                    piesa[i][j]->afisare();
                }
                else
                {
                    cout << "_ ";
                }
            }
            cout << endl;
        }
    }

    void adaugaPiesa(Piesa* piesa)
    {
        //Adauga piesa pe tabla (pointer la un obiect de tip piesa)
        this->piesa[piesa->getX()][piesa->getY()] = piesa;
    }

    Piesa* getPiesa(int x, int y)
    {
        //Returneaza pointer catre piesa de pe pozitia specificata de coordonate.
        return piesa[x][y];
    }

    void mutarePiesa(int x1, int y1, int x2, int y2)
    {
        std::swap(piesa[x1][y1], piesa[x2][y2]);
    }

    bool isInSah(bool alb)
    {
        // Determina pozitia regelui jucatorului cu culoarea specificata
        int xRege = -1, yRege = -1;
        for (int x = 0; x < 8; ++x)
        {
            for (int y = 0; y < 8; ++y)
            {
                Piesa* piesa = getPiesa(x, y);
                if (piesa != nullptr && piesa->isAlb() == alb)
                {
                    xRege = x;
                    yRege = y;
                    break;
                }
            }
        }

        // Verifica daca exista vreo piesa a adversarului care poate muta pe pozitia regelui
        for (int x = 0; x < 8; ++x)
        {
            for (int y = 0; y < 8; ++y)
            {
                Piesa* piesa = getPiesa(x, y);
                if (piesa != nullptr && piesa->isAlb() != alb && piesa->isMoveValid(xRege, yRege))
                {
                    return true;
                }
            }
        }

        return false;
    }



    bool areMutariValide(bool alb)
    {
        // Verifica daca exista cel putin o piesa a jucatorului cu culoarea specificata care are cel putin o mutare valida
        for (int x = 0; x < 8; ++x)
        {
            for (int y = 0; y < 8; ++y)
            {
                Piesa* piesa = getPiesa(x, y);
                if (piesa != nullptr && piesa->isAlb() == alb && piesa->isMoveValid(x,y))
                {
                    return true;
                }
            }
        }

        return false;
    }









    bool isInSahMat(bool alb)
    {
        // se verifica daca regele este in sah
        if (!isInSah(alb))
        {
            return false;
        }

        // se verifica daca se poate face o mutare pentru a iesi din sah
        for (int x = 0; x < 8; ++x)
        {
            for (int y = 0; y < 8; ++y)
            {
                Piesa* piesa = getPiesa(x, y);
                // se verifica daca piesa exista si apartine jucatorului cu culoarea specificata
                if (piesa != nullptr && piesa->isAlb() == alb)
                {
                    // se parcurg toate mutarile valide ale piesei
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            if (piesa->isMoveValid(i, j))
                            {
                                // se incearca mutarea piesei pe noua pozitie
                                mutarePiesa(x, y, i, j);

                                // se verifica daca regele nu mai este in sah
                                bool esteInSah = isInSah(alb);

                                // se revine la starea initiala a tablei
                                mutarePiesa(i, j, x, y);

                                if (!esteInSah)
                                {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }

        // daca nu s-a putut face nicio mutare pentru a iesi din sah, este sah mat
        return true;
    }

bool existaPiesa(int x, int y)
{
    Piesa* piesa = getPiesa(x, y);
    return (piesa != nullptr);
}


};

#endif // TABLADEJOC_H
