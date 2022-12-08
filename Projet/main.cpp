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

  //l->AddFirst(new TrajetSimple("Paris", "Londres", "bateau"));
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
  Trajet *t3 = new TrajetSimple("Paris", "Orlean", "Train");
  Trajet *t4 = new TrajetSimple("Mama", "Nana", "t");
 
  Catalogue *c = new Catalogue();

  c->Insert(t1);
  c->Insert(t2);
  c->Insert(t3);
  c->Insert(t4);

  cout << c->GetDescriptionOf(1);
  cout << c->GetDescriptionOf(2);
  cout << c->GetDescriptionOf(3);
  cout << c->GetDescriptionOf(4);


  delete c;

}


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


int main(int argc, char const *argv[])
{
  
  //test_affichage_Terminal();

  //test_menu_Terminal();

  //test_detection_vD_vA_TrajetCompose();

  //test_ordre_catalogue();

  Terminal term = Terminal();
  term.Start();

  

  return 0;
}