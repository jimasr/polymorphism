#if ! defined ( TRAJET_H )
#define TRAJET_H

class Trajet {
    public:
        // virtual void Afficher () const = 0;
        const char* GetDepart();
        const char* GetArrive();
        
        virtual ~Trajet ();

    protected:
        Trajet(const char * depart, const char * arrive);

        const char* depart;
        const char* arrive;
};

#endif
