/*************************************************************************
                           LinkedList  -  Classe implémentant une
                                          liste chaînée
                             -------------------
    début                : 21/11/2022
    copyright            : (C) 2022 par G.Canaple et J.Bondyfalat
    e-mail               : gabriel.canaple@insa-lyon.fr,
                           julien.bodyfalat@insa-lyon.fr
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

Element * LinkedList::GetHead () const
{
return this->tete;
} //----- Fin de GetHead


void LinkedList::Afficher () const
// Algorithme :
//
{
    Element *current = tete;
    for (int i=0; i<taille; i++)
    {
        cout << current->GetTrajet()->GetDescription() << endl;
        current = current->GetNext();
    }
} //----- Fin de Afficher

bool LinkedList::AddTrie(Trajet *trajet) {

    Element *current = tete;
    Element *prec = tete;

    //On ajoute en tête si la liste est vide
    if (tete == NULL) {
        this->AddFirst(trajet);
        return true;
    }

    //Si la ville d'arrivée du trajet est la ville de depart de l'element
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

/*
void LinkedList::AddOrdreAlphab (Trajet *trajet, bool _deleteTrajet)
// Algorithme :
//
{
    if (tete==NULL)
    {
        Element *e = new Element (trajet,NULL);
        tete = e;
    }
    else if (strcmp(trajet->GetVilleDepart(),tete->GetTrajet()->GetVilleDepart()) < 0)
    {
        Element *e = new Element (trajet,tete);
        tete=e;
        return;
    }
    else
    {
        Element *current = tete;
        while (current->GetNext()!=NULL)
        {
            if (strcmp(trajet->GetVilleDepart(),current->GetNext()->GetTrajet()->GetVilleDepart()) < 0)
                //Si la ville de départ est avant dans l'ordre alphabétique, on a la place finale
            {

                break;
            }
            else if (strcmp(trajet->GetVilleDepart(),current->GetNext()->GetTrajet()->GetVilleDepart()) == 0)
                //Si même ville de départ, on compare les villes d'arrivée
            {
                while()
                {

                }
                break;
            }
            current=current->GetNext();
        }
    }

} //----- Fin de Afficher
*/
void LinkedList::AddFirst (Trajet *trajet, bool _deleteTrajet) {
    Element *e = new Element(trajet, tete);
    e->SetDeleteTrajet(_deleteTrajet);
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
