/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#ifndef TRAJET_H
#define TRAJET_H

class Trajet
{
public:
    virtual void Afficher() const {}; // Add function definition for 'Afficher'
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
