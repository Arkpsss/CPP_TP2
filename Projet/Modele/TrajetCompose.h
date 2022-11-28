/*************************************************************************
                           Trajet  -  Classe implémentant un trajet composé
                             -------------------
    début                : 28/11/2022
    copyright            : (C) 2022 par Julien Bondyfalat et Gabriel Canaple
    e-mail               : gabriel.canaple@insa-lyon.fr, julien.bodyfalat@insa-lyon.fr
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

#define DESC 100    //taille du superflux de description

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

    TrajetCompose( Trajet **tab, int nb, const char *vD = NULL, const char *vA = NULL);
    // Mode d'emploi :
    // A partir d'un tableau de nb trajets, construit une LinkedList 
    // en se chargeant de les ajouter de manière ordonné (contraintes sur les villes
    // de départ et d'arrivé de chaque). 
    // En cas d'impossibilité de respecter cette contrainte, une MauvaiseComposition
    // exception est levée.
    // Si les paramètres vD et vA sont non renseignés, on les détermine après la construction de la liste
    // en prenant le premier et dernier element

    virtual ~TrajetCompose ();
    // Mode d'emploi :
    // Désalloue la liste des trajets

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées


    char* ToString() const;
    // Mode d'emploi :
    // Construit une chaine de caractère C décrivant le trajet
    // Contient la ville de départ et la ville d'arrivé et la description de 
    // chaque sous-trajet

    inline static char* realloc(char* text, int newSize) 
    // Mode d'emploi :
    // Recopie le text dans une nouvelle chaine de caractère plus grande (newSize)
    // delete le text
    {

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


//------------------------------------------------------------------------
// Rôle de la classe <MauvaiseCompositio>
//
// Cette classe hérite de la classe exception
// Cette exception est levée lorsque l'on ajoute un trajet au trajet composé
// qui ne permet pas de maintenir la cohérence entre ville de départ et ville
// d'arrivée
//
// En cas de levé d'exception le trajet composé en cours de construction est
// détruit et cette classe se charge de détruire la liste incomplète.
//------------------------------------------------------------------------


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

