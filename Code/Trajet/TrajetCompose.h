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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose(const char *vD, const char *vA, const list<Trajet> *l);
    // Mode d'emploi :
    // Initialise la liste des trajets et la ville de départ et d'arrive 
    // du trajet en totalité

    virtual ~TrajetCompose ();
    // Mode d'emploi :
    // Désalloue la liste des trajets

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées

    bool estOrdonne() const;

//----------------------------------------------------- Attributs privés

    list<Trajet> *listTrajets;

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H

