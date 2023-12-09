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
    taille = 0; 
}

// Ajoute un élément à la fin de la liste.

void Liste::Ajouter(Trajet *trajet)
{
    #ifdef MAP
        cout << "Appel au ajouter de <Liste>" << endl;
    #endif

    Noeud * noeud = new Noeud(nullptr, trajet);
    taille++; //increment taille

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
    int count = 0;
    Noeud *temp = tete;
    while (temp != nullptr)
    {
        const Trajet *trajet = temp->GetTrajet();

        cout << count + 1 << " : ";
        trajet->Afficher();
        cout << endl;
        temp = temp->GetNoeudSuivant();

        count++;
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

Noeud *Liste::GetNoeud(int index) const
{
    Noeud *temp = tete;
    int i = 0;
    while (temp != nullptr)
    {
        if (i == index)
        {
            return temp;
        }
        temp = temp->GetNoeudSuivant();
        i++;
    }
    return nullptr;
}

int Liste::GetTaille() const
{
    return taille;
}

bool Liste::Equals(const Liste *liste) const
{
    #ifdef MAP
        cout << "Appel au equals de <Liste>" << endl;
    #endif
    if (taille != liste->GetTaille())
    {
        return false;
    }

    Noeud *noeud = tete;
    Noeud *n = liste->GetTete();

    while (noeud != nullptr)
    {
        Trajet *trajet = noeud->GetTrajet();
        Trajet *trajet2 = n->GetTrajet();

        if (!trajet->Equals(trajet2))
        {
            return false;
        }

        noeud = noeud->GetNoeudSuivant();
        n = n->GetNoeudSuivant();
    }

    return true;
}
