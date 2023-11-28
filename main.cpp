#include <iostream>
#include "TrajetSimple.h"
using namespace std;

int main() {
    // Création d'un trajet simple
    TrajetSimple trajetSimple("A", "B", "MT1");

    // Affichage du trajet simple
    std::cout << "Affichage du trajet simple : ";
    trajetSimple.Afficher();
    std::cout << std::endl;

    // Affichage des informations sur le trajet simple
    std::cout << "Départ : " << trajetSimple.getDepart() << std::endl;
    std::cout << "Arrivée : " << trajetSimple.getArrive() << std::endl;
    std::cout << "Transport : " << trajetSimple.getTransport() << std::endl;

    return 0;
}

