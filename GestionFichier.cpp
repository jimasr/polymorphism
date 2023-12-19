/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "GestionFichier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void GestionFichier::ChargerFichier(Catalogue **catalogue, const string &nomFichier)
{
	// OuvrirFichier(nomFichier);

	// string line;
	// char car;

	// while(getline(fic, line)) {

	// 	istringstream issPrimary(line);
	// 	char type;
	// 	char delimiter = ':';

	// 	string depart;
	// 	string arrive;
	// 	string transport;

	// 	string token;
	// 	string buffer;

	// 	if(issPrimary >> type >> delimiter >> buffer) {
	// 		if(type == 'S') {
	// 			istringstream issSimple(buffer);
				
	// 			if(issSimple >> depart >> delimiter >> arrive >> delimiter >> transport) {
	// 				TrajetSimple *trajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
	// 				catalogue->Ajouter(trajetSimple);
	// 				delete trajetSimple;
	// 			}
				
	// 		} 

	// 		if(type == 'C') {
	// 			istringstream issCompose(buffer);
	// 			int count = 0;
	// 			while(issCompose >> token >> delimiter) {
					
	// 			}
				
	// 		}
	// 	}

	// FermerFichier();

	OuvrirFichier(nomFichier);

	string line;

	while(getline(fic, line)) {

			std::istringstream iss(line);
			char delimiter = ':';
			string depart;
			string arrive;
			string transport;
			
			string buff;

		while(iss >> buff) {

			cout << buff;

			if(buff == "S") {
				if(iss >> depart >> delimiter >> arrive >> delimiter >> transport >> delimiter) {
					TrajetSimple * trajetSimple = new TrajetSimple(depart.c_str(), arrive.c_str(), transport.c_str());
					trajetSimple->Afficher();
					(*catalogue)->Ajouter(trajetSimple);
				}
			} else if(buff == "C") {
				int numTrajets;
				
				if(iss >> depart >> delimiter >> numTrajets >> delimiter) {
					Liste * liste = new Liste();
					string arrivePrecedent = depart;

					for(int i = 0; i < numTrajets; i++) {

						if(iss >> arrive >> delimiter >> transport >> delimiter) {
							TrajetSimple * trajetSimple = new TrajetSimple(arrivePrecedent.c_str(), arrive.c_str(), transport.c_str());
							liste->Ajouter(trajetSimple);
							arrivePrecedent = arrive;
						}
					}

					TrajetCompose * trajetCompose = new TrajetCompose(depart.c_str(), arrivePrecedent.c_str(), liste);
					trajetCompose->Afficher();
					(*catalogue)->Ajouter(trajetCompose);
				}
			}
		}
	}

	






	FermerFichier();
}

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

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
