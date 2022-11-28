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

#include "../Modele/LinkedList.h"
#include "../Modele/Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
// Cette classe répresente une liste sans ordre spécifique de Trajet possible.
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

    void Afficher() const;
    // Mode d'emploi :
    // Affiche un par un chaque trajet de la liste

    int GetNbTrajet() const {
        return list->GetTaille();
    }


    char* GetDescriptionOf(int numeroTrajet) const;

    Catalogue *RechercheSimple (char *villeDepart, char *villeArrivee) const;
    // Mode d'emploi :
    // Recherche tous les trajets dont la ville de départ est villeDepart et dont la ville d'arrivée est
    // villeArrivee.
    // Renvoie un pointeur vers un Catalogue contenant tous les trajets (simples ou composés)
    // remplissant ces deux conditions
    // Ces trajets seront réalloués dynamiquement dans le tas

    Catalogue *RechercheAvancee (char *villeDepart, char *villeArrivee) const;
    // Mode d'emploi :
    // Recherche toutes les combinaisons de trajets dont la ville de départ est villeDepart et dont la
    // ville d'arrivée est villeArrivee.
    // Renvoie un pointeur vers un Catalogue contenant toutes les combinaisons de trajets (simples ou composés)
    // remplissant ces deux conditions
    // Les combinaisons de trajets seront représentées par des trajets composés
    // Ces trajets seront réalloués dynamiquement dans le tas

//-------------------------------------------- Constructeurs - destructeur


    Catalogue(LinkedList *_list = new LinkedList());
    // Mode d'emploi :
    // Instancie un nouveau catalogue avec une liste donnée en paramètre (vide par défaut)

    virtual ~Catalogue ();
    // Mode d'emploi :
    // Désalloue la liste

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privées

bool rechercheRecursive (char *villeDepart, char *villeArrivee) const;

//----------------------------------------------------- Attributs privés

    LinkedList *list;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

