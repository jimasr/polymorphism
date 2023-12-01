#include <iostream>
using namespace std;

#include "Noeud.h"
#include "Trajet.h"

// Constructeur de Noeud
Noeud::Noeud(Noeud *suivant, Trajet *traj) : noeud(suivant), trajet(traj)
{
#ifdef MAP
    cout << "Appel au constructeur de <Noeud>" << endl;
#endif
}

// Obtient le nœud suivant.
Noeud *Noeud::GetNoeudSuivant() const
{
    return noeud;
}

// Modifier le pointeur du nœud suivant
void Noeud::SetNoeudSuivant(Noeud *suivant)
{
    noeud = suivant;
}

// Obtient le trajet associé au nœud.
Trajet *Noeud::GetTrajet() const
{
    return trajet;
}

// Destructeur de Noeud
Noeud::~Noeud()
{
#ifdef MAP
    cout << "Appel au destructeur de <Noeud>" << endl;
#endif
}
