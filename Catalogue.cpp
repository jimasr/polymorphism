#include <iostream>
using namespace std;

#include "Catalogue.h"

Catalogue::Catalogue() : liste(new Liste())
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalogue>" << endl;
    #endif
}

void Catalogue::Ajouter(Trajet *trajet)
{
    #ifdef MAP
        cout << "Appel au ajouter de <Catalogue>" << endl;
    #endif
    liste->Ajouter(trajet);
}

void Catalogue::AfficherCatalogue() const
{
    #ifdef MAP
        cout << "Appel au afficherCatalogue de <Catalogue>" << endl;
    #endif
    liste->Afficher();
}

int Catalogue::RechercherSimple(char *depart, char *arrive) const //send 0 if not found, 1 if found
{
    #ifdef MAP
        cout << "Appel au rechercherSimple de <Catalogue>" << endl;
    #endif
    Noeud *noeud = liste->GetTete();

    int count = 0;

    while (noeud != nullptr)
    {
        const Trajet *trajet = noeud->GetTrajet();
        
        // Compare le départ et l'arrivée du trajet avec les paramètres
        if (!strcmp(trajet->GetArrive(), arrive) && !strcmp(trajet->GetDepart(), depart))
        {
            // Affiche le trajet correspondant
            noeud->GetTrajet()->Afficher();
            count++;
        }

        noeud = noeud->GetNoeudSuivant();
    }
    return count;
}


int Catalogue::VerifierDupliquer(Trajet * trajet) const
{
    #ifdef MAP
        cout << "Appel au verifierDupliquer de <Catalogue>" << endl;
    #endif
    Noeud *noeud = liste->GetTete();
    
    while(noeud != nullptr)
    {
        const Trajet *t = noeud->GetTrajet();
        if(trajet->Equals(t))
        {
            return 1; // si un duplique trajet est trouvé
        }
        noeud = noeud->GetNoeudSuivant();
    }
    return 0; // si aucun duplique trajet n'est trouvé

}

bool Catalogue::RechercherTransitif(const char *depart, const char *arrive, char **visited, int &visitedCount, char **currentPath, int &pathCount, int &count) const
{
    if (visitedCount >= 100) // Assumption: there will be no more than 100 cities
    {
        return false;
    }

    visited[visitedCount] = new char[strlen(depart) + 1];
    strcpy(visited[visitedCount], depart);
    visitedCount++;

    currentPath[pathCount] = new char[strlen(depart) + 1];
    strcpy(currentPath[pathCount], depart);
    pathCount++;

    Noeud *noeud = liste->GetTete();
    bool found = false;

    while (noeud != nullptr)
{
    const Trajet *trajet = noeud->GetTrajet();

    if (!strcmp(trajet->GetDepart(), depart))
    {
        // Imprimez le trajet
        std::cout << "Trajet utilise : " << std::endl;
        trajet->Afficher();
        std::cout << std::endl;

        if (!strcmp(trajet->GetArrive(), arrive))
        {
            count++;
            found = true;
        }
        else
        {
            bool alreadyVisited = false;

            for (int i = 0; i < visitedCount; i++)
            {
                if (!strcmp(visited[i], trajet->GetArrive()))
                {
                    alreadyVisited = true;
                    break;
                }
            }

            if (!alreadyVisited)
            {
                // Ajoutez la ville à la liste des villes visitées avant d'appeler RechercherTransitif
                strcpy(visited[visitedCount], trajet->GetArrive());
                visitedCount++;

                if (RechercherTransitif(trajet->GetArrive(), arrive, visited, visitedCount, currentPath, pathCount, count))
                {
                    found = true;
                }

                // Supprimez la ville de la liste des villes visitées après l'appel à RechercherTransitif
                visitedCount--;
            }
        }
    }

    
    noeud = noeud->GetNoeudSuivant();
}
    delete[] visited[visitedCount - 1];
    visitedCount--;
    delete[] currentPath[pathCount - 1];
    pathCount--;

    return found;
}

void Catalogue::RechercherAvancee(char* debut, char* fin) const
{
    char *visited[100]; // Assumption: there will be no more than 100 cities
    int visitedCount = 0;
    char *currentPath[100]; // Assumption: there will be no more than 100 cities in a path
    int pathCount = 0;
    int count = 0;

    RechercherTransitif(debut, fin, visited, visitedCount, currentPath, pathCount, count);

    cout<<endl;
    std::cout << "Nombre de parcours possibles entre le lieu de depart et d'arrivee : " << count << std::endl;

    for (int i = 0; i < visitedCount; i++)
    {
        delete[] visited[i];
    }

    for (int i = 0; i < pathCount; i++)
    {
        delete[] currentPath[i];
    }
}

Catalogue::~Catalogue()
{
    delete liste;
    #ifdef MAP
        cout
            << "Appel au destructeur de <Catalogue>" << endl;
    #endif
    // Le destructeur de Catalogue libérera automatiquement la mémoire utilisée par la Liste
}
