/*************************************************************************
                           Trajet  -  Classe représentant un trajet générale
                             -------------------
    début                : 28/11/2022
    copyright            : (C) 2022 par Julien Bondyfalat et Gabriel Canaple
    e-mail               : gabriel.canaple@insa-lyon.fr, julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#ifndef TRAJET_H
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

#include "fonction_string.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// 
// La classe Trajet est une classe générique pour représenter soit un trajet
// simple soit un trajet composé.
// Un trajet est caractérisé par une ville de départ et une ville d'arrivée.
// Ainsi qu'un string C de description
//
// Cette classe est abstraite car un trajet sans moyen de transport n'est pas
// possible.
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    const char* GetVilleDepart() const
    // Mode d'emploi :
    // Retourne la ville de départ
    {
        return villeDepart;
    }

    const char* GetVilleArrivee() const
    // Mode d'emploi :
    // Retourne la ville d'arrivé
    {
        return villeArrivee;
    }

    const char* GetDescription() const
    // Mode d'emploi:
    // Retourn la description du trajet
    {
        return description;
    }
    


//-------------------------------------------- Constructeurs - destructeur
    Trajet(const char *vD = NULL, const char *vA = NULL);
    // Mode d'emploi :
    // Initialise les attributs de la classe (2 tableaux dynamiques de char).

    virtual ~Trajet ();
    // Mode d'emploi :
    // Détruit les attributs (2 tableaux dynamiques de char).

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    virtual char* ToString() const = 0;
    // Mode d'emploi :
    // Construit une chaine de caractère C décrivant le trajet
    // Contient la ville de départ et la ville d'arrivé

    void SetVilleDepart(const char* vD);
    // Mode d'emploi :
    // Redéfinit la ville de départ en supprimant l'ancienne si nécessaire

    void SetVilleArrivee(const char* vA);
    // Mode d'emploi : 
    // Redéfinit la ville d'arrivé en supprimant l'ancienne si nécessaire



    static void deleteDescription(Trajet *t) {

        if (t->description != NULL) {
            delete [] t->description;
            t->description = NULL;
        }

    }

//----------------------------------------------------- Attributs protégés

    char *villeDepart;
    char *villeArrivee;

    char *description;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H

