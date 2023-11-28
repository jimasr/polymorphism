#include "Catalogue.h"
#include <iostream>

Catalogue::Catalogue() {
    
}

Catalogue::~Catalogue() {
    // Le destructeur de Catalogue libérera automatiquement la mémoire utilisée par la Liste
}

void Catalogue::Ajouter(char* debut, char* fin) {
    // Ajoutez le trajet à la liste
    //liste.Ajouter(char* debut, char* fin);
}

void Catalogue::AfficherCatalogue() const {
    // Affichez la liste
    liste.Afficher();
}

void Catalogue::RechercherSimple(char* depart, char* arrive) const
{

}