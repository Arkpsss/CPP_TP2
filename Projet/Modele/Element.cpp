/*************************************************************************
                 Element  -  Classe implémentant un maillon de 
                             la liste chaînée
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr, 
                           julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Element> (fichier Element.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Element.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur




Element::Element (Trajet *trajet, Element *next, bool _deleteTrajet) : 
trajet(trajet), next(next), deleteTrajet(_deleteTrajet)
// Algorithme :
// Initialise chacun des attributs
{
#ifdef MAP
    cout << "Appel au deuxième constructeur de <Element>" << endl;
#endif
} //----- Fin de Element

Element::~Element ( )
// Algorithme :
// Désalloue la zone mémoire du trajet
{
#ifdef MAP
    cout << "Appel au destructeur de <Element>" << endl;
#endif
    if (deleteTrajet)
      delete(trajet);
} //----- Fin de ~Element


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
