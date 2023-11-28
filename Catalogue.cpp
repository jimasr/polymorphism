#include "Catalogue.h"
#include <iostream>


Catalogue::Catalogue() : liste(nullptr) {
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
}

Catalogue::~Catalogue() {
    // Le destructeur de Catalogue libérera automatiquement la mémoire utilisée par la Liste
}

void Catalogue::Ajouter(char* debut, char* fin) {
}

void Catalogue::AfficherCatalogue() const {

}

void Catalogue::RechercherSimple(char* depart, char* arrive) const
{
    Liste * test = liste;
    while (test != nullptr) {
        // Compare le départ et l'arrivée du trajet avec les paramètres
        if (test->GetTrajet().GetArrive() == arrive && test->GetTrajet().GetDepart() == depart) {
            // Affiche le trajet correspondant
            test->GetTrajet().Afficher();
        }

        test = test->GetNoeudSuivant();
    }

}