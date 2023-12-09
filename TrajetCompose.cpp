#include <iostream>
using namespace std;

#include "TrajetCompose.h" 
#include <cstring>


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

    Noeud *noeud = liste->GetTete();
    while(noeud != nullptr)
    {
        const Trajet *trajet = noeud->GetTrajet();
        trajet->Afficher();
        if(noeud->GetNoeudSuivant() != nullptr) 
        cout << " - ";

        noeud = noeud->GetNoeudSuivant();
    }
}

char* TrajetCompose::ToString() const
{
    char* trajetStr = new char[1000]; // Assumption: the total length of the string will not exceed 1000 characters
    trajetStr[0] = '\0'; // Initialize the string to be empty
    Noeud *noeud = liste->GetTete();

    while (noeud != nullptr)
    {
        const Trajet *trajet = noeud->GetTrajet();
        char trajetPart[100]; // Assumption: the length of the string for a single trajet will not exceed 100 characters
        sprintf(trajetPart, "%s a %s", trajet->GetDepart(), trajet->GetArrive());
        strcat(trajetStr, trajetPart);
        noeud = noeud->GetNoeudSuivant();

        // Add a comma after each sub-trajet except the last
        if (noeud != nullptr)
        {
            strcat(trajetStr, ", ");
        }
    }

    return trajetStr;
}

Liste *TrajetCompose::GetListe() const
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
    delete liste;
}

bool TrajetCompose::Equals(const Trajet *trajet) const
{
    #ifdef MAP
        cout << "Appel au equals de <TrajetCompose>" << endl;
    #endif
    const TrajetCompose *trajetCompose = dynamic_cast<const TrajetCompose *>(trajet);

    if(trajetCompose != nullptr)
    {
        if(!strcmp(trajetCompose->GetDepart(), depart) && !strcmp(trajetCompose->GetArrive(), arrive))
        {
            if(trajetCompose->GetListe()->GetTaille() == liste->GetTaille())
            {
                Noeud *noeud = liste->GetTete();
                Noeud *other = trajetCompose->GetListe()->GetTete();
                while(noeud != nullptr)
                {
                    if(!noeud->GetTrajet()->Equals(other->GetTrajet()))
                    {
                        return false;
                    }
                    noeud = noeud->GetNoeudSuivant();
                    other = other->GetNoeudSuivant();
                }
                return true;
            }
        }
    }
    return false;
}
