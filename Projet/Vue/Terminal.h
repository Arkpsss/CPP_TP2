 /*************************************************************************
                           Terminal  -  Système d'IHM du projet
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et gabriel.canaple@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Terminal> (fichier Terminal.h) ----------------
#if ! defined ( TERMINAL_H )
#define TERMINAL_H

//--------------------------------------------------- Interfaces utilisées

#include "../Controleur/Catalogue.h"

#include "../Modele/Trajet.h"
#include "../Modele/TrajetSimple.h"
#include "../Modele/TrajetCompose.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Terminal>
//
// La classe Terminal représente une vue console du projet.
// Elle permet de communiquer avec l'utilisateur en utilisant les entrées 
// et sortie standard sur un terminal.  
//
// c'est dans cette classe que sont implémentés les appels des fonctionnalités
// du catalogue : demander l'affichage, ajouter un trajet en le saisissant, 
// avoir le résultat d'une recherche de parcours.
//
//------------------------------------------------------------------------

class Terminal
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher() const;
    // Mode d'emploi :
    // Recupère les descriptions de chaque trajet du catalogue et les affiche
    // au fur et à mesure.

    void Start();
    // Mode d'emploi : 
    // Débute l'affichage sur console en bouclant jusqu'à arret de l'utilisateur
    // sur un menu permettant de choisir les actions que l'on souhaite utiliser du
    // catalogue

    Trajet* SaisirNewTrajet() const;

    void RechercheTrajet () const;
    // Mode d'emploi :
    // Demande à l'utilisateur d'entrer une ville de départ et une ville
    // d'arrivée, et recherche à travers le catalogue courant tous les
    // trajets correspondant. Affiche ensuite le contenu du catalogue
    // contenant le résultat


//-------------------------------------------- Constructeurs - destructeur

    Terminal ( );
    // Mode d'emploi :
    // Créer un nouveau Catalogue

    virtual ~Terminal ( );
    // Mode d'emploi :
    // Detruit le catalogue

//------------------------------------------------------------------ PRIVE

private:

//----------------------------------------------------- Attributs privés
    Catalogue *catalogue;

};

//-------------------------------- Autres définitions dépendantes de <Terminal>

#endif // TERMINAL_H

