#include <iostream>
using namespace std;

#include "Trajet.h"


Trajet::Trajet(string newDepart, string newArrive) : depart(newDepart), arrive(newArrive) {
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
} 


Trajet::~Trajet () {
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
}

string Trajet::GetDepart() {
    return depart;
}

string Trajet::GetArrive() {
    return arrive;
}
