/*************************************************************************
                           Element  -  Classe implémentant une liste chaînée
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr, julien.bodyfalat@insa-lyon.fr
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
Trajet *Element::GetTrajet () const
{
     return trajet;
} //----- Fin de GetTrajet


Element *Element::GetNext () const
{
    return next;
} //----- Fin de GetNext


void Element::SetNext(Element *e) {
    this->next = e;
} //----- Fin de SetNext

//-------------------------------------------- Constructeurs - destructeur




Element::Element (Trajet *trajet, Element *next) : trajet(trajet), next(next)
// Algorithme :
// Met à this->next à next et this->trajet à trajet.
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
    delete(trajet);
} //----- Fin de ~Element


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
