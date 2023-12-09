#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "Liste.h"
#include "Noeud.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

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

    //Rechercher simple
    int RechercherSimple(char *debut, char *fin) const;

    //Verifier dupliquer
    int VerifierDupliquer(Trajet * trajet) const;

protected:
    Liste *liste;
};

#endif
