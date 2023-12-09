#include <iostream>
using namespace std;

#include "Catalogue.h"

Catalogue::Catalogue() : liste(new Liste())
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalogue>" << endl;
    #endif
}

void Catalogue::Ajouter(Trajet *trajet)
{
    #ifdef MAP
        cout << "Appel au ajouter de <Catalogue>" << endl;
    #endif
    liste->Ajouter(trajet);
}

void Catalogue::AfficherCatalogue() const
{
    #ifdef MAP
        cout << "Appel au afficherCatalogue de <Catalogue>" << endl;
    #endif
    liste->Afficher();
}

int Catalogue::RechercherSimple(char *depart, char *arrive) const //send 0 if not found, 1 if found
{
    #ifdef MAP
        cout << "Appel au rechercherSimple de <Catalogue>" << endl;
    #endif
    Noeud *noeud = liste->GetTete();

    int count = 0;

    while (noeud != nullptr)
    {
        const Trajet *trajet = noeud->GetTrajet();
        
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


int Catalogue::VerifierDupliquer(Trajet * trajet) const
{
    #ifdef MAP
        cout << "Appel au verifierDupliquer de <Catalogue>" << endl;
    #endif
    Noeud *noeud = liste->GetTete();
    
    while(noeud != nullptr)
    {
        const Trajet *t = noeud->GetTrajet();
        if(trajet->Equals(t))
        {
            return 1; // si un duplique trajet est trouvé
        }
        noeud = noeud->GetNoeudSuivant();
    }
    return 0; // si aucun duplique trajet n'est trouvé

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
