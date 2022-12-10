/*************************************************************************
                           Element  -  Maillon du liste chainée simple
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr, julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Element> (fichier Element.h) ----------------
#if ! defined ( ELEMENT_H )
#define ELEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Element>
// Un Element est un chaînon de la LinkedList implémentée dans notre projet.
// Il contient un pointeur sur un trajet, qui peut être simple ou composé, et contient éga
// -lement un pointeur vers le chaînon suivant.
//------------------------------------------------------------------------

class Element
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Trajet *GetTrajet () const
    // Mode d'emploi :
    // Retourne le pointeur sur le trajet
    {
        return trajet;
    }

    Element *GetNext () const
    // Mode d'emploi :
    // Retourne un pointeur vers le prochain chaînon
    {
        return next;
    }


    void SetNext(Element *e)
    // Mode d'emploi :
    // Redéfinit l'élement suivant celui-ci
    {
        this->next = e;
    }


//-------------------------------------------- Constructeurs - destructeur


    Element (Trajet *trajet = NULL, Element *next = NULL, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Crée un Element avec :
    // this->trajet = trajet (paramètre formel)
    // this->next = next
    // deleteTrajet à _deleteTrajet
    // next doit être valide (pointe vers un Element existant ou vers NULL)

    ~Element ();
    // Mode d'emploi :
    // Détruit l'Element, c'est à dire désalloue la zone mémoire pointée
    // par trajet.

//------------------------------------------------------------------ PRIVE

private:

//----------------------------------------------------- Attributs privés
    Trajet *trajet;
    Element *next;
    bool deleteTrajet; //Indique si, au moment, du delete, on delete le trajet.
                       //Utile notamment dans les méthodes RechercheSimple et RechercheAvancee de Catalogue
};

//-------------------------------- Autres définitions dépendantes de <Element>

#endif // ELEMENT_H
