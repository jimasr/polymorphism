#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

#include "Trajet.h"
#include "TrajetSimple.h"
#include "Liste.h"

class TrajetCompose : public Trajet
{
	public:
		TrajetCompose(const char *depart, const char *arrive, Liste *liste);
		virtual ~TrajetCompose();
		Liste *GetListe() const;
		virtual bool Equals(const Trajet *trajet) const;
		virtual void Afficher() const;

	protected:
		Liste *liste;
};

#endif
