/*************************************************************************
                           Terminal  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Terminal> (fichier Terminal.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Terminal.h"
#include "../Modele/Trajet.h"
#include "../Modele/TrajetSimple.h"
#include "../Modele/TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Terminal::Afficher() const {

    for (int i = 1; i <= catalogue->GetNbTrajet(); i++) {

        cout << "\t\t" << "Trajet n° " << i << "/ " << endl;

        cout << catalogue->GetDescriptionOf(i) << endl;

    }

}


//-------------------------------------------- Constructeurs - destructeur



Terminal::Terminal ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Terminal>" << endl;
#endif

    catalogue = new Catalogue();

    //Pour le test
    Trajet *t1 = new TrajetSimple("Paris", "Londres", "bateau");
    Trajet *t2 = new TrajetSimple("Londres", "Los Angeles", "avion");

    Trajet* tab[2] = {t1,t2};

    Trajet *t = new TrajetCompose(tab, 2, "Paris", "Los Angeles");

    catalogue->Insert(t);

    Trajet *tbis = new TrajetSimple("Paris", "Londres", "Bateau");
    catalogue->Insert(tbis);



} //----- Fin de Terminal


Terminal::~Terminal ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Terminal>" << endl;
#endif

    delete catalogue;

} //----- Fin de ~Terminal


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

