#if !defined(TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H

#include "Trajet.h"
#include <cstring>

class TrajetSimple : public Trajet 
{
    public:
        TrajetSimple (const char* depart, const char* arrive, const char* transport);
        virtual ~TrajetSimple();
        char* GetTransport() const;
        virtual bool Equals(const Trajet *trajet) const;
        virtual void Afficher() const;
        const char* GetMoyenTransport() const;

    protected:
        char* transport;
};


#endif

