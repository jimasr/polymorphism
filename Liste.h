#ifndef LISTE_H
#define LISTE_H

#include "Noeud.h"
#include "Trajet.h"

// Représente une liste chaînée de nœuds.
class Liste {
    public:
        // Constructeur de Liste.
        // Initialise la liste avec un pointeur de tête nul.
        Liste();

        // Ajoute un élément à la fin de la liste.
        // elem : Le trajet à ajouter.
        void Ajouter(const Trajet& elem);
        Noeud* GetTete() const;
        // Affiche la liste
        void Afficher() const;

        // Destructeur de Liste.
        // Libère la mémoire occupée par tous les nœuds de la liste.
        virtual ~Liste();
        

    protected:
        Noeud* tete; // Pointeur vers le premier nœud de la liste.
};

#endif
