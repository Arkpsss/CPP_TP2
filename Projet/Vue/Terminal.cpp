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

#define MAX 1000

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Terminal::Afficher() const {

    for (int i = 1; i <= catalogue->GetNbTrajet(); i++) {

        cout << "\t\t" << "Trajet n° " << i << "/ " << endl;

        cout << catalogue->GetDescriptionOf(i) << endl;

    }

}

Trajet* Terminal::SaisirNewTrajet() const {

    int nbSousTrajets = 0;
    cout << "Entrer le nombre de sous-trajets que contient votre trajet à saisir : ";
    cin >> nbSousTrajets;

    char vD[MAX];
    char vA[MAX];

    if (nbSousTrajets == 1) {
        cout << "   Ville de départ : ";
        fgets(vD, MAX, stdin);

        cout << "   Ville d'arrivee : ";
        fgets(vA, MAX, stdin);

        char mt[MAX];
        cout << "   Moyen de transport : ";
        fgets(mt, MAX, stdin);

        return new TrajetSimple(vD, vA, mt);

    }

    else {

        cout << "   Ville de départ : ";
        fgets(vD, MAX, stdin);

        cout << "   Ville d'arrivee : ";
        fgets(vA, MAX, stdin);

        Trajet* *tab = new Trajet*[nbSousTrajets];

        for (int i = 0; i < nbSousTrajets; i++) {

            cout << "\tSous-Trajet n° " << i+1 << endl;
            tab[i] = SaisirNewTrajet();

        }

        return new TrajetCompose(tab, nbSousTrajets, vD, vA);
    }

    

}

void Terminal::Start() {

    bool ok = true;

    cout << "Bienvenue dans le menu de gestion de catalogue de voyage" << endl;

    while (ok) {

        
        cout << "   1. Afficher le catalogue" << endl;
        cout << "   2. Inserer un trajet" << endl;
        cout << "   3. Rechercher un voyage" << endl;
        cout << "   4. Quitter" << endl;
        cout << "Saisir le numero qui vous interesse" << endl;

        int action;
        cin >> action;

        switch(action) {

        case 1:
            this->Afficher();
            break;

        case 2:
            catalogue->Insert(this->SaisirNewTrajet());
            break;

        case 3:
            break;

        case 4:
            ok = false;
            break;

        default:
            cout << "Erreur de numero !" << endl;

        }

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

