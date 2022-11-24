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

  delete l;
}


static void test_affichage_Terminal() {

  Terminal term = Terminal();

  term.Afficher();

}


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


int main(int argc, char const *argv[])
{
  
  test_affichage_Terminal();

  return 0;
}