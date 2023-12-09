#include <iostream>
#include <cstring>
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
    delete[] depart;
    delete[] arrive;
}

char* Trajet::GetDepart() const {
    return depart;
}

char* Trajet::GetArrive() const {
    return arrive;
}

bool Trajet::Equals(const Trajet* trajet) const {
    #ifdef MAP
        cout << "Appel au equals de <Trajet>" << endl;
    #endif
    return !strcmp(trajet->GetDepart(), depart) && 
        !strcmp(trajet->GetArrive(), arrive);
}
