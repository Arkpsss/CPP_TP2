/*************************************************************************
                           LinkedList  -  Classe implémentant une liste chaînée
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr, julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LinkedList> (fichier LinkedList.h) ----------------

#if ! defined ( LinkedList_H )
#define LinkedList_H

//--------------------------------------------------- Interfaces utilisées
#include "Element.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LinkedList>
//
//
//------------------------------------------------------------------------

class LinkedList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    LinkedList ( const LinkedList & unLinkedList );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LinkedList ( );
    // Mode d'emploi :
    // Crée une liste vide avec tete=NULL et taille=0
    // Contrat :
    //

    LinkedList(Element *tete, int taille);
    // Mode d'emploi :
    // Crée une liste vide avec tete=tete et taille=taille
    // La taille doit correspondre à la taille de la liste pointée par tete
    // Contrat :
    //

    ~LinkedList ( );
    // Mode d'emploi :
    // Détruit la LinkedList, c'est à dire désalloue tous ses éléments
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Element *tete;
    int taille;
};

//-------------------------------- Autres définitions dépendantes de <LinkedList>

#endif // LinkedList_H