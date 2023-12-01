#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "Liste.h"
#include "Noeud.h"

class Catalogue
{
public:
    // Constructeur de Catalogue
    Catalogue();

    // Destructeur de Catalogue
    ~Catalogue();

    // Ajoute un trajet au catalogue
    void Ajouter(Trajet *trajet);

    // Affiche le catalogue
    void AfficherCatalogue() const;

    int RechercherSimple(char *debut, char *fin) const;
    int RechercherSimple2(char *debut, char *fin) const;

protected:
    Liste *liste;
};

#endif
