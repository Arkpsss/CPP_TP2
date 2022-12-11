/*************************************************************************
              TrajetSimple  -  Classe implémentant un trajet simple
                             -------------------
    début                : 28/11/2022
    copyright            : (C) 2022 par Julien Bondyfalat et 
                                        Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et 
                           gabriel.canaple@insa-lyon.f
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


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
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes privées

char* TrajetSimple::ToString() const 
// Algorithme :
// Concatène les caractéristiques du trajet en une seule chaine de
// caractères.
{

    char *res = new char[DESC + strlen(villeDepart) + strlen(villeArrivee) 
      + strlen(moyenTransport)];
    res[0] = '\0';

    strcat(res, "Ville de depart : ");
    strcat(res, villeDepart);
    strcat(res, "\nVille d'arrivee : ");
    strcat(res, villeArrivee);
    strcat(res, "\nMoyen de transport : ");
    strcat(res, moyenTransport);
    strcat(res, "\n");

    return res;

}
