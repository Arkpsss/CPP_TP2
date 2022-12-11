/*************************************************************************
                   Terminal  -  Système d'IHM du projet
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et 
                                        Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et 
                           gabriel.canaple@insa-lyon.fr
*************************************************************************/

//------ Réalisation de la classe <Terminal> (fichier Terminal.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Terminal.h"

#include "../Modele/fonction_string.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Terminal::Afficher() const 
// Algorithme :
// Utilise la fonction GetDescriptionOf pour accéder aux trajets
{
    if (catalogue->GetNbTrajet() == 0) {
        cout << "Le catalogue est vide." << endl;
    }

    for (int i = 1; i <= catalogue->GetNbTrajet(); i++) {

        cout << "\t\t" << "Trajet n° " << i << "/ " << endl;

        cout << catalogue->GetDescriptionOf(i) << endl;

    }

} //---- Fin de Afficher



Trajet* Terminal::SaisirNewTrajet() const 
// Algorithme :
// Séparation en trois temps :
// 1) Demande du nombre d'étapes du trajet, en gérant les saisaies incorrectes
// 2) S'il y a une seule étape, création d'un TrajetSimple en demandant
//    à l'utilisateur ses caractéristiques.
// 3) S'il y a plus d'une étape, création d'un TrajetCompose avec possibilité
//    d'y inclure des trajets simples et des trajets composés, en rappelant
//    la fonction récursivement.
{

    int nbSousTrajets = 0;
    bool ok = true;
    
    //Etape 1
    while (ok) {
        cout << "Entrer le nombre d'escales que contient votre trajet : ";

        //Pour gerer les exceptions de mauvaise saisie
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
    //Etape 2
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
    //Etape 3
    else {

        Trajet* *tab = new Trajet*[nbSousTrajets];

        for (int i = 0; i < nbSousTrajets; i++) {
            cout << "\tSous-Trajet n° " << i+1 << endl;
            //On rappelle la fonction pour pouvoir saisir un trajet simple
            //ou un trajet composé
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



Catalogue* Terminal::RechercheTrajet() const 
// Algorithme :
// Fait appel aux fonctions fournies par fonction_string pour l'entrée,
// et fait appel à RechercheSimple de Catalogue pour trouver les
// trajets qui correspondent.
{
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




void Terminal::Start() 
// Algorithme :
// Utilisation d'un switch case afin de gérer tous les choix du menu
// A chaque fois, on récupère le nombre entier saisi par
// l'utilisateur, qui doit etre valide.
// Puis on utilise les fonctions adaptées de la classe pour chaque 
// choix différent.
{
    bool ok = true;
    cout << "Bienvenue dans le menu de gestion de catalogue de voyages" << endl;

    while (ok) {

        cout << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "|   1. Afficher le catalogue        |" << endl;
        cout << "|   2. Insérer un trajet            |" << endl;
        cout << "|   3. Rechercher un voyage         |" << endl;
        cout << "|   4. Quitter                      |" << endl;
        cout << "+-----------------------------------+" << endl;
        cout << "Saisir le numéro qui vous intéresse : ";

        int action;

        //Pour gerer les exceptions de mauvaise saisie
        cin.exceptions(ios_base::failbit);

        try {
            cin >> action;

            switch(action) {

            case 1:
                this->Afficher();
                break;

            case 2:
                {
                    //Saisie d'un trajet
                    Trajet *t = this->SaisirNewTrajet();
                    //Insertion dans le catalogue s'il n'y a pas eu 
                    //d'erreur de saisie.
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

                    //on remplace le catalogue de l'instance par celui du 
                    //resultat de la recherche et on l'affiche
                    this->catalogue = resultat;

                    cout << "\nRésultat de la requête : " << endl;
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

