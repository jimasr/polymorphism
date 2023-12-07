#include <iostream>
using namespace std;

#include "TrajetSimple.h"


TrajetSimple::TrajetSimple(const char* newDepart, const char* newArrive, const char* newTransport) : Trajet(newDepart, newArrive){
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif

    transport = new char[strlen(newTransport) + 1];
    strcpy(transport, newTransport);
}

TrajetSimple::~TrajetSimple () {
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
} 

void TrajetSimple::Afficher() const {
    cout << "de " << depart << " a " << arrive << " en " << transport << endl;
}

char* TrajetSimple::GetTransport() {
    return transport;
}
