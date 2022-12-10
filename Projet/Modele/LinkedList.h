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

#include "fonction_string.h"

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
    Element* GetHead () const 
    // Mode d'emploi :
    // Renvoie le premier maillon de la liste
    {
        return this->tete;
    }
    

    bool AddCoherent(Trajet *trajet, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Ajoute un trajet à la liste de telle sorte que la ville d'arrivé de celui-ci
    // correspondent à la ville de départ du trajet contenu dans l'élement suivant.

    void AddOrdreAlphabetique(Trajet *trajet, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Si la liste est vide ajoute en tête le trajet sinon fait appel à la méthode
    // RecAddAlpha pour ajouter le trajet par ordre alphabetique de la ville de depart
    // et en cas d'égalité par rapport à la ville d'arrivée.

    int GetTaille() const
    // Mode d'emploi :
    // Renvoie la taille de la liste
    {
        return this->taille;
    }
    



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

    static bool compare(Trajet *a, Trajet *b) 
    // Mode d'emploi:
    // Compare la ville de depart du premier trajet avec la ville d'arrivé du second
    {
        if (strcmp(a->GetVilleDepart(), b->GetVilleArrivee()) == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void RecAddAlpha(Trajet *trajet, Element *current, Element *prec, bool depart, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Ajoute un trajet de telle sorte que l'orde alphabétique soit respecté
    // Determine si l'element courant et l'element prec est bien le bon encadrement pour 
    // ajouter ce trajet
    // Sinon rappelle cette methode en progressant dans la liste 
    // Le boolean depart permet de savoir si la comparaison doit s'effectuer sur la ville de 
    // départ ou celle d'arrivée.

    void AddFirst(Trajet *trajet, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Ajoute un trajet en tête de liste
    // __deleteTrajet permet de spécifier le comportement lors du delete 

//----------------------------------------------------- Attributs privé
    Element *tete;
    int taille;

};

//-------------------------------- Autres définitions dépendantes de <LinkedList>

#endif // LINKEDLIST_H
