#include <iostream>
#include "Trajet.h"
using namespace std;

Trajet::Trajet(std::string newDepart, std::string newArrive)
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} 


Trajet::~Trajet ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
}

std::string Trajet::getDepart()
{
    return depart;
}

std::string Trajet::getArrive()
{
    return arrive;
}