#include <iostream>
using namespace std;

#include "TrajetSimple.h"
#include "Liste.h"


int main() {

    // Création d'un trajet simple
    TrajetSimple trajet1("A", "B", "MT1");
    TrajetSimple trajet2("A", "C", "MT2");

    Liste l;
    Liste c;

    l.Ajouter(trajet1);
    l.Ajouter(trajet2);

    l.Afficher();
    c.Afficher();

    // Affichage du trajet simple
    cout << "Affichage du trajet simple : ";
    trajet1.Afficher();
    cout << endl;

    // Affichage des informations sur le trajet simple
    cout << "Départ : " << trajet1.GetDepart() << endl;
    cout << "Arrivée : " << trajet1.GetArrive() << endl;
    cout << "Transport : " << trajet1.GetTransport() << endl;

    return 0;
}

