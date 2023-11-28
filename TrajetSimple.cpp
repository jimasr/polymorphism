#include <iostream>
using namespace std;

#include "TrajetSimple.h"


TrajetSimple::TrajetSimple(string newDepart, string newArrive, string newTransport) : Trajet(newDepart, newArrive), transport(newTransport)
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
    cout << " de " << depart << " a " << arrive << " en " << transport << endl;
}

string TrajetSimple::GetTransport()
{
    return transport;
}
