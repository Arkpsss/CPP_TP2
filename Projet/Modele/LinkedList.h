/*************************************************************************
           LinkedList  -  Classe implémentant une liste chaînée simple
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr, 
                           julien.bondyfala@insa-lyon.fr
*************************************************************************/

//----- Interface de la classe <LinkedList> (fichier LinkedList.h) ------

#if ! defined ( LINKEDLIST_H )
#define LINKEDLIST_H

//--------------------------------------------------- Interfaces utilisées
#include "Element.h"

#include "fonction_string.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LinkedList>
// LinkedList implémente une liste chaînée simple avec pour chaînons des 
// Element, qui contiennent des trajets.
// Elle contient deux attributs :
// tete, de type Element*, qui est un pointeur vers le début de la liste
// taille, de type int, qui correspond à la taille de la liste.
// Elle propose différentes fonctions d'ajout décrites ci-dessous
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
    } //---- Fin de GetHead
    
    int GetTaille() const
    // Mode d'emploi :
    // Renvoie la taille de la liste
    {
        return this->taille;
    } //----Fin de GetTaille

    bool AddCoherent(Trajet *trajet, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Ajoute un trajet à la liste de telle sorte que la ville d'arrivée
    // de celui-ci corresponde à la ville de départ du trajet contenu 
    // dans l'élément suivant.

    void AddOrdreAlphabetique(Trajet *trajet, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Si la liste est vide, ajoute en tête le trajet. Sinon, fait appel 
    // à la méthode RecAddAlpha pour ajouter le trajet par ordre 
    // alphabétique de la ville de depart
    // En cas d'égalité, se fait par rapport à la ville d'arrivée.

//-------------------------------------------- Constructeurs - destructeur

    LinkedList(Element *tete = NULL, int taille = 0);
    // Mode d'emploi :
    // Crée une liste vide
    // La taille doit correspondre à la taille de la liste pointée par tete

    ~LinkedList ( );
    // Mode d'emploi :
    // Détruit la LinkedList, c’est-à-dire désalloue tous ses éléments

//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Méthodes privé

    static bool compare(Trajet *a, Trajet *b) 
    // Mode d'emploi:
    // Compare la ville de depart du premier trajet avec la ville 
    // d'arrivée du second. 
    // Renvoie true si ce sont les memes, false sinon.
    {
        if (strcmp(a->GetVilleDepart(), b->GetVilleArrivee()) == 0) {
            return true;
        }
        else {
            return false;
        }
    } //---- Fin de compare

    void RecAddAlpha(Trajet *trajet, Element *current, Element *prec, 
        bool depart, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Ajoute un trajet de telle sorte que l'orde alphabétique soit 
    // respecté.
    // Détermine si l'élément courant et l'élément précédent forment le 
    // bon encadrement pour ajouter ce trajet.
    // Sinon, rappelle cette methode en progressant dans la liste 
    // Le booléen depart permet de savoir si la comparaison doit 
    // s'effectuer sur la ville de départ ou sur celle d'arrivée.

    void AddFirst(Trajet *trajet, bool _deleteTrajet = true);
    // Mode d'emploi :
    // Ajoute un trajet en tête de liste.
    // _deleteTrajet permet de spécifier le comportement lors du delete 

//----------------------------------------------------- Attributs privé
    Element *tete; //Pointeur vers le premier élément de la liste
    int taille;

};

//-------------------------------- Autres définitions dépendantes de <LinkedList>

#endif // LINKEDLIST_H
