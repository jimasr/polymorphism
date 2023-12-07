#include <iostream>
using namespace std;

#include "Liste.h"
#include "TrajetSimple.h"

// Constructeur de Liste
Liste::Liste()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Liste>" << endl;
    #endif
    tete = nullptr; // Initialise la liste avec un pointeur de tête nul.
}

// Ajoute un élément à la fin de la liste.

void Liste::Ajouter(Trajet *trajet)
{
    #ifdef MAP
        cout << "Appel au ajouter de <Liste>" << endl;
    #endif

    Noeud * noeud = new Noeud(nullptr, trajet);
    if (tete == nullptr)
    {
        tete = noeud; // Si la liste est vide, le nouvel élément devient le premier
        return;
    }

    Noeud *temp = tete;
    while (temp->GetNoeudSuivant() != nullptr)
    {
        temp = temp->GetNoeudSuivant();
    }

    temp->SetNoeudSuivant(noeud);
    // Ajouter le nouvel élément à la fin de la liste
}

// Affichage Liste

void Liste::Afficher() const
{
    #ifdef MAP
        cout << "Appel au afficher de <Liste>" << endl;
    #endif

    Noeud *temp = tete;
    while (temp != nullptr)
    {
        Trajet *trajet = temp->GetTrajet();
        cout << "de " << trajet->GetDepart() << " à " << trajet->GetArrive() << endl;
        temp = temp->GetNoeudSuivant();
    }
}

// Destructeur de Liste
Liste::~Liste()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Liste>" << endl;
    #endif

    Noeud *courant = tete;
    while (courant != nullptr)
    {
        Noeud *suivant = courant->GetNoeudSuivant();
        delete courant;
        courant = suivant;
    }
}

Noeud *Liste::GetTete() const
{
    return tete;
}
