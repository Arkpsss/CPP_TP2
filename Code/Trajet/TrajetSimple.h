/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#ifndef TRAJETSIMPLE_H
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

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
    
    void Afficher() const;
    // Mode d'emploi:
    // Affiche la ville de départ, d'arrivé, et le moyen de transport
    // du trajet simple.



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

//----------------------------------------------------- Attributs privés
    char *moyenTransport;


};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

