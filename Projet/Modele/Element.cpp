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
// Algorithme :
//
{
     return trajet;
} //----- Fin de GetTrajet

void Element::SetTrajet (Trajet *trajet)
// Algorithme :
//
{
    this->trajet=trajet;
} //----- Fin de Méthode

Element *Element::GetNext () const
// Algorithme :
//
{
    return next;
} //----- Fin de GetTrajet

void Element::SetNext (Element *next)
// Algorithme :
//
{
this->next=next;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*Element::Element ( const Element & unElement )
// Algorithme :
// Copie les pointeurs vers trajet et next de l'élément à copier.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Element>" << endl;
#endif
    trajet=unElement.trajet;
    next=unElement.next;
} //----- Fin de Element (constructeur de copie)
*/



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
