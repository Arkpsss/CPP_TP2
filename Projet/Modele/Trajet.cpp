/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques




//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet(const char *vD, const char *vA) {

    if (vD != NULL && vA != NULL) {
        villeDepart = new char[strlen(vD)+1];
        villeArrivee = new char[strlen(vA) + 1];

        strcpy(villeDepart, vD);
        strcpy(villeArrivee, vA);
    }

    description = NULL;

    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
}
// Mode d'emploi :
// Initialise les attributs de la classe (2 tableaux dynamiques de char).

Trajet::~Trajet () {

    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif

    delete [] villeArrivee;
    delete [] villeDepart;

    if (description != NULL) {
        delete [] description;
    }
    
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Trajet::SetVilleDepart(const char* vD) {

    if (vD == NULL) {
        return;
    }

    if (villeDepart != NULL) {
        delete [] villeDepart;
    }
    
    villeDepart = new char[strlen(vD)+1];
    strcpy(villeDepart, vD);

}


void Trajet::SetVilleArrivee(const char* vA) {
    
    if (vA == NULL) {
        return;
    }

    if (villeArrivee != NULL) {
        delete [] villeArrivee;
    }

    villeArrivee = new char[strlen(vA) + 1];
    strcpy(villeArrivee, vA);
}
