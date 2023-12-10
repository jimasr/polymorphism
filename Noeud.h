/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Noeud> (fichier Noeud.h) ----------------
#ifndef NOEUD_H
#define NOEUD_H

#include "Trajet.h"

// Représente un nœud dans une liste chaînée.
class Noeud
{
public:
    // Constructeur de Noeud.
    // suivant : Le pointeur vers le nœud suivant.
    // trajet : Le trajet associé au nœud.
    Noeud(Noeud *suivant, Trajet *trajet);

    // Obtient le nœud suivant.
    Noeud *GetNoeudSuivant() const;

    // Modifie le noeud suivant.
    void SetNoeudSuivant(Noeud *suivant);

    // Obtient le trajet associé au nœud.
    Trajet *GetTrajet() const;

    // Destructeur de Noeud.
    virtual ~Noeud();

private:
    Noeud *noeud;   // Pointeur vers le nœud suivant.
    Trajet *trajet; // Trajet associé au nœud.
};

#endif
