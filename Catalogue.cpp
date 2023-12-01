#include <iostream>
using namespace std;

#include "Catalogue.h"

Catalogue::Catalogue() : liste(new Liste())
{

#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
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

void Catalogue::Ajouter(Trajet *trajet)
{
    (*liste).Ajouter(trajet);
}

void Catalogue::AfficherCatalogue() const
{
    Noeud *noeud = liste->GetTete();

    while (noeud != nullptr)
    {
        noeud->GetTrajet()->Afficher();
        noeud = noeud->GetNoeudSuivant();
    }
}

int Catalogue::RechercherSimple(char *depart, char *arrive) const
{
    Noeud *noeud = liste->GetTete();

    while (noeud != nullptr)
    {
        // Compare le départ et l'arrivée du trajet avec les paramètres
        if (noeud->GetTrajet()->GetArrive() == arrive && noeud->GetTrajet()->GetDepart() == depart)
        {
            // Affiche le trajet correspondant
            noeud->GetTrajet()->Afficher();
            return 1;
        }

        noeud = noeud->GetNoeudSuivant();
    }
    return 0;
}

int Catalogue::RechercherSimple2(char *depart, char *arrive) const
{
    Noeud *noeud = liste->GetTete();

    while (noeud != nullptr)
    {
        // Compare le départ et l'arrivée du trajet avec les paramètres
        if (noeud->GetTrajet()->GetArrive() == arrive && noeud->GetTrajet()->GetDepart() == depart)
        {
            // Affiche le trajet correspondant
            return 1;
        }

        noeud = noeud->GetNoeudSuivant();
    }
    return 0;
}
