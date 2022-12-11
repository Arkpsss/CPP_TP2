/*************************************************************************
           LinkedList  -  Classe implémentant une liste chaînée simple
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr, 
                           julien.bondyfala@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <LinkedList> (fichier LinkedList.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LinkedList.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



bool LinkedList::AddCoherent(Trajet *trajet, bool _deleteTrajet) 
// Algorithme :
// Distingue 4 cas :
// - la liste est vide, donc pas de comparaison à faire, donc ajout en
//   tete
// - la ville d'arrivée est la ville de départ du premier élement, donc 
//   ajout en tete
// - la ville de départ du trajet est la ville d'arrivée d'un trajet au 
//   milieu de la liste -> ajout en milieu de liste
// - la ville d'arrivée du dernier trajet de la liste est la ville de 
//   départ du trajet à ajouter -> ajout en fin
{

    Element *current = tete;
    Element *prec = tete;

    //Liste vide --> ajout en tete
    if (tete == NULL) {
        this->AddFirst(trajet, _deleteTrajet);
        return true;
    }

    // La ville d'arrivée du trajet est la ville de depart de la tete
    // --> Ajout en tete
    if (compare(current->GetTrajet(), trajet)) {
        Element *e = new Element(trajet, current, _deleteTrajet);
        this->tete = e;
        taille++;
        
        return true;
    }

    else {

        for (int i = 0; i < taille; i++) {
            current = prec->GetNext();
            
            // On est en fin de liste
            if (current == NULL) {
                // Ajout en fin
                if(compare(trajet,prec->GetTrajet())) {
                    Element *e = new Element(trajet, NULL, _deleteTrajet);
                    prec->SetNext(e);
                    taille++;
                    return true;
                }
                // Si pas de correspondance, pas d'ajout
                else {
                    return false;
                }
            }
            //Ajout en milieu de liste
            else if (compare(current->GetTrajet(), trajet)) {
                Element *e = new Element(trajet, current, _deleteTrajet);
                prec->SetNext(e);

                taille++;
                return true;
            }

            prec = current;
        }

        return false;
    }

}





void LinkedList::AddOrdreAlphabetique(Trajet *trajet, bool _deleteTrajet) 
// Algorithme :
// Deux cas :
// - On ajoute en tete de liste si la liste est nulle
// - On fait appel à RecAddAlpha si la liste n'est pas nulle
{
    
    if (tete == NULL) {
        this->AddFirst(trajet, _deleteTrajet);
    }

    else {
        RecAddAlpha(trajet, tete, tete, true, _deleteTrajet);
    }

}




//-------------------------------------------- Constructeurs - destructeur


LinkedList::LinkedList(Element *tete, int taille) : 
  tete(tete), taille(taille)
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


void LinkedList::RecAddAlpha(Trajet *trajet, Element *current, 
   Element *prec, bool depart, bool _deleteTrajet)
  // Algorithme :
  //
{

    ComparaisonAlphabetique res;
    
    //Si on est en fin de liste, on ajoute
    if (current == NULL) {
        Element *e = new Element(trajet, current, _deleteTrajet);
        prec->SetNext(e);
        taille++;
        return;
    }

    //Comparaison des villes de départ
    if (depart) {
        const char* tD = trajet->GetVilleDepart();
        const char* cD = current->GetTrajet()->GetVilleDepart();

        res = ordre_alphabetique(tD, cD);

    } 
    //Comparaison des villes d'arrivée
    else {
        const char* tA = trajet->GetVilleArrivee();
        const char* cA = current->GetTrajet()->GetVilleArrivee();

        res = ordre_alphabetique(tA, cA);
    }


    //La ville de départ du trajet est avant la ville de départ de
    //l'élément courant, on a donc trouvé l'encadrement
    if (res == ARG1) {
        Element *e = new Element(trajet, current, _deleteTrajet);

        if (current == tete) {
            this->tete = e;
        }
        else {
            prec->SetNext(e);
        }
        taille++;
    }


    //La ville de depart du trajet est la meme que la ville de départ 
    //de l'élément courant, il faut comparer les villes d'arrivée
    else if (res == EGAL) {
        
        //Si les villes d'arrivée sont égales, on ajoute à la liste
        if (!depart) {
            Element *e = new Element(trajet, current, _deleteTrajet);

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
            //debut de la recherche sur la ville d'arrivée
            RecAddAlpha(trajet, current, prec, !depart, _deleteTrajet);
            return;
        }
    }


    //La ville de départ du trajet est après la ville de départ de l'element 
    //courant, on relance donc la recherche
    else if (res == ARG2) {

        RecAddAlpha(trajet, current->GetNext(), current, depart, _deleteTrajet);
        return;
        
    }

} //--- Fin de RecAddAlpha



void LinkedList::AddFirst (Trajet *trajet, bool _deleteTrajet) 
// Algorithme :
// aucun
{

    Element *e = new Element(trajet, tete, _deleteTrajet);
    this->tete = e;

    taille++;

} //---- Fin de AddFirst
