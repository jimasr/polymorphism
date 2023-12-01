#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

#include "Trajet.h"
#include "Liste.h"

class TrajetCompose : public Trajet
{
public:
	TrajetCompose(const char *depart, const char *arrive, Liste *liste);
	virtual void Afficher() const;
	Liste *GetListe();
	virtual ~TrajetCompose();

protected:
	Liste *liste;
};

#endif
