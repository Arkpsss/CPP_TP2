/*************************************************************************
           TrajetCompose  -  Classe implémentant un trajet composé
                             -------------------
    début                : 28/11/2022
    copyright            : (C) 2022 par Julien Bondyfalat et 
                                        Gabriel Canaple
    e-mail               : gabriel.canaple@insa-lyon.fr, 
                           julien.bondyfalat@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
#ifndef TRAJETCOMPOSE_H
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include "LinkedList.h"
#include "fonction_string.h"

using namespace std;


//------------------------------------------------------------------------
//
// Rôle de la classe <TrajetCompose>
// Cette classe représente un trajet composé de plusieurs trajets, qui
// peuvent etre simples ou composés.
// Il est ordonné de telle sorte que la ville d'arrivée corresponde à la 
// ville de départ du suivant.
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose( Trajet **tab, int nb, const char *vD = NULL, 
        const char *vA = NULL);
    // Mode d'emploi :
    // A partir d'un tableau de nb trajets, construit une LinkedList 
    // en se chargeant de les ajouter de manière ordonnée (contraintes 
    // sur les villes de départ et d'arrivée de chacune). 
    // En cas d'impossibilité de respecter cette contrainte, une 
    // exception MauvaiseComposition est levée.
    // Si les paramètres vD et vA ne sont pas renseignés, on les détermine 
    // après la construction de la liste en prenant le premier et le 
    // dernier element

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



//----------------------------------------------------- Attributs privés

    LinkedList *list;

};

//------------------------ Autres définitions dépendantes de <TrajetCompose>


//------------------------------------------------------------------------
// Rôle de la classe <MauvaiseComposition>
//
// Cette classe hérite de la classe exception
// Cette exception est levée lorsque l'on ajoute un trajet au trajet composé
// qui ne permet pas de maintenir la cohérence entre ville de départ et 
// ville d'arrivée.
// En cas de levée d'exception, le trajet composé en cours de construction est
// détruit et cette classe se charge de détruire le reste du tableau
//------------------------------------------------------------------------


class MauvaiseComposition : public exception {

public:

    MauvaiseComposition(Trajet **tab ,  int limit){

        this->tab = tab;
        this->limit = limit;
    }
    virtual ~MauvaiseComposition() {

        for (int i = 0; i <= limit; i++) {
            delete tab[i];
        }

        delete [] tab;

    }

    virtual const char* what() const throw() {      //redefinition de what() de la classe exception
        return "Erreur: Impossible d'ajouter ce trajet compose car la succession n'est pas ordonnée";
    }

private:
    Trajet **tab;
    int limit;

};

#endif // TRAJETCOMPOSE_H
