#include <iostream>
using namespace std;

#include "Trajet.h"


Trajet::Trajet(const char* newDepart, const char* newArrive) {
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif

    depart = new char[strlen(newDepart) + 1];
    arrive = new char[strlen(newArrive) + 1];
    strcpy(depart, newDepart);
    strcpy(arrive, newArrive);
} 


Trajet::~Trajet () {
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
}

char * Trajet::GetDepart() {
    return depart;
}

char* Trajet::GetArrive() {
    return arrive;
}
