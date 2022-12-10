/*************************************************************************
                           Catalogue  -  Classe imlémentant un catalogue de Trajet
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et gabriel.canaple@insa-lyon.fr
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
// Cette classe répresente une liste trié par ordre alphabetique de Trajet possible.
// Un catalogue peut fournir la description de chaque trajet qu'il contient.
// On peut aussi insérer un trajet dans ce catalogue.
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    void Insert(Trajet *trajet);
    // Mode d'emploi:
    // Ajoute un trajet trié par ordre alphabetique par rapport à sa ville de
    // départ puis par rapport à sa ville d'arrivée.


    int GetNbTrajet() const 
    // Mode d'emploi:
    // Retourne le nombre de trajet contenu dans le catalogue
    {
        return list->GetTaille();
    }

    const char* GetDescriptionOf(int numeroTrajet) const;
    // Mode d'emploi:
    // Renvoie la description du trajet dont le numéro est passé en
    // paramètre.

    Catalogue *RechercheSimple (const char *villeDepart, const char *villeArrivee) const;
    // Mode d'emploi :
    // Recherche tous les trajets dont la ville de départ est villeDepart et dont la ville d'arrivée est
    // villeArrivee.
    // Renvoie un pointeur vers un Catalogue contenant tous les trajets (simples ou composés)
    // remplissant ces deux conditions
    // Ces trajets seront réalloués dynamiquement dans le tas, tout comme le catalogue renvoyé (penser à le delete)

    Catalogue *RechercheAvancee (const char *villeDepart, const char *villeArrivee) const;
    // Mode d'emploi :
    // Recherche toutes les combinaisons de trajets dont la ville de départ est villeDepart et dont la
    // ville d'arrivée est villeArrivee.
    // Renvoie un pointeur vers un Catalogue contenant toutes les combinaisons de trajets (simples ou composés)
    // remplissant ces deux conditions
    // Les combinaisons de trajets seront représentées par des trajets composés
    // Ces trajets seront réalloués dynamiquement dans le tas

//-------------------------------------------- Constructeurs - destructeur


    Catalogue(LinkedList *_list = new LinkedList ());
    // Mode d'emploi :
    // Instancie un nouveau catalogue avec une liste vide

    virtual ~Catalogue ();
    // Mode d'emploi :
    // Désalloue la liste

//------------------------------------------------------------------ PRIVE

private:

//----------------------------------------------------- Attributs privés

    LinkedList *list;                        

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

