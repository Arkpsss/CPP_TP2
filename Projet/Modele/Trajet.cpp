/*************************************************************************
            Trajet  -  Classe représentant un trajet général
                           -------------------
    début                : 28/11/2022
    copyright            : (C) 2022 par Julien Bondyfalat et 
                                        Gabriel Canaple
    e-mail               : gabriel.canaple@insa-lyon.fr, 
                           julien.bondyfalat@insa-lyon.fr
*************************************************************************/

//------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ---------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel

#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet(const char *vD, const char *vA) 
{
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif

    if (vD != NULL && vA != NULL) {
        villeDepart = new char[strlen(vD)+1];
        villeArrivee = new char[strlen(vA) + 1];

        strcpy(villeDepart, vD);
        strcpy(villeArrivee, vA);
    }
    else {
        villeDepart = NULL;
        villeArrivee = NULL;
    }

    description = NULL;

    
} //---- Fin du constructeur de Trajet

Trajet::~Trajet () 
{
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif

    delete [] villeArrivee;
    delete [] villeDepart;

    if (description != NULL) {
        delete [] description;
    }
} //---- Fin du destructeur de Trajet

//-------------------------------------------------------------- PROTECTED

//----------------------------------------------------- Méthodes protégées

void Trajet::SetVilleDepart(const char* vD) 
{
    if (vD == NULL) {
        return;
    }

    if (villeDepart != NULL) {
        delete [] villeDepart;
    }
    
    villeDepart = new char[strlen(vD)+1];
    strcpy(villeDepart, vD);
} //---- Fin de SetVilleDepart


void Trajet::SetVilleArrivee(const char* vA) 
{
    if (vA == NULL) {
        return;
    }

    if (villeArrivee != NULL) {
        delete [] villeArrivee;
    }

    villeArrivee = new char[strlen(vA) + 1];
    strcpy(villeArrivee, vA);
} //---- Fin de SetVilleArrivee
