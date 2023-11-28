#include <iostream>
#include "TrajetSimple.h"
using namespace std;

TrajetSimple::TrajetSimple(std::string newDepart, std::string newArrive, std::string newTransport) : Trajet(newDepart, newArrive), transport(newTransport)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
}


TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} 

void TrajetSimple::Afficher() const
{
    cout << "de" << depart << "a" << arrive << "en" << transport << endl;
}

std::string TrajetSimple::getTransport()
{
    return transport;
}