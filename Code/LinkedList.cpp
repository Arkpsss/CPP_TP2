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


LinkedList::LinkedList ( ) : tete(NULL), taille(0)
// Algorithme :
// Met tete à NULL et taille à 0
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <LinkedList>" << endl;
#endif
} //----- Fin de LinkedList

LinkedList::LinkedList(Element *tete, int taille) : tete(tete), taille(taille)
// Algorithme :
// Met tete à l'attribut tete et taille à l'attribut taille
    {
#ifdef MAP
    cout << "Appel au premier constructeur de <LinkedList>" << endl;
#endif
    }

LinkedList::~LinkedList ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LinkedList>" << endl;
#endif
    Element *current = tete;
    for (int i=0; i<taille; i++)
    {
        Element *temp = current->GetNext();
        delete(current);
        current=temp;
    }
} //----- Fin de ~LinkedList


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
