#include <iostream>
#include <cstring>
#include "Catalogue.h"
#include "TrajetSimple.h"
// Assurez-vous que le chemin du fichier d'en-tête est correct

using namespace std;

int main()
{
    char lecture[100];
    Catalogue *cat = new Catalogue(); // Création d'une instance de la classe Catalogue
    while (1)
    {
        cout << "menu:\n"
             << endl;
        cout << "\t1: rechercher un trajet simplement\n"
             << endl;
        cout << "\t2: rechercher un trajet de manière avancée\n"
             << endl;
        cout << "\t3: ajouter un trajet au catalogue\n"
             << endl;
        cout << "\t4: afficher le catalogue\n"
             << endl;
        cout << "\t0: quitter\n"
             << endl;
        int choix;

        cin >> choix;
        switch (choix)
        {
        case 0:
            goto fin;
            break;
        case 1:
            cout << "Effectue bien le cas 1\n"
                 << endl;

            char debut1[100];
            char fin1[100];
            cout << "ville de départ : " << endl;
            cin >> debut1;
            cout << "ville de fin : " << endl;
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
            cout << "ville de départ : " << endl;
            cin >> debut2;
            cout << "ville de fin : " << endl;
            cin >> fin2;
            break;
            // cat->RechercherAvancee(debut, fin);
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
                cout << "ville de départ : " << endl;
                cin >> debut3;
                cout << "ville de fin : " << endl;
                cin >> fin3;
                cout << "Moyen de transport" << endl;
                cin >> Moyen;

                /* il faut faire une recherche dans la liste des trajet dispo s'ils sont deja la alors il ne faut pas ajouter le schema au catalogue d*/
                if (cat->RechercherSimple2(debut3, fin3))
                {
                    cout << "Deja present" << endl;
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
        default:
            printf("choix incorrect\n");
            continue; // revenir au menu
        }
        break;
    }

fin:
    cout << "au revoir\n"
         << endl;
    delete cat;
    return 0;
}
