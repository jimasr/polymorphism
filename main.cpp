#include <iostream>
#include <cstring>
#include <cstdlib>

#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR_CONSOLE "cls"
    #define PAUSE_COMMAND "pause"
#else
    #define CLEAR_CONSOLE "clear"
    #define PAUSE_COMMAND "read -p \"Appuyez sur une touche pour continuer . . .\""
#endif

#include "Catalogue.h"
#include "TrajetSimple.h"

using namespace std;

static void Message();
static void Pause();
static void Clear();

int main()
{
        
    //Clear();
    Message();
    Pause();

    char transport[100];
    char debut[100];
    char fin[100];
    int choix;

    Catalogue *cat = new Catalogue(); // Création d'une instance de la classe Catalogue

    do
    {
        //Clear();
        cout << "Menu :\n"
             << "\n"
             << "\t1: Rechercher un trajet simplement\n"
             << "\t2: Rechercher un trajet de manière avancée\n"
             << "\t3: Ajouter un trajet au catalogue\n"
             << "\t4: Afficher le catalogue\n"
             << "\t0: Quitter\n"
             << endl;

        cout << " > ";


        if (!(cin >> choix))
        {
            cin.clear();// Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            choix = -1; // Set to an invalid value to continue the loop
        }
        //Clear();

        switch (choix)
        {
            int parcours;

            case 0:
                break;
                
            case 1:
                cout << "Ville de départ : ";
                cin >> debut;
                cout << "Ville de fin : ";
                cin >> fin;

                parcours = cat->RechercherSimple(debut, fin);
                if (parcours == 0)
                {
                    cout << "Trajet non trouvé\n";
                }
                break;

            case 2:

                cout << "Ville de départ : ";
                cin >> debut;
                cout << "Ville de fin : ";
                cin >> fin;

                // Ajouter le code pour RechercherAvancee(debut, fin);
                break;

            case 3:
                int ajout;

                do
                {
                    cout << "Voulez-vous ajouter un trajet simple ou complexe ?\n"
                        << "\n"
                        << "\t1: Simple\n"
                        << "\t2: Complexe\n"
                        << "\t0: Menu\n"
                        << endl;
                        
                    cout << " > ";

                    if (!(cin >> ajout))
                    {
                        cin.clear();// Clear the error state
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                        ajout = -1; // Set to an invalid value to continue the loop
                    }
                    // Clear();

                    switch(ajout)
                    {
                        case 0:
                            break;
                        case 1:
                            cout << "Ville de départ : ";
                            cin >> debut;
                            cout << "Ville de fin : ";
                            cin >> fin;
                            cout << "Moyen de transport : ";
                            cin >> transport;

                            if (!(cat->VerifierDupliquerSimple(debut, fin, transport)))
                            {
                                TrajetSimple * trajet = new TrajetSimple(debut, fin, transport);
                                cat->Ajouter(trajet);
                            }
                            else
                            {
                                cout << "Trajet déjà existant\n";
                            }
                            break;
                        case 2:                            
                            break;

                        default:
                            cout << "Choix incorrect\n";
                    }

                } while (ajout != 0); 

                break;
            case 4:
                cat->AfficherCatalogue();
                break;

            default:
                cout << "Choix incorrect\n";
        }

        //Pause();

    } while (choix != 0);

    //Clear();

    cout << "Au revoir\n"
         << endl;

    delete cat;
    return 0;
}

static void Message()
{
    cout << "__________      .__                                    .__    .__                \n"
         << "\\______   \\____ |  | ___.__. _____   _________________ |  |__ |__| ______ _____  \n"
         << " |     ___/  _ \\|  |<   |  |/     \\_/ __ \\_  __ \\____ \\|  |  \\|  |/  ___//     \\ \n"
         << " |    |  (  <_> )  |_\\___  |  Y Y  \\  ___/|  | \\/  |_> >   Y  \\  |\\___ \\|  Y Y  \\\n"
         << " |____|   \\____/|____/ ____|__|_|  /\\___  >__|  |   __/|___|  /__/____  >__|_|  /\n\n\n\n";         
}

static void Pause()
{
    system(PAUSE_COMMAND);
}

static void Clear()
{
    system(CLEAR_CONSOLE);
}

