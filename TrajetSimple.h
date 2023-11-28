#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H
#include "Trajet.h"

class TrajetSimple : public Trajet
{
public:
    TrajetSimple (std::string depart, std::string arrive, std::string transport);
    virtual ~TrajetSimple( );
    std::string getTransport();
    virtual void Afficher() const;


protected:
    std::string transport;
};


#endif

