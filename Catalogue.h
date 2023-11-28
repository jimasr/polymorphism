#if !defined(CATALOGUE_H)
#define CATALOGUE_H

#include "Trajet.h"
#include "Liste.h"

class Catalogue {
public:
    Catalogue(int capacite);
    ~Catalogue();

    void ajouterTrajet(Trajet* trajet);
    void lireCatalogue() const;

private:
    Trajet** trajets;
    int capaciteActuelle;
    int tailleActuelle;
};

#endif // CATALOGUE_H
