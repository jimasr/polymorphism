#include <iostream>
using namespace std;

#include "Catalogue.h"
#include "TrajetSimple.h"

Catalogue::Catalogue() : liste(new Liste())
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalogue>" << endl;
    #endif
}

void Catalogue::Ajouter(Trajet *trajet)
{
    liste->Ajouter(trajet);
}

void Catalogue::AfficherCatalogue() const
{
    liste->Afficher();
}

int Catalogue::RechercherSimple(char *depart, char *arrive) const //send 0 if not found, 1 if found
{
    Noeud *noeud = liste->GetTete();

    int count = 0;

    while (noeud != nullptr)
    {
        Trajet *trajet = noeud->GetTrajet();
        
        // Compare le départ et l'arrivée du trajet avec les paramètres
        if (!strcmp(trajet->GetArrive(), arrive) && !strcmp(trajet->GetDepart(), depart))
        {
            // Affiche le trajet correspondant
            noeud->GetTrajet()->Afficher();
            count++;
        }

        noeud = noeud->GetNoeudSuivant();
    }
    return count;
}


int Catalogue::VerifierDupliquerSimple(char *depart, char *arrive, char *transport) const
{
    Noeud *noeud = liste->GetTete();

    while (noeud != nullptr)
    {
        TrajetSimple *trajetSimple = dynamic_cast<TrajetSimple *>(noeud->GetTrajet());
        // Compare le départ et l'arrivée du trajet avec les paramètres
        if (strcmp(trajetSimple->GetArrive(), depart) && strcmp(trajetSimple->GetDepart(), depart) && strcmp(trajetSimple->GetTransport(), transport) == 0)
        {
            return 1;
        }

        noeud = noeud->GetNoeudSuivant();
    }
    return 0;
}

Catalogue::~Catalogue()
{
    delete liste;
    #ifdef MAP
        cout
            << "Appel au destructeur de <Catalogue>" << endl;
    #endif
    // Le destructeur de Catalogue libérera automatiquement la mémoire utilisée par la Liste
}
