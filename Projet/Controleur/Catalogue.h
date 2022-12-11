/*************************************************************************
         Catalogue  -  Classe implémentant un catalogue de trajets
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et 
                                        Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et 
                           gabriel.canaple@insa-lyon.fr
*************************************************************************/

//------ Interface de la classe <Catalogue> (fichier Catalogue.h) --------
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
// Cette classe implémentente une liste chainée de trajets (de type 
// Trajet) triée par ordre alphabétique.
// Un catalogue peut fournir la description de chaque trajet qu'il 
// contient.
// On peut aussi insérer un trajet dans ce catalogue, et rechercher tous 
// les trajets allant d'un point A à un point B.
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    void Insert(Trajet *trajet);
    // Mode d'emploi:
    // Ajoute un trajet trié par ordre alphabetique par rapport à sa ville 
    // de départ puis par rapport à sa ville d'arrivée.


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

    Catalogue *RechercheSimple (const char *villeDepart, 
        const char *villeArrivee) const;
    // Mode d'emploi :
    // Recherche tous les trajets dont la ville de départ est villeDepart 
    // et dont la ville d'arrivée est villeArrivee.
    // Renvoie un pointeur vers un Catalogue contenant tous les trajets 
    // (simples ou composés) remplissant ces deux conditions
    // Les éléments de la liste chainée du catalogue généré pointent vers
    // des trajets déjà existant (ils ne sont pas réalloués), il ne faut
    // donc pas les delete individuellement!

    Catalogue *RechercheAvancee (const char *villeDepart, 
        const char *villeArrivee) const;
    // Mode d'emploi :
    // Recherche toutes les combinaisons de trajets dont la ville de départ 
    // est villeDepart et dont la ville d'arrivée est villeArrivee.
    // Renvoie un pointeur vers un Catalogue contenant toutes les 
    // combinaisons de trajets (simples ou composés) remplissant ces deux 
    // conditions
    // Les combinaisons de trajets seront représentées par des trajets 
    // composés.
    // Les éléments de la liste chainée du catalogue généré pointent vers
    // des trajets déjà existant (ils ne sont pas réalloués), il ne faut
    // donc pas les delete individuellement!

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

