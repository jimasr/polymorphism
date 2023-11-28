#if ! defined ( TRAJET_H )
#define TRAJET_H

class Trajet {
    public:
        // virtual void Afficher () const = 0;
        string GetDepart();
        string GetArrive();
        
        virtual ~Trajet ();

    protected:
        Trajet(string depart, string arrive);

        string depart;
        string arrive;
        //commentaire
};

#endif
