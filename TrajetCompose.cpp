#include <iostream>
using namespace std;

#include "TrajetCompose.h" 

TrajetCompose::TrajetCompose(const char *depart, const char *arrive, Liste *liste) : Trajet(depart, arrive)
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
    this->liste = new Liste();
    for(int i = 0; i < liste->GetTaille(); i++) // copie profonde
    {
        this->liste->Ajouter(liste->GetNoeud(i)->GetTrajet());
    }

    this->depart = new char[strlen(depart) + 1];
    this->arrive = new char[strlen(arrive) + 1];

    strcpy(this->depart, depart);
    strcpy(this->arrive, arrive);
}

void TrajetCompose::Afficher() const
{
    #ifdef MAP
        cout << "Appel au afficher de <TrajetCompose>" << endl;
    #endif

    for(int i = 0; i < liste->GetTaille(); i++)
    {
        Trajet *trajet = liste->GetNoeud(i)->GetTrajet();
        TrajetSimple * trajetSimple = dynamic_cast<TrajetSimple *>(trajet);

        trajetSimple->Afficher();
        cout << " - ";
    }
}

Liste *TrajetCompose::GetListe()
{
    #ifdef MAP
        cout << "Appel au getter liste de <TrajetCompose>" << endl;
    #endif
    return liste;
}

TrajetCompose::~TrajetCompose()
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
}
