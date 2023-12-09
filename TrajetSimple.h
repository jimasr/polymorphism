#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

#include "Trajet.h"

class TrajetSimple : public Trajet {
    public:
        TrajetSimple (const char* depart, const char* arrive, const char* transport);
        virtual ~TrajetSimple( );
        char* GetTransport() const;
        virtual void Afficher() const;
        virtual bool Equals(const Trajet *trajet) const;

    protected:
        char* transport;
};


#endif

