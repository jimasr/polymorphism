#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H
#include "Trajet.h"

class TrajetSimple : public Trajet
{
public:
    TrajetSimple (string depart, string arrive, string transport);
    virtual ~TrajetSimple( );
    string GetTransport();
    virtual void Afficher() const;


protected:
    string transport;
};


#endif

