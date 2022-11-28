/*************************************************************************
                           Terminal  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Terminal> (fichier Terminal.h) ----------------
#if ! defined ( TERMINAL_H )
#define TERMINAL_H

//--------------------------------------------------- Interfaces utilisées

#include "../Controleur/Catalogue.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Terminal>
//
//
//------------------------------------------------------------------------

class Terminal
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher() const;

    void Start();
    Trajet* SaisirNewTrajet() const;

    void ViderBuffer() const;
    int RecupSaisiString(char *chaine, int longueur) const;
    


//-------------------------------------------- Constructeurs - destructeur

    Terminal ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Terminal ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Catalogue *catalogue;

};

//-------------------------------- Autres définitions dépendantes de <Terminal>

#endif // TERMINAL_H

