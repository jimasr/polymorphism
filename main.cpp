#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits>

using namespace std;

#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR_CONSOLE "cls"
    #define PAUSE_COMMAND "pause"
#else
    #define CLEAR_CONSOLE "clear"
    #define PAUSE_COMMAND "read -p \"Appuyez sur une touche pour continuer . . .\""
#endif

#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "Catalogue.h"
#include "Liste.h"

static void Message();
static void Pause();
static void Clear();

int main()
{
    Clear();
    Message();
    Pause();
    Clear();

    char transport[100];
    char debut[100];
    char fin[100];
    int choix;

    Catalogue *cat = new Catalogue(); // Creation d'une instance de la classe Catalogue

    do
    {
        //Clear();
        cout << "Menu :\n"
             << "\n"
             << "\t1: Rechercher un trajet simplement\n"
             << "\t2: Rechercher un trajet de maniere avancee\n"
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
                cout << "Ville de depart\n"
                    << " > ";
                cin >> debut;

                cout << "Ville de fin\n"
                    << " > ";
                cin >> fin;

                parcours = cat->RechercherSimple(debut, fin);
                if (parcours == 0)
                {
                    cout << "Trajet non trouve\n";
                }
                break;

            case 2:

            cout << "Ville de depart\n"
            << " > ";
            cin >> debut;
    
            cout << "Ville de fin\n"
            << " > ";
            cin >> fin;

            cat->RechercherAvancee(debut, fin);
            cout << "\n";
            break;

            case 3 : {
                
                int ajout = 0;

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
                        {
                            cout << "Ajout d'un trajet simple :\n"
                                << "\n"
                                << "Ville de depart\n"
                                << " > ";
                            cin >> debut;

                            cout << "Ville de fin\n"
                                << " > ";
                            cin >> fin;

                            cout << "Moyen de transport\n"
                                << " > ";
                            cin >> transport;

                            TrajetSimple * trajet = new TrajetSimple(debut, fin, transport);
                            cout << endl;

                            if (!cat->VerifierDupliquer(trajet))
                            {
                                cat->Ajouter(trajet);
                            }
                            else
                            {
                                cout << "Trajet simple deja existant\n";
                            }
                        }
                            break;
                        case 2 : 
                        {

                            int flag = 0;
                            int count = 0;

                            TrajetSimple * trajet;
                            Liste * liste = new Liste();

                            char debutIndicator[100];
                            char finIndicator[100];


                            cout << "Ajout d'un trajet complexe : \n"
                                << "\n";

                                cout << "Ville de depart\n"
                                    << " > ";
                                cin >> debut;

                                cout << "Ville de fin temporaire\n"
                                    << " > ";
                                cin >> fin;

                                cout << "Moyen de transport\n"
                                    << " > ";
                                cin >> transport;

                                trajet = new TrajetSimple(debut, fin, transport);
                                liste->Ajouter(trajet);

                                cout << "Voulez-vous ajouter un autre trajet ?\n"
                                    << "\n"
                                    << "\t1: Oui\n"
                                    << "\t2: Non\n"
                                    << "\t3: Annuler\n"
                                    << endl;

                                cout << " > ";
                                cin >> flag;

                                if(count == 0)
                                {
                                    strcpy(debutIndicator, debut);
                                }

                                if(flag == 2) {
                                    strcpy(finIndicator, fin);
                                }

                                count++;
                            
                            while(flag==1) 
                            {
                                cout << "Ajout d'un trajet complexe : \n"
                                << "\n";

                                strcpy(debut,fin);

                                cout << "Nouvelle ville de fin\n"
                                    << " > ";
                                cin >> fin;

                                cout << "Moyen de transport\n"
                                    << " > ";
                                cin >> transport;

                                trajet = new TrajetSimple(debut, fin, transport);
                                liste->Ajouter(trajet);

                                cout << "Voulez-vous ajouter un autre trajet ?\n"
                                    << "\n"
                                    << "\t1: Oui\n"
                                    << "\t2: Non\n"
                                    << "\t3: Annuler\n"
                                    << endl;

                                cout << " > ";
                                cin >> flag;

                                if(count == 0)
                                {
                                    strcpy(debutIndicator, debut);
                                }

                                if(flag == 2) {
                                    strcpy(finIndicator, fin);
                                }

                                count++;
                                
                            }
                            TrajetCompose * trajetCompose = new TrajetCompose(debutIndicator, finIndicator, liste);

                            if(flag != 3) {
                                if (!cat->VerifierDupliquer(trajetCompose)) 
                                {
                                    cat->Ajouter(trajetCompose);
                                } 
                                else 
                                {
                                    cout << "Trajet compose deja existant\n";
                                }
                            } else {
                                cout << "Ajout annule\n";
                            }
                        }
                            break;

                        default:
                            cout << "Choix incorrect\n";
                    }
                    if(ajout != 0)
                    Pause();

                } while (ajout != 0); 
                
            }

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

