#include <iostream>
using namespace std;

#include "Trajet.h"


Trajet::Trajet(const char* newDepart, const char* newArrive) : depart(newDepart), arrive(newArrive) {
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
} 


Trajet::~Trajet () {
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
}

const char * Trajet::GetDepart() {
    return depart;
}

const char* Trajet::GetArrive() {
    return arrive;
}
