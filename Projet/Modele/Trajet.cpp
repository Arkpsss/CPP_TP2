/*************************************************************************
                      TrajetCompose  -  Classe implémentant les trajets
                                        du TP2
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr,
                           julien.bodyfalat@insa-lyon.fr
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
    villeDepart = new char[strlen(vD)+1];
    villeArrivee = new char[strlen(vA) + 1];

    strcpy(villeDepart, vD);
    strcpy(villeArrivee, vA);

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

