/*************************************************************************
                           main  -  Module principale
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et gabriel.canaple@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <main> (fichier main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Modele/Trajet.h"
#include "Modele/TrajetSimple.h"
#include "Modele/TrajetCompose.h"

#include "Vue/Terminal.h"


///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées


static void test_affichage_trajet_simple() {


  Trajet *t = new TrajetSimple("Paris", "Londres", "Bateau");

  //t->Afficher();

  delete t;

}

static void test_affichage_trajet_compose() {


  Trajet *t1 = new TrajetSimple("Paris", "Londres", "bateau");
  Trajet *t2 = new TrajetSimple("Londres", "Los Angeles", "avion");

  Trajet* tab[2] = {t1,t2};

  Trajet *t = new TrajetCompose(tab, 2, "Paris", "Los Angeles");

  //t->Afficher();

  delete t;

}

static void test_creation_linkedlist() {
  LinkedList *l = new LinkedList();

  //l->AddOrdreAlphabetique(new TrajetSimple("Paris", "Londres", "bateau"));
  l->AddCoherent(new TrajetSimple("Londres", "Los Angeles", "avion"));

  delete l;
}


static void test_affichage_Terminal() {

  Terminal term = Terminal();

  term.Afficher();

}

static void test_menu_Terminal() {

  Terminal term = Terminal();

  term.Start();

}

static void test_detection_vD_vA_TrajetCompose() {
  Trajet *t1 = new TrajetSimple("Paris", "Londres", "bateau");
  Trajet *t2 = new TrajetSimple("Londres", "Los Angeles", "avion");

  Trajet* tab[2] = {t1,t2};

  Trajet *t = new TrajetCompose(tab, 2);

  cout << t->GetDescription() << endl;
}

static void test_ordre_catalogue() {

  Trajet *t1 = new TrajetSimple("Paris", "Marseille", "Train");
  Trajet *t2 = new TrajetSimple("Londres", "Rotterdam", "Train");
  Trajet *t3 = new TrajetSimple("Paris", "Orleans", "Train");
  Trajet *t4 = new TrajetSimple("Mama", "Nana", "t");
  Trajet *t5 = new TrajetSimple("Paris","Marseille","Avion");
 
  Catalogue *c = new Catalogue();

  c->Insert(t1);
  c->Insert(t2);
  c->Insert(t3);
  c->Insert(t4);
  c->Insert(t5);

  cout << c->GetDescriptionOf(1);
  cout << c->GetDescriptionOf(2);
  cout << c->GetDescriptionOf(3);
  cout << c->GetDescriptionOf(4);
  cout << c->GetDescriptionOf(5);


  delete c;

}

static void test_creation_catalogue ()
{
    Trajet *ts3 = new TrajetSimple("Londres", "Bruxelles", "bus");
    Trajet *ts4 = new TrajetSimple("Berlin", "Munich", "avion");
    Trajet *ts5 = new TrajetSimple("Calais", "Marseille", "voiture");
    Trajet *ts6 = new TrajetSimple("New York", "Los Angeles", "avion");
    Trajet *ts7 = new TrajetSimple("New York", "Los Angeles", "train");

    Trajet *ts1 = new TrajetSimple("Paris", "Londres", "bateau");
    Trajet *ts2 = new TrajetSimple("Londres", "Los Angeles", "avion");
    Trajet *ts8 = new TrajetSimple("Los Angeles", "New York", "train");
    Trajet *tc1tab [] = {ts1,ts2,ts8};
    Trajet *tc1 = new TrajetCompose(tc1tab,3,"Paris","New York");

    LinkedList *listeCatalogue = new LinkedList();
    listeCatalogue->AddOrdreAlphabetique(ts3);
    listeCatalogue->AddOrdreAlphabetique(ts4);
    listeCatalogue->AddOrdreAlphabetique(ts5);
    listeCatalogue->AddOrdreAlphabetique(ts6);
    listeCatalogue->AddOrdreAlphabetique(ts7);
    listeCatalogue->AddOrdreAlphabetique(tc1);
    Catalogue *catalogue = new Catalogue(listeCatalogue);
    if (catalogue->GetNbTrajet() == 0) {
        cout << "Le catalogue est vide." << endl;
    }

    for (int i = 1; i <= catalogue->GetNbTrajet(); i++) {

        cout << "\t\t" << "Trajet n° " << i << "/ " << endl;

        cout << catalogue->GetDescriptionOf(i) << endl;
    }
    delete(catalogue);
}

static void test_recherche_simple_catalogue ()
{
    Trajet *ts3 = new TrajetSimple("Londres", "Bruxelles", "bus");
    Trajet *ts4 = new TrajetSimple("Berlin", "Munich", "avion");
    Trajet *ts5 = new TrajetSimple("Calais", "Marseille", "voiture");
    Trajet *ts6 = new TrajetSimple("New York", "Los Angeles", "avion");
    Trajet *ts7 = new TrajetSimple("New York", "Los Angeles", "train");
    Trajet *ts9 = new TrajetSimple("Paris","New York", "nage");
    Trajet *ts1 = new TrajetSimple("Paris", "Londres", "bateau");
    Trajet *ts2 = new TrajetSimple("Londres", "Los Angeles", "avion");
    Trajet *ts8 = new TrajetSimple("Los Angeles", "New York", "train");
    Trajet *tc1tab [] = {ts1,ts2,ts8};
    Trajet *tc1 = new TrajetCompose(tc1tab,3,"Paris","New York");

    LinkedList *listeCatalogue = new LinkedList();
    listeCatalogue->AddOrdreAlphabetique(ts3);
    listeCatalogue->AddOrdreAlphabetique(ts4);
    listeCatalogue->AddOrdreAlphabetique(ts5);
    listeCatalogue->AddOrdreAlphabetique(ts6);
    listeCatalogue->AddOrdreAlphabetique(ts7);
    listeCatalogue->AddOrdreAlphabetique(ts9);
    listeCatalogue->AddOrdreAlphabetique(tc1);
    Catalogue *catalogue = new Catalogue(listeCatalogue);
    Catalogue *resultat = catalogue->RechercheSimple("Paris", "New York");
    

    if (resultat->GetNbTrajet() == 0) {
        cout << "Le catalogue est vide." << endl;
    }

    for (int i = 1; i <= resultat->GetNbTrajet(); i++) {

        cout << "\t\t" << "Trajet n° " << i << "/ " << endl;

        cout << resultat->GetDescriptionOf(i) << endl;
    }

    delete(catalogue);
    delete(resultat);
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


int main(int argc, char const *argv[])
{
  //Pour démarrer le terminal
  Terminal term = Terminal();
  term.Start(); 
  return 0;
}
