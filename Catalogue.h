#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "Liste.h"

class Catalogue {
public:
    // Constructeur de Catalogue
    Catalogue();

    // Destructeur de Catalogue
    ~Catalogue();

    // Ajoute un trajet au catalogue
    void Ajouter(char* debut, char* fin);

    // Affiche le catalogue
    void AfficherCatalogue() const;
    
    void RechercherSimple(char* debut, char* fin) const;

private:
    Liste liste;
    
};

#endif
