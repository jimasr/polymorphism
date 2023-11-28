#include <iostream>
using namespace std;

#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Liste.h"


int main() {

    // Création d'un trajet simple
    TrajetSimple trajet1("A", "B", "MT1");
    TrajetSimple trajet2("A", "C", "MT2");

    Liste l;

    l.Ajouter(trajet1);
    l.Ajouter(trajet2);

    TrajetCompose trajet3("A", "C", &l);

    l.Afficher();

    // Affichage du trajet simple
    cout << "Affichage du trajet simple : ";
    trajet1.Afficher();
    cout << endl;

    // Affichage du trajet compose
    cout << "Affichage du trajet compose : ";
    trajet3.Afficher();
    cout << endl;

    return 0;
}

