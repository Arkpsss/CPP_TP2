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



bool LinkedList::AddCoherent(Trajet *trajet) 
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





void LinkedList::AddOrdreAlphabetique(Trajet *trajet) {

    if (tete == NULL) {
        this->AddFirst(trajet);
    }

    else {

        RecAddAlpha(trajet, tete, tete, true);

    }

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

//----------------------------------------------------- Méthodes privées


void LinkedList::RecAddAlpha(Trajet *trajet, Element *current, Element *prec, bool depart)
{

    ComparaisonAlphabetique res;

    if (current == NULL) {
        Element *e = new Element(trajet, current);
        prec->SetNext(e);
        taille++;
        return;
    }

    if (depart) {
        const char* tD = trajet->GetVilleDepart();
        const char* cD = current->GetTrajet()->GetVilleDepart();

        res = ordre_alphabetique(tD, cD);

    }
    
    else {
        const char* tA = trajet->GetVilleArrivee();
        const char* cA = current->GetTrajet()->GetVilleArrivee();

        res = ordre_alphabetique(tA, cA);
    }


    //La ville de départ du trajet est avant la ville de depart de l'element courant
    if (res == ARG1) {
        Element *e = new Element(trajet, current);

        if (current == tete) {
            this->tete = e;
        }
        else {
            prec->SetNext(e);
        }
        taille++;
    }



    //La ville de depart du trajet est la meme que la ville de départ de l'element courant
    else if (res == EGAL) {

        if (!depart) {
            Element *e = new Element(trajet, current);

            if (current == tete) {
                this->tete = e;
                taille++;
            }
            else {
                prec->SetNext(e);
                taille++;
            }
        }
        else {
            //debut recherche sur ville arrivée
            RecAddAlpha(trajet, current, prec, !depart);
            return;
        }
        
        

    }

    //La ville de depart du trajet est après la ville de départ de l'element courant
    else if (res == ARG2) {

        RecAddAlpha(trajet, current->GetNext(), current, depart);
        return;
        
    }

} //--- Fin de RecAddAlpha



void LinkedList::AddFirst (Trajet *trajet) {

    Element *e = new Element(trajet, tete);

    this->tete = e;

    taille++;

} //---- Fin de AddFirst