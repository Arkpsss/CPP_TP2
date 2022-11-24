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

char* TrajetSimple::ToString() const {

    char *res = new char[DESC + strlen(villeDepart) + strlen(villeArrivee) + strlen(moyenTransport)];
    res[0] = '\0';

    strcat(res, "Ville de depart : ");
    strcat(res, villeDepart);
    strcat(res, "\nVille d'arrivee : ");
    strcat(res, villeArrivee);
    strcat(res, "\nMoyen de transport : ");
    strcat(res, moyenTransport);
    strcat(res, "\n");

    //printf("%s\n\n\n", res);

    return res;

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

    description = ToString();

} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple () {
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete [] moyenTransport;
    //delete [] description;

} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

