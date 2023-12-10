/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#ifndef TRAJETCOMPOSE_H
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
