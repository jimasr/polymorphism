/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "Liste.h"
#include "Noeud.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <cstring>

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

    void RechercherAvancee(char *debut, char *fin) const;

    //Verifier dupliquer
    int VerifierDupliquer(Trajet * trajet) const;

protected:

// Dans Catalogue.h
bool RechercherTransitif(const char *depart, const char *arrive, char **visited, int &visitedCount, Trajet **currentPath, int &pathCount, int &count) const;
Liste *liste;
};

#endif
