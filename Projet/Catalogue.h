/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

#include "LinkedList.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
// Cette classe répresent une liste sans ordre spécifique de Trajet possible.
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    void Insert(Trajet *trajet);
    // Mode d'emploi:
    // Ajoute un trajet en tête de liste

    void Afficher();
    // Mode d'emploi :
    // Affiche un par un chaque trajet de la liste




//-------------------------------------------- Constructeurs - destructeur


    Catalogue();
    // Mode d'emploi :
    // Instancie un nouveau catalogue avec une liste vide

    virtual ~Catalogue ();
    // Mode d'emploi :
    // Désalloue la liste

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privés

    LinkedList *list;                        

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

