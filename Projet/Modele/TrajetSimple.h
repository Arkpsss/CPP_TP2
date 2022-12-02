/*************************************************************************
                      TrajetCompose  -  Classe implémentant les trajets
                                        composés du TP2
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr,
                           julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#ifndef TRAJETSIMPLE_H
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

#define DESC 100

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
// Cette classe représente un trajet simple d'une ville à une autre avec un
// moyen de transport.
//
// Un trajet simple est une sorte de Trajet
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    //void Afficher() const;

    


//-------------------------------------------- Constructeurs - destructeur


    TrajetSimple(const char *vD, const char *vA, const char *mt);
    // Mode d'emploi :
    // Fait appel au constructeur de Trajet pour initialiser les
    // villes de départ et d'arrivé
    // Initialise le moyen de transport

    virtual ~TrajetSimple();
    // Mode d'emploi :
    // Détruit les 3 tableaux dynamique (2 de Trajet et un de TrajetSimple)

//------------------------------------------------------------------ PRIVE

private:

    char* ToString() const;

//----------------------------------------------------- Attributs privés
    char *moyenTransport;

    //char *description;


};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

