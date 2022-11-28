/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#ifndef TRAJETCOMPOSE_H
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include "LinkedList.h"

#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

#define DESC 100

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
// Cette classe représente un trajet composé de plusieurs trajets simples
// ou composé
// ordonné de tel sorte que la ville d'arrivé correspondent à la ville de 
// départ du suivant.
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
    /*TrajetCompose(LinkedList *l, const char *vD = "", const char *vA = "");
    // Mode d'emploi :
    // Initialise la liste des trajets et si renseigné, les villes de départ
    // et d'arrivé. Sinon se contente de les instancier avec des chaines vides
    */

    TrajetCompose( Trajet **tab, int nb, const char *vD = NULL, const char *vA = NULL);

    virtual ~TrajetCompose ();
    // Mode d'emploi :
    // Désalloue la liste des trajets

    //friend class MauvaiseComposition;

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées


    char* ToString() const;

    inline static char* realloc(char* text, int newSize) {

        char* res = new char[newSize];

        if (text != NULL) {
            strcpy(res, text);
            delete [] text;
        }

        return res;

    }



//----------------------------------------------------- Attributs privés

    LinkedList *list;

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

class MauvaiseComposition : public exception {

public:

    MauvaiseComposition(LinkedList *l){

        this->list  = l;

    }
    virtual ~MauvaiseComposition() {

        delete list;

    }

    virtual const char* what() const throw() {      //redefinition de what() de la classe exception
        return "Erreur: Impossible d'ajouter ce trajet compose car la succession n'est pas ordonnée";
    }

private:
    LinkedList *list;

};

#endif // TRAJETCOMPOSE_H

