/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const {

    cout << "Ville de départ : " << villeDepart << endl;
    cout << "Ville d'arrivee : " << villeArrivee << endl;
    cout << "Moyen de transport : " << moyenTransport << endl;

}


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char *vD, const char *vA, const char *mt)
    : Trajet(vD, vA)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

    moyenTransport = new char[strlen(mt) + 1];
    strcpy(moyenTransport, mt);

} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple () {
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete [] moyenTransport;

} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

