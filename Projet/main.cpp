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
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"


///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées


static void test_affichage_trajet_simple() {


  Trajet *t = new TrajetSimple("Paris", "Londres", "Bateau");

  t->Afficher();

  delete t;

}

static void test_affichage_trajet_compose() {


  LinkedList *l = new LinkedList();

  l->AddFirst(new TrajetSimple("Paris", "Londres", "bateau"));
  l->AddTrie(new TrajetSimple("Londres", "Los Angeles", "avion"));

  Trajet *t = new TrajetCompose(l);

  t->Afficher();

  delete t;

}

static void test_creation_linkedlist() {
  LinkedList *l = new LinkedList();

  l->AddFirst(new TrajetSimple("Paris", "Londres", "bateau"));
  l->AddTrie(new TrajetSimple("Londres", "Los Angeles", "avion"));

  delete l;
}


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques


int main(int argc, char const *argv[])
{
  
  test_creation_linkedlist();

  return 0;
}