#include <iostream>
using namespace std;

#include "Ensemble.h"

//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble( unsigned int cardMax)
{
#ifdef MAP
    cout << "Appel au constructeur1 de <Ensemble>" << "\r\n";
#endif

cardmax=cardMax;
cardActuel=0;

if (cardMax != 0)
{
    tab = new int[cardmax];
}
else
{
    tab = NULL;
}

}

Ensemble::~Ensemble ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << "\r\n";
#endif
delete[] tab;
}

void Ensemble::Afficher()
{
    cout << cardActuel << "\r\n";
    cout << cardmax << "\r\n";
    
    if (cardActuel == 0)
    {
        cout << "{}" << "\r\n";
    }
    else if (cardActuel == 1)
    {
        cout << "{" << tab[0] << "}" << "\r\n";
    }
    else
    {
        for (int i = 0; i < cardActuel - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < cardActuel; j++)
            {
                if (tab[j] < tab[min])
                {
                    min = j;
                }
            }

            int temp = tab[i];
            tab[i] = tab[min];
            tab[min] = temp;
        }

        cout << "{";
        for (int i = 0; i < cardActuel - 1; i++)
        {
            cout << tab[i] << ",";
        }
        cout << tab[cardActuel - 1] << "}" << "\r\n";
    }
}


Ensemble::Ensemble ( int t [ ], unsigned int nbElements )
{
#ifdef MAP
    cout << "Appel au constructeur2 de <Ensemble>" << "\r\n";
#endif
cardmax=nbElements;

if (cardmax==0)
{
    cardActuel=0;
    tab = NULL;
}
else
{
    tab = new int[cardmax];
    cardActuel=1;
    tab[0]=t[0];
    
    int i;
    int j;
    
    for (i=1; i<cardmax; i++)
    {int res = 1;
        for (j=0; j<cardActuel; j++)
        {
            if (tab[j]==t[i])
            {
                res = 0;
            }
        }
        
        if (res==1)
        {
            tab[cardActuel]=t[i];
            cardActuel++;
        }
    
    }
}
}

bool Ensemble::EstEgal ( const Ensemble & unEnsemble ) const
{
	if(unEnsemble.cardActuel != cardActuel)
	{
	     return false;
	}
	else
	{
	     int i;
	     int j;
	     for (i=0; i<cardActuel; i++)
	     {
	     int c=0;
	     	for (j=0; j<cardActuel; j++)
	     	{
	     		if (unEnsemble.tab[j]==tab[i])
	     		{c=1;}
	     	}
	     if (c==0)
	     {return false;}
	     }
	return true;
	}
}

crduEstInclus Ensemble::EstInclus(const Ensemble &unEnsemble) const
{
int i;
int j;

    if (EstEgal(unEnsemble)) {
        return INCLUSION_LARGE;
    } else if (unEnsemble.cardActuel < cardActuel) {
        return NON_INCLUSION;
    } else {
        for (i = 0; i < cardActuel; i++) {
            bool found = false;
            for (j = 0; j < unEnsemble.cardActuel; j++) {
                if (unEnsemble.tab[j] == tab[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return NON_INCLUSION;
            }
        }
        return INCLUSION_STRICTE;
    }
}

crduAjouter Ensemble::Ajouter( int aAjouter )
{
int i;
for (i=0;i<cardActuel;i++)
   if (tab[i]==aAjouter)
   {
   return DEJA_PRESENT;
   }

if (cardActuel == cardmax)
{return PLEIN;
}

else
{
tab[cardActuel]=aAjouter;
cardActuel++;
return AJOUTE;
}
}

unsigned int Ensemble::Ajuster ( int delta )
{
int i;
if (delta==0)
{
return cardmax;
}
else if (delta>0)
{
int * temp = new int[cardmax+delta];
for (i=0; i<cardActuel;i++)
{
temp[i]=tab[i];
}
delete [] tab;
tab=temp;
cardmax=cardmax+delta;
return cardmax;
}
else
{
if (cardmax+delta>cardActuel)
{
int * temp = new int[cardmax-delta];
for (i=0; i<cardActuel;i++)
{
temp[i]=tab[i];
}
delete [] tab;
tab=temp;
cardmax=cardmax+delta;
return cardmax;
}
else
{
cardmax=cardActuel;
return cardmax;
}
}
}

bool Ensemble::Retirer ( int element )
{
if (cardmax==0)
{
    cardmax=cardActuel;
    return false;
}
else
{
    int i;
    for (i=0;i<cardActuel;i++)
    {
        if (tab[i]==element)
        {
            tab[i]=tab[cardActuel-1];
            cardActuel--;
            cardmax=cardActuel;
            return true;
        }
    }
    cardmax=cardActuel;
    return false;
}

}

unsigned int Ensemble::Retirer ( const Ensemble & unEnsemble ) //à voir
{
int i;
int j;
int retirer=0;
int card=cardmax;

for (i=0;i<cardActuel;i++)
    {
        for (j=0;j<unEnsemble.cardActuel;j++)
        {
            if (unEnsemble.tab[j]==tab[i])
            {
                Retirer(tab[i]);
                i=i-1;
                retirer++;
                break;
            }
        }
}
cardmax=card;
return retirer;
}

int Ensemble::Reunir(const Ensemble &unEnsemble) // à voir
{
    if (EstInclus(unEnsemble) == INCLUSION_STRICTE || EstInclus(unEnsemble) == INCLUSION_STRICTE)
    {
        return 0;
    }
    else
    {
        int i;
        int j;
        
        int* ajout = new int[unEnsemble.cardActuel];
        int a = 0;
        
        for (i = 0; i < unEnsemble.cardActuel; i++)
        {
            int res = 1;
            for (j = 0; j < cardActuel; j++)
            {
                if (tab[j] == unEnsemble.tab[i])
                {
                    res = 0;
                    break;
                }
            }
            if (res == 1)
            {
                ajout[a] = unEnsemble.tab[i];
                a++;
            }
        }
        
        if (cardmax - cardActuel >= a)
        {
            for (i = 0; i < a; i++)
            {
                tab[cardActuel] = ajout[i];
                cardActuel++;
            }
            delete[] ajout;
            return a;
        }
        else
        {
            int* temp = new int[cardActuel + a];
            for (i = 0; i < cardActuel; i++)
            {
                temp[i] = tab[i];
            }
            delete[] tab;
            tab = temp;
            
            for (i = 0; i < a; i++)
            {
                tab[cardActuel] = ajout[i];
                cardActuel++;
            }
            
            cardmax = cardActuel;
            delete[] ajout; // Libérer la mémoire allouée dynamiquement.
            return -a;
        }
    }
}


/*unsigned int Ensemble::Intersection(const Ensemble &unEnsemble) //à refaire
{
    unsigned int elementsSupprimes = 0; // Pour compter le nombre d'éléments supprimés.
    
    int i;
    int j;

    for (i = 0; i < cardActuel; i++)
    {
        bool elementCommun = false;

        for (j = 0; j < unEnsemble.cardActuel; j++)
        {
            if (tab[i] == unEnsemble.tab[j])
            {
                elementCommun = true;
                break;
            }
        }

        if (!elementCommun)
        {
            tab[i] = tab[cardActuel - 1];
            cardActuel--;

            elementsSupprimes++;
            i--;
        }
    }
    Ajuster(cardActuel - cardmax);

    return elementsSupprimes;}*/


unsigned int Ensemble::Intersection ( const Ensemble & unEnsemble )
{
    int i;
    int j;
    
    int * val = new int[cardActuel];
    int a=0;
    
    int nb;
    
    for (i=0;i<unEnsemble.cardActuel;i++)
    {
        for (j=0;j<cardActuel;j++)
        {
            if (unEnsemble.tab[i]==tab[j])
            {
                
                val[a]=unEnsemble.tab[i];
                a++;
                break;
            }
        }
    }
    
    nb=cardActuel-a;
    
    if (a==0)
    {
        delete [] tab;
        tab = NULL;
        cardActuel=0;
        cardmax=0;
        delete[] val;
        return nb;
    }
    else
    {
        int * temp = new int[a];
        for (i=0; i<a; i++)
        {
            temp[i]=val[i];
        }
        
        delete [] tab;
        tab = temp;
        cardActuel=a;
        cardmax=a;
        delete[] val;
        return nb;
    }
    
    
}


