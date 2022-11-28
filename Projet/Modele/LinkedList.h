/*************************************************************************
                           LinkedList  -  Classe implémentant une liste chaînée simple
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr, julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LinkedList> (fichier LinkedList.h) ----------------

#if ! defined ( LINKEDLIST_H )
#define LINKEDLIST_H

//--------------------------------------------------- Interfaces utilisées
#include "Element.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LinkedList>
// LinkedList implémente une liste chaînée simple avec pour chaînons des Element
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
    Element* GetHead () const {
        return this->tete;
    }
    // Mode d'emploi :
    // Renvoie le premier maillon de la liste


    void AddFirst(Trajet *trajet);
    // Mode d'emploi :
    // Ajoute un trajet en tête de liste

    bool AddTrie(Trajet *trajet);
    // Mode d'emploi :
    // Ajoute un trajet à la liste de telle sorte que la ville d'arrivé de celui-ci
    // correspondent à la ville de départ du trajet contenu dans l'élement suivant.

    int GetTaille() const {
        return this->taille;
    }
    // Mode d'emploi :
    // Renvoie la taille de la liste



//-------------------------------------------- Constructeurs - destructeur


    LinkedList(Element *tete = NULL, int taille = 0);
    // Mode d'emploi :
    // Crée une liste vide avec tete=tete et taille=taille
    // La taille doit correspondre à la taille de la liste pointée par tete

    ~LinkedList ( );
    // Mode d'emploi :
    // Détruit la LinkedList, c’est-à-dire désalloue tous ses éléments

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privé

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

//----------------------------------------------------- Attributs privé
    Element *tete;
    int taille;
};

//-------------------------------- Autres définitions dépendantes de <LinkedList>

#endif // LINKEDLIST_H