/*************************************************************************
                           LinkedList  -  Classe implémentant une liste chaînée
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr, julien.bodyfalat@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LinkedList> (fichier LinkedList.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LinkedList.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void LinkedList::Add (Trajet *trajet, int position)
// Algorithme :
//
{
    //Si on ajoute en tête de liste
    if (position==0)
    {
        Element *nouvelElement = new Element(trajet,tete);
        tete = nouvelElement;
        return;
    }

    //Si on ajoute dans le reste de la liste
    Element *current=tete;
    for (int i=0; i<position-1; i++)
    {
        current=current->GetNext();
    }

    Element *nouvelElement = new Element (trajet, current->GetNext());
    current->SetNext(nouvelElement);
} //----- Fin de Add

bool LinkedList::AddTrie(Trajet *trajet) {

    Element *current = tete;
    Element *prec = tete;

    if (tete == NULL) {
        this->AddFirst(trajet);
        return true;
    }

    //Ville d'arrivee du trajet est la ville de depart de l'element
    if (compare(current->GetTrajet(), trajet)) {



        Element *e = new Element(trajet, current);
        this->tete = e;
        taille++;

        return true;
    }

    else {

        for (int i = 0; i < taille; i++) {
            current = prec->GetNext();

            if (current == NULL) {
                if(compare(trajet,prec->GetTrajet())) {
                    Element *e = new Element(trajet, NULL);
                    prec->SetNext(e);
                    taille++;
                    return true;
                }
                else {
                    return false;
                }
            }

            else if (compare(current->GetTrajet(), trajet)) {
                Element *e = new Element(trajet, current);
                prec->SetNext(e);

                taille++;
                return true;
            }

            prec = current;
        }

        return false;
    }

}


void LinkedList::AddFirst (Trajet *trajet) {

    Element *e = new Element(trajet, tete);

    this->tete = e;

    taille++;

}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*LinkedList::LinkedList ( const LinkedList & uneLinkedList )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LinkedList>" << endl;
#endif
    tete=uneLinkedList.tete;
    taille=uneLinkedList.taille;
} //----- Fin de LinkedList (constructeur de copie)
*/



LinkedList::LinkedList(Element *tete, int taille) : tete(tete), taille(taille)
// Algorithme :
// Met tete à l'attribut tete et taille à l'attribut taille
{
#ifdef MAP
    cout << "Appel au constructeur de <LinkedList>" << endl;
#endif
}

LinkedList::~LinkedList ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LinkedList>" << endl;
#endif
    Element *current = tete;
    for (int i=0; i<taille; i++)
    {
        Element *temp = current->GetNext();
        delete(current);
        current=temp;
    }
} //----- Fin de ~LinkedList


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
