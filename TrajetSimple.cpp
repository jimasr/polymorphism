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
    delete[] transport;
} 

void TrajetSimple::Afficher() const {
    cout << "de " << depart << " à " << arrive << " en " << transport;
}

char* TrajetSimple::GetTransport() const{
    return transport;
}

bool TrajetSimple::Equals(const Trajet *trajet) const
{
    #ifdef MAP
        cout << "Appel au equals de <TrajetSimple>" << endl;
    #endif
    const TrajetSimple *trajetSimple = dynamic_cast<const TrajetSimple *>(trajet);
    if(trajetSimple != nullptr)
    {
        return !strcmp(trajetSimple->GetDepart(), depart) && 
            !strcmp(trajetSimple->GetArrive(), arrive) && 
            !strcmp(trajetSimple->GetTransport(), transport);
    }
    return false;
}
