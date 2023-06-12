#include <iostream>
#include <cmath>
#include "Piesa.h"
#include "TablaDeJoc.h"
#include "Pion.h"
#include "Rege.h"
#include "Regina.h"
#include "Tura.h"
#include "Nebun.h"
#include "Cal.h"

int main()
{
    TablaDeJoc tabla;

    // adaugam piese
    tabla.adaugaPiesa(new Tura(0, 0, true, &tabla));
    tabla.adaugaPiesa(new Cal(1, 0, true, &tabla));
    tabla.adaugaPiesa(new Nebun(2, 0, true, &tabla));
    tabla.adaugaPiesa(new Regina(3, 0, true, &tabla));
    tabla.adaugaPiesa(new Rege(4, 0, true, &tabla));
    tabla.adaugaPiesa(new Nebun(5, 0, true, &tabla));
    tabla.adaugaPiesa(new Cal(6, 0, true, &tabla));
    tabla.adaugaPiesa(new Tura(7, 0, true, &tabla));
    for(int i = 0; i < 8; i++)
    {
        tabla.adaugaPiesa(new Pion(i, 1, true, &tabla));
        tabla.adaugaPiesa(new Pion(i, 6, false, &tabla));
    }
    tabla.adaugaPiesa(new Tura(0, 7, false, &tabla));
    tabla.adaugaPiesa(new Cal(1, 7, false, &tabla));
    tabla.adaugaPiesa(new Nebun(2, 7, false, &tabla));
    tabla.adaugaPiesa(new Regina(3, 7, false, &tabla));
    tabla.adaugaPiesa(new Rege(4, 7, false, &tabla));
    tabla.adaugaPiesa(new Nebun(5, 7, false, &tabla));
    tabla.adaugaPiesa(new Cal(6, 7, false, &tabla));
    tabla.adaugaPiesa(new Tura(7, 7, false, &tabla));

    // afisam tabla initiala
    tabla.afisareTabla();

    // miscam piese
    /*std::cout << "Mutam tura de la (0,0) la (0,4)\n";
    tabla.mutarePiesa(0, 0, 0, 4);
    tabla.afisareTabla();

    std::cout << "Mutam pionul de la (0,1) la (0,3)\n";
    tabla.mutarePiesa(0, 1, 0, 3);
    tabla.afisareTabla();

    std::cout << "Mutam calul de la (1,0) la (2,2)\n";
    tabla.mutarePiesa(1, 0, 2, 2);
    tabla.afisareTabla();

    std::cout << "Mutam nebunul de la (2,0) la (4,2)\n";
    tabla.mutarePiesa(2, 0, 4, 2);
    tabla.afisareTabla();

    std::cout << "Mutam regina de la (3,0) la (7,4)\n";
    tabla.mutarePiesa(3, 0, 7, 4);
    tabla.afisareTabla();

    std::cout << "Mutam regele de la (4,0) la (4,1)\n";
    tabla.mutarePiesa(4, 0, 4, 1);
    tabla.afisareTabla();*/

    bool jucatorCurent = true; // true = alb, false = negru
    bool jocInCurs = true;
    while(jocInCurs)
    {
        // afiseaza tabla de joc
        std::cout << "Tabla de joc inainte de mutarea jucatorului " << (jucatorCurent ? "alb" : "negru") << std::endl;
        tabla.afisareTabla();

        // citeste mutarea de la jucatorul curent
        std::cout << "Este randul jucatorului " << (jucatorCurent ? "alb" : "negru") << std::endl;
        int xSursa, ySursa, xDestinatie, yDestinatie;
        std::cout << "Introdu coordonatele piesei pe care vrei sa o misti: ";
        std::cin >> xSursa >> ySursa;
        std::cout << "Introdu coordonatele destinatiei: ";
        std::cin >> xDestinatie >> yDestinatie;

        // verifica daca mutarea este valida
        Piesa *piesa = tabla.getPiesa(xSursa, ySursa);
        if(piesa != nullptr)
        {


                tabla.mutarePiesa(xSursa, ySursa, xDestinatie, yDestinatie);

        }
        // schimba jucatorul curent
        jucatorCurent = !jucatorCurent;

    bool inSah = tabla.isInSah(jucatorCurent);
    if(inSah && !tabla.areMutariValide(jucatorCurent))
    {
        std::cout << "Joc terminat. ";
        if(tabla.isInSah(jucatorCurent))
        {
            std::cout << "Jucatorul " << (jucatorCurent ? "alb" : "negru") << " a castigat prin sah mat!";
        }
        else
        {
            std::cout << "Jocul s-a incheiat cu remiza!";
        }
    }
    }
    return 0;
}

