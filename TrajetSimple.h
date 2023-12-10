/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#ifndef TRAJETSIMPLE_H
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

