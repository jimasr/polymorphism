#include "Catalogue.h"
#include <iostream>

Catalogue::Catalogue(int capacite) : capaciteActuelle(capacite), tailleActuelle(0) {
    trajets = new Trajet*[capacite];
}

Catalogue::~Catalogue() {
    for (int i = 0; i < tailleActuelle; ++i) {
        delete trajets[i];
    }
    delete[] trajets;
}

void Catalogue::ajouterTrajet(Trajet* trajet) {
    if (tailleActuelle < capaciteActuelle) {
        trajets[tailleActuelle++] = trajet;
    } else {
        std::cout << "Catalogue plein. Impossible d'ajouter plus de trajets." << std::endl;
    }
}

void Catalogue::lireCatalogue() const {
    for (int i = 0; i < tailleActuelle; ++i) {
        trajets[i]->Afficher();
    }
}
