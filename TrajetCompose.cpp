#include <iostream>
using namespace std;

#include "TrajetCompose.h"

TrajetCompose::TrajetCompose(const char *depart, const char *arrive, Liste *liste) : Trajet(depart, arrive), liste(liste)
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
}

void TrajetCompose::Afficher() const
{
    #ifdef MAP
        cout << "Appel au afficher de <TrajetCompose>" << endl;
    #endif
    liste->Afficher();
}

Liste *TrajetCompose::GetListe()
{
    #ifdef MAP
        cout << "Appel au getter liste de <TrajetCompose>" << endl;
    #endif
    return liste;
}

TrajetCompose::~TrajetCompose()
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
}
