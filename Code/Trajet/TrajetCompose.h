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
#include "../LinkedList.h"

//------------------------------------------------------------- Constantes

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
    
    void Afficher() const;

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose(const LinkedList *l, const char *vD = "", const char *vA = "");
    // Mode d'emploi :
    // Initialise la liste des trajets et si renseigné, les villes de départ
    // et d'arrivé. Sinon se contente de les instancier avec des chaines vides

    virtual ~TrajetCompose ();
    // Mode d'emploi :
    // Désalloue la liste des trajets

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées

    bool estOrdonne() const;

//----------------------------------------------------- Attributs privés

    LinkedList *listTrajets;

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

