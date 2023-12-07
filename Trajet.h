#if !defined(TRAJET_H)
#define TRAJET_H

class Trajet
{
public:
    virtual void Afficher() const = 0;
    char *GetDepart();
    char *GetArrive();
    virtual ~Trajet();

protected:
    char *depart;
    char *arrive;
    Trajet(const char *depart, const char *arrive);
};

#endif
