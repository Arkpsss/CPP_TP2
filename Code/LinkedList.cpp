/*************************************************************************
                           LinkedList  -  Classe implémentant une liste chaînée
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr, julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LinkedList> (fichier LinkedList.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LinkedList.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LinkedList::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
LinkedList & LinkedList::operator = ( const LinkedList & unLinkedList )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LinkedList::LinkedList ( const LinkedList & unLinkedList )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LinkedList>" << endl;
#endif
} //----- Fin de LinkedList (constructeur de copie)


LinkedList::LinkedList ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LinkedList>" << endl;
#endif
} //----- Fin de LinkedList


LinkedList::~LinkedList ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LinkedList>" << endl;
#endif
} //----- Fin de ~LinkedList


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
