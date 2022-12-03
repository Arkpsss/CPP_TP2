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



bool LinkedList::AddTrie(Trajet *trajet) 
// Algorithme :
// Distingue 4 cas :
// - la liste est vide donc pas de comparaison à faire
// - la ville d'arrivé est la ville de départ du premier élement -> ajout en tete
// - la ville de départ du trajet est la ville d'arrivé d'un trajet au milieu de la liste -> ajout en milieu
// - la ville d'arrivé du dernier trajet de la liste est la ville de départ du trajet à ajouter -> ajout en fin
{

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

//-------------------------------------------- Constructeurs - destructeur


LinkedList::LinkedList(Element *tete, int taille) : tete(tete), taille(taille)
{
#ifdef MAP
    cout << "Appel au constructeur de <LinkedList>" << endl;
#endif
}

LinkedList::~LinkedList ( )
// Algorithme :
// Parcourt la liste et delete chaque element
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
