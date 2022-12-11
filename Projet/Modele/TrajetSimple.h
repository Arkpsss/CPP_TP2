/*************************************************************************
              TrajetSimple  -  Classe implémentant un trajet simple
                             -------------------
    début                : 28/11/2022
    copyright            : (C) 2022 par Julien Bondyfalat et 
                                        Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et 
                           gabriel.canaple@insa-lyon.f
*************************************************************************/

//--- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#ifndef TRAJETSIMPLE_H
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

#include "fonction_string.h"

//------------------------------------------------------------- Constantes

#define DESC 100    //taille du superflux de description

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Cette classe représente un trajet simple d'une ville à une autre avec un
// moyen de transport.
// Un trajet simple est une sorte de Trajet
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    

//-------------------------------------------- Constructeurs - destructeur


    TrajetSimple(const char *vD, const char *vA, const char *mt);
    // Mode d'emploi :
    // Fait appel au constructeur de Trajet pour initialiser les
    // villes de départ et d'arrivée
    // Initialise le moyen de transport

    virtual ~TrajetSimple();
    // Mode d'emploi :
    // Détruit les 3 tableaux dynamique (2 de Trajet et un de TrajetSimple)

//------------------------------------------------------------------ PRIVE

private:

    char* ToString() const;
    // Mode d'emploi :
    // Construit une chaine de caractère C décrivant le trajet
    // Contient la ville de départ et la ville d'arrivé et 
    // le moyen de transport.

//----------------------------------------------------- Attributs privés
    char *moyenTransport;
};

//----------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
