/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Insert(Trajet *trajet) {

    list->AddFirst(trajet);

}

char* Catalogue::GetDescriptionOf(int numeroTrajet) const {

    if (numeroTrajet > list->GetTaille() || numeroTrajet < 0) {
        return NULL;
    }

    Element *e = list->GetHead();

    for (int i = 0; i < numeroTrajet; i++) {
        e = e->GetNext();
    }

    return e->GetTrajet()->GetDescription();

}

Catalogue *Catalogue::RechercheSimple (char *villeDepart, char *villeArrivee) const
{
#ifdef MAP
    cout << "Appel à RechercheSimple de Catalogue" << endl;
#endif
    //Si la liste est vide, on renvoie un catalogue vide
    if (list->GetTaille() == 0)
        return new Catalogue();

    LinkedList *matching = new LinkedList();
    Element *current = list->GetHead();
    for (int i = 0; i<list->GetTaille(); i++)
    {
        if (strcmp(current->GetTrajet()->GetVilleDepart(), villeDepart) == 0
        && strcmp(current->GetTrajet()->GetVilleArrivee(), villeArrivee) == 0)
        {
            matching->AddFirst(current->GetTrajet());
        }
        current = current->GetNext();
    }
    return new Catalogue(matching);
}

//-------------------------------------------- Constructeurs - destructeur



Catalogue::Catalogue(LinkedList *_list) : list(_list)
{
#ifdef MAP
    cout << "Appel au constructeur de Catalogue" << endl;
#endif
} //----- Fin du constructeur par défaut Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

    delete list;

} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

