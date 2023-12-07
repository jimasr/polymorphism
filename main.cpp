#include <iostream>
#include <cstring>
#include "Catalogue.h"
#include "TrajetSimple.h"

using namespace std;

int main()
{
    char lecture[100];
    Catalogue *cat = new Catalogue(); // Création d'une instance de la classe Catalogue
    int choix;

    do
    {
        cout << "Menu :\n"
             << "1: Rechercher un trajet simplement\n"
             << "2: Rechercher un trajet de manière avancée\n"
             << "3: Ajouter un trajet au catalogue\n"
             << "4: Afficher le catalogue\n"
             << "0: Quitter\n"
             << endl;

        cin >> choix;

        switch (choix)
        {
        case 0:
            break;
        case 1:
            cout << "Effectue bien le cas 1\n"
                 << endl;

            char debut1[100];
            char fin1[100];
            cout << "Ville de départ : ";
            cin >> debut1;
            cout << "Ville de fin : ";
            cin >> fin1;
            int r;
            r = cat->RechercherSimple(debut1, fin1);
            if (r == 0)
            {
                cout << "Pas dans la liste " << endl;
            }
            break;
        case 2:
            cout << "Effectue bien le cas 2\n"
                 << endl;

            char debut2[100];
            char fin2[100];
            cout << "Ville de départ : ";
            cin >> debut2;
            cout << "Ville de fin : ";
            cin >> fin2;
            // Ajouter le code pour RechercherAvancee(debut2, fin2);
            break;
        case 3:
            cout << "Effectue bien le cas 3\n"
                 << endl;

            cin >> lecture;
            if (strcmp(lecture, "Complexe") == 0)
            {
                // TrajetComplexe * t;
            }
            else if (strcmp(lecture, "Simple") == 0)
            {
                char debut3[100];
                char fin3[100];
                char Moyen[100];
                cout << "Ville de départ : ";
                cin >> debut3;
                cout << "Ville de fin : ";
                cin >> fin3;
                cout << "Moyen de transport : ";
                cin >> Moyen;

                if (cat->RechercherSimple2(debut3, fin3, transport))
                {
                    cout << "Déjà présent\n";
                    break;
                }
                else
                {
                    TrajetSimple *trajet1 = new TrajetSimple(debut3, fin3, Moyen);
                    cat->Ajouter(trajet1);
                }
            }
            break;
        case 4:
            cout << "Effectue bien le cas 4\n"
                 << endl;

            cat->AfficherCatalogue();
            break;
        default:
            cout << "Choix incorrect\n";
            continue; // Revenir au menu
        }
    } while (choix != 0);

    cout << "Au revoir\n"
         << endl;
    delete cat;
    return 0;
}
