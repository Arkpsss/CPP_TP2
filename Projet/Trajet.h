/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#ifndef TRAJET_H
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// 
// La classe Trajet est une classe générique pour représenter soit un trajet
// simple soit un trajet composé.
// Un trajet est caractérisé par une ville de départ et une ville d'arrivée.
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
    
    virtual void Afficher() const = 0;
    // Mode d'emploi:
    // Affiche les caractéristiques du trajet sur la sortie standard cout

    char* GetVilleDepart() {
        return villeDepart;
    }

    char* GetVilleArrivee() {
        return villeArrivee;
    }
    


//-------------------------------------------- Constructeurs - destructeur
    Trajet(const char *vD, const char *vA);
    // Mode d'emploi :
    // Initialise les attributs de la classe (2 tableaux dynamiques de char).

    virtual ~Trajet ();
    // Mode d'emploi :
    // Détruit les attributs (2 tableaux dynamiques de char).

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    char *villeDepart;
    char *villeArrivee;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // XXX_H

