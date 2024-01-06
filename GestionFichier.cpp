/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 16 decembre 2023
    copyright            : (C) 2023 par H. ASRI
    e-mail               : hazim.asri@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GestionFichier> (fichier GestionFichier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "GestionFichier.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Liste.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void GestionFichier::ChargerFichier(Catalogue **catalogue, const string &nomFichier)
{
	OuvrirFichier(nomFichier);
	string line;

	while(getline(fic, line)) 
	{
		//get type
		size_t pos = 0;
		string typeDelimiter = "::";
		string partDelimiter = ":";
		string trajetDelimiter = ",";

		pos = line.find(typeDelimiter);
		char type = line.substr(0, pos).at(0);
		line.erase(0, pos + typeDelimiter.length());

		switch (type) {
			case 'S' : {
				pos = line.find(partDelimiter);
				string depart = line.substr(0, pos);
				line.erase(0, pos + partDelimiter.length());

				pos = line.find(partDelimiter);
				string arrive = line.substr(0, pos);
				line.erase(0, pos + partDelimiter.length());

				string transport = line;

				TrajetSimple * trajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());

				(*catalogue)->Ajouter(trajetSimple);
			}

			break;

			case 'C' : {
				pos = line.find(partDelimiter);
				string depart = line.substr(0, pos);
				line.erase(0, pos + partDelimiter.length());

				Liste * liste = new Liste();
				string avant = depart;

				while ((pos = line.find(trajetDelimiter)) != string::npos) {
					string currentLine = line.substr(0, pos);

					size_t posPart = currentLine.find(partDelimiter);
					string arrive = currentLine.substr(0, posPart);
					currentLine.erase(0, posPart + partDelimiter.length());

					string transport = currentLine;

					TrajetSimple * trajetSimple = new TrajetSimple(avant.c_str(), arrive.c_str(), transport.c_str());

					avant = arrive;
					liste->Ajouter(trajetSimple);

					line.erase(0, pos + partDelimiter.length());
				}

				//EOL treatment
				size_t posPart = line.find(partDelimiter);
				string arrive = line.substr(0, posPart);
				line.erase(0, posPart + partDelimiter.length());
				string transport = line;
				
				TrajetSimple * trajetSimple = new TrajetSimple(avant.c_str(), arrive.c_str(), transport.c_str());
				liste->Ajouter(trajetSimple);
	
				TrajetCompose * trajetCompose = new TrajetCompose(depart.c_str(), arrive.c_str(), liste);

				(*catalogue)->Ajouter(trajetCompose);
			}

			break;
			
			default:
				break;
		}
	}

	FermerFichier();
}

//------------------------------------------------------------------ PRIVE

bool GestionFichier::OuvrirFichier(const string &nomFichier) 
{
	fic.open (nomFichier); // tentative d’ouverture du fichier test.txt
	if ((fic.rdstate() & ifstream::failbit) != 0 )
	{
		cerr << "Erreur d'ouverture de " << nomFichier << endl;
		return false;
	}
	return true;
}

void GestionFichier::FermerFichier()
{
	fic.close();
}

//----------------------------------------------------- Méthodes protégées
