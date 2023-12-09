#if !defined(TRAJET_H)
#define TRAJET_H

class Trajet
{
public:
    virtual void Afficher() const;
    char *GetDepart() const;
    char *GetArrive() const;
    virtual bool Equals(const Trajet *trajet) const;
    virtual ~Trajet();

protected:
    char *depart;
    char *arrive;
    Trajet(const char *depart, const char *arrive);
};

#endif
