/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques




//-------------------------------------------- Constructeurs - destructeur



TrajetCompose::TrajetCompose (const LinkedList *l, const char *vD, const char *vA)
    : Trajet(vD, vA)

{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

    listTrajets = new LinkedList(l->GetHead(), l->GetTaille());

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    delete listTrajets;
    
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

