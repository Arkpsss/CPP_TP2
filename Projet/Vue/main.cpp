/*************************************************************************
                           main  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <main> (fichier main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "../Modele/Trajet.h"
#include "../Modele/TrajetSimple.h"
#include "../Modele/TrajetCompose.h"

#include "Terminal.h"


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

  l->AddFirst(new TrajetSimple("Paris", "Londres", "bateau"));
  l->AddTrie(new TrajetSimple("Londres", "Los Angeles", "avion"));
  Trajet *tctab [] = {new TrajetSimple("Paris", "Londres", "bateau"),
                      new TrajetSimple("Londres", "Los Angeles", "avion")};
  Trajet *tc = new TrajetCompose (tctab,2,"Paris","Los Angeles");
  l->AddFirst(tc);
  delete l;
}


static void test_affichage_Terminal() {

  Terminal term = Terminal();

  term.Afficher();

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
    listeCatalogue->AddFirst(ts3);
    listeCatalogue->AddFirst(ts4);
    listeCatalogue->AddFirst(ts5);
    listeCatalogue->AddFirst(ts6);
    listeCatalogue->AddFirst(ts7);
    listeCatalogue->AddFirst(tc1);
    Catalogue *catalogue = new Catalogue(listeCatalogue);
    for (int i=0; i<catalogue->GetNbTrajet(); i++)
    {
        std::cout << catalogue->GetDescriptionOf(i) << std::endl;
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
    listeCatalogue->AddFirst(ts3);
    listeCatalogue->AddFirst(ts4);
    listeCatalogue->AddFirst(ts5);
    listeCatalogue->AddFirst(ts6);
    listeCatalogue->AddFirst(ts7);
    listeCatalogue->AddFirst(ts9);
    listeCatalogue->AddFirst(tc1);
    Catalogue *catalogue = new Catalogue(listeCatalogue);
    Catalogue *resultat = catalogue->RechercheSimple("Paris", "New York");
    resultat->Afficher();
    delete(catalogue);
    delete(resultat);
}


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


int main(int argc, char const *argv[])
{
  
  //test_affichage_Terminal();
  //test_affichage_trajet_compose();
  //test_creation_catalogue();
  test_recherche_simple_catalogue();
  return 0;
}