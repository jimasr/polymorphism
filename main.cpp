#include <iostream>
using namespace std;

#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

int main()
{

    Catalogue catalogue;

    // Création d'un trajet simple
    TrajetSimple *trajet1 = new TrajetSimple("A", "B", "MT1");
    TrajetSimple *trajet2 = new TrajetSimple("A", "C", "MT2");

    Liste l;

    l.Ajouter(trajet1);
    l.Ajouter(trajet2);

    TrajetCompose *trajet3 = new TrajetCompose("A", "C", &l);

    l.Afficher();

    catalogue.Ajouter(trajet1);
    catalogue.Ajouter(trajet2);
    catalogue.Ajouter(trajet3);

    cout << "Affichage du catalogue : ";
    catalogue.AfficherCatalogue();
    cout << endl;

    // Affichage du trajet simple
    cout << "Affichage du trajet simple : ";
    trajet1->Afficher();
    cout << endl;

    // Affichage du trajet compose
    cout << "Affichage du trajet compose : ";
    trajet3->Afficher();
    cout << endl;

    return 0;
}
