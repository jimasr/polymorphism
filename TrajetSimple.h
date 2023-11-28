#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

#include "Trajet.h"

class TrajetSimple : public Trajet {
    public:
        TrajetSimple (const char* depart, const char* arrive, const char* transport);
        virtual ~TrajetSimple( );
        const char* GetTransport();
        virtual void Afficher() const;


    protected:
        const char* transport;
};


#endif

