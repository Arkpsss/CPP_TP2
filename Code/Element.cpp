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
// type Element::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Element::Element ( const Element & unElement )
// Algorithme :
// Copie les pointeurs vers trajet et next de l'élément à copier.
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Element>" << endl;
#endif
    trajet=unElement.trajet;
    next=unElement.next;
} //----- Fin de Element (constructeur de copie)


Element::Element ( ) : trajet(NULL), next(NULL)
// Algorithme :
// Met à NULL trajet et next.
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Element>" << endl;
#endif
} //----- Fin de Element

Element::Element (Trajet *trajet) : trajet(trajet), next(NULL)
// Algorithme :
// Met à next à NULL et this->trajet à trajet.
{
#ifdef MAP
    cout << "Appel au premier constructeur de <Element>" << endl;
#endif
}

Element::Element (Trajet *trajet, Element *next) : trajet(trajet), next(next)
// Algorithme :
// Met à this->next à next et this->trajet à trajet.
{
#ifdef MAP
    cout << "Appel au deuxième constructeur de <Element>" << endl;
#endif
}

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
