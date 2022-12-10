 /*************************************************************************
                           Terminal  -  Système d'IHM du projet
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et gabriel.canaple@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Terminal> (fichier Terminal.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Terminal.h"

#include "../Modele/fonction_string.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Terminal::Afficher() const {

    if (catalogue->GetNbTrajet() == 0) {
        cout << "Le catalogue est vide." << endl;
    }

    for (int i = 1; i <= catalogue->GetNbTrajet(); i++) {

        cout << "\t\t" << "Trajet n° " << i << "/ " << endl;

        cout << catalogue->GetDescriptionOf(i) << endl;

    }

} //---- Fin de Afficher



Trajet* Terminal::SaisirNewTrajet() const {

    int nbSousTrajets = 0;
    bool ok = true;
    
    while (ok) {
        cout << "Entrer le nombre d'escales que contient votre trajet à saisir : ";

        //Pour gerer les exceptions de mauvaise saisi
        cin.exceptions(ios_base::failbit);

        try {

            cin >> nbSousTrajets;
            cin.ignore();

            ok = false;

        } catch (exception &e) {
            cout << "Il faut saisir un nombre !" << endl;

                cin.clear();
                cin.ignore(300, '\n');
        }
    }


    char vD[TAILLE_MAX];
    char vA[TAILLE_MAX];

    if (nbSousTrajets == 1) {
        cout << "   Ville de départ : ";
        recup_saisi_string(vD, TAILLE_MAX);

        cout << "   Ville d'arrivée : ";
        recup_saisi_string(vA, TAILLE_MAX);


        char mt[TAILLE_MAX];
        cout << "   Moyen de transport : ";
        recup_saisi_string(mt, TAILLE_MAX);


        cout << "\n";

        return new TrajetSimple(vD, vA, mt);

    }

    else {

        Trajet* *tab = new Trajet*[nbSousTrajets];

        for (int i = 0; i < nbSousTrajets; i++) {

            cout << "\tSous-Trajet n° " << i+1 << endl;
            tab[i] = SaisirNewTrajet();

        }

        try {
            Trajet* t = new TrajetCompose(tab, nbSousTrajets);
            delete [] tab;

            return t;
        }
        catch (exception &e) {
            cout << e.what() << endl;
        }
        
        return NULL;
        
    }

    

} //---- Fin de SaisirNewTrajet



Catalogue* Terminal::RechercheTrajet() const {
    char vD[TAILLE_MAX];
    char vA[TAILLE_MAX];

    cin.ignore();

    cout << "   Ville de départ : ";
    recup_saisi_string(vD, TAILLE_MAX);

    cout << "   Ville d'arrivée : ";
    recup_saisi_string(vA, TAILLE_MAX);

    Catalogue *resultat = catalogue->RechercheSimple(vD, vA);

    return resultat;
    
} //---- Fin de RechercheTrajet




void Terminal::Start() {

    bool ok = true;

    cout << "Bienvenue dans le menu de gestion de catalogue de voyage" << endl;

    
    

    while (ok) {

        cout << endl;
        cout << "   1. Afficher le catalogue" << endl;
        cout << "   2. Inserer un trajet" << endl;
        cout << "   3. Rechercher un voyage" << endl;
        cout << "   4. Quitter" << endl;
        cout << "Saisir le numero qui vous interesse : ";

        int action;

        //Pour gerer les exceptions de mauvaise saisi
        cin.exceptions(ios_base::failbit);

        try {
            cin >> action;

            switch(action) {

            case 1:
                this->Afficher();
                break;

            case 2:
                {
                    Trajet *t = this->SaisirNewTrajet();
                    if (t != NULL) {
                        catalogue->Insert(t);
                    }
                }
                break;

            case 3:
                {
                    //Recup des resultat de la recherche
                    Catalogue *resultat = RechercheTrajet();

                    //Sauvegarde temporaire du catalogue entier
                    Catalogue *temp = this->catalogue;

                    //on remplace le catalogue de l'instance par celui du resultat de la recherche et on l'affiche
                    this->catalogue = resultat;

                    cout << "Résultat de la requête : " << endl;
                    Afficher();
                    cout << endl;

                    //Suppression du catalogue de resultat
                    delete resultat;

                    //Recuperation du catalogue entier
                    this->catalogue = temp;
                }

                break;

            case 4:
                ok = false;
                break;

            default:
                cout << "Erreur de numero !" << endl;
                break;

            }


        } catch(exception &ex) {
            cout << "Il faut saisir un nombre !" << endl;

            cin.clear();
            cin.ignore(300, '\n');
        }

    }

} //---- Fin de Start


//-------------------------------------------- Constructeurs - destructeur



Terminal::Terminal ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Terminal>" << endl;
#endif

    catalogue = new Catalogue();


} //----- Fin de Terminal


Terminal::~Terminal ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Terminal>" << endl;
#endif

    delete catalogue;

} //----- Fin de ~Terminal


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

