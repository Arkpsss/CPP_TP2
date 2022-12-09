/*************************************************************************
                           LinkedList  -  Classe implémentant une liste
                                          chaînée
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr,
                           julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LinkedList> (fichier LinkedList.h) ----------------

#if ! defined ( LinkedList_H )
#define LinkedList_H

//--------------------------------------------------- Interfaces utilisées
#include "Element.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LinkedList>
// LinkedList implémente une liste chaînée avec pour chaînons des Element
// Son utilisation est indépendante du type contenu dans Element, mais ici
// elle sera utilisée avec des Element contenant des Trajet.
// Elle contient deux attributs :
// tete, de type Element*, qui est un pointeur vers le début de la liste
// taille, de type int, qui correspond à la taille de la liste.
//------------------------------------------------------------------------

class LinkedList
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Element * GetHead () const ;    // Mode d'emploi :
    // Renvoie le premier maillon de la liste
    // Contrat :
    //

    void Afficher () const;
    // Mode d'emploi :
    // Affiche le contenu de la liste
    // Contrat :
    //

    void SetHead () ;
    // Mode d'emploi :
    // Redéfinit le début de la liste
    // Contrat :
    //

    void Add (Trajet *trajet, int position) ;
    // Mode d'emploi :
    // Crée un Element donc le trajet est trajet à la position position.
    // Trajet doit être alloué dynamiquement (avec new)
    // position doit être valide (0<=position<=taille);
    // Contrat :
    //

    /*
    void AddOrdreAlphab (Trajet *trajet, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Ajoute un trajet à la liste en le classant d'abord par ordre alphabétique de la ville de départ,
    // puis par ordre alphabétique de la ville d'arrivée.
*/
    void AddFirst(Trajet *trajet, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Ajoute un trajet en tête de liste
    // _deleteTrajet permet de spécifier le comportement lors du delete

    bool AddTrie(Trajet *trajet);
    // Mode d'emploi :
    // Ajoute un trajet à la liste de telle sorte que la ville d'arrivée de celui-ci
    // corresponde à la ville de départ du trajet contenu dans l'élement suivant.

    int GetTaille() const {
        return this->taille;
    }
    // Mode d'emploi :
    // Renvoie la taille de la liste

    

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    /*LinkedList ( const LinkedList & unLinkedList );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    */


    LinkedList(Element *tete = NULL, int taille = 0);
    // Mode d'emploi :
    // Crée une liste avec tete=tete et taille=taille
    // La taille doit correspondre à la taille de la liste pointée par tete

    ~LinkedList ( );
    // Mode d'emploi :
    // Détruit la LinkedList, c’est-à-dire désalloue tous ses éléments

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées

    inline static bool compare(Trajet *a, Trajet *b) {
        if (strcmp(a->GetVilleDepart(), b->GetVilleArrivee()) == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    // Mode d'emploi:
    // Compare la ville de depart du premier trajet avec la ville d'arrivé du second

//----------------------------------------------------- Attributs privés
    Element *tete;
    int taille;
};

//-------------------------------- Autres définitions dépendantes de <LinkedList>

#endif // LinkedList_H