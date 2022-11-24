/*************************************************************************
                           Element  -  Classe implémentant une liste chaînée
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr, julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Element> (fichier Element.h) ----------------
#if ! defined ( Element_H )
#define Element_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Element>
// Un Element est un chaînon de la LinkedList implémentée dans notre projet.
// Il contient un trajet, qui peut être simple ou composé, et contient éga
// -lement un pointeur vers le chaînon suivant.
// La classe contient donc deux attributs :
// - trajet, de type Trajet*, est un pointeur vers le trajet contenu dans
//   le chaînon.
// - next, de type Element*, est un pointeur vers le prochain Element de la
//   liste.
//------------------------------------------------------------------------

class Element
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Trajet *GetTrajet () const;
    // Mode d'emploi :
    // Retourne un pointeur vers le trajet contenu dans le chaînon
    // Contrat :
    //

    void SetTrajet (Trajet *trajet);
    // Mode d'emploi :
    // Permet de modifier le trajet contenu dans le chaînon à partir d'un
    // trajet alloué dynamiquement (avec new).
    // Contrat :
    //

    Element *GetNext () const;
    // Mode d'emploi :
    // Retourne un pointeur vers le prochain chaînon
    // Contrat :
    //

    void SetNext (Element *next);
    // Mode d'emploi :
    // Permet de modifier le prochain chaînon pointé par next avec une
    // valeur valide (NULL ou Element alloué dynamiquement)
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    /*Element ( const Element &unElement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    */

    Element (Trajet *trajet = NULL, Element *next = NULL);
    // Mode d'emploi :
    // Crée un Element avec :
    // this->trajet = trajet (paramètre formel)
    // this->next = next
    // next doit être valide (pointe vers un Element existant ou vers NULL)

    ~Element ( );
    // Mode d'emploi :
    // Détruit l'Element, c'est à dire désalloue la zone mémoire pointée
    // par trajet.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Trajet *trajet;
    Element *next;
};

//-------------------------------- Autres définitions dépendantes de <Element>

#endif // Element_H