/*************************************************************************
                      TrajetCompose  -  Classe implémentant les trajets
                                        composés du TP2
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr,
                           julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#ifndef TRAJETCOMPOSE_H
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include "LinkedList.h"

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

    TrajetCompose( Trajet **tab, int nb, const char *vD, const char *vA );

    virtual ~TrajetCompose ();
    // Mode d'emploi :
    // Désalloue la liste des trajets

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

#endif // TRAJETCOMPOSE_H

