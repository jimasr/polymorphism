#if ! defined ( TRAJET_H )
#define TRAJET_H

class Trajet
{
public:

    virtual void Afficher () const = 0;
    std::string getDepart();
    std::string getArrive();
    Trajet(std::string depart, std::string arrive);
    virtual ~Trajet ( );



protected:
    std::string depart;
    std::string arrive;

};


#endif
