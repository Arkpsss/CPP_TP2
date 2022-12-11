/*************************************************************************
         Catalogue  -  Classe implémentant un catalogue de trajets
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et 
                                        Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et 
                           gabriel.canaple@insa-lyon.fr
*************************************************************************/

//----- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Insert(Trajet *trajet) {

    list->AddOrdreAlphabetique(trajet);

} //---- Fin de Insert


const char* Catalogue::GetDescriptionOf(int numeroTrajet) const
// Algorithme :
// Parcourt (numeroTrajet) éléments de la liste chainée
{
    if (numeroTrajet > list->GetTaille() || numeroTrajet < 0) {
        return NULL;
    }

    Element *e = list->GetHead();

    for (int i = 1; i < numeroTrajet; i++) {
        e = e->GetNext();
    }

    return e->GetTrajet()->GetDescription();

} //---- Fin de GetDescriptionOf


Catalogue *Catalogue::RechercheSimple (const char *villeDepart, 
    const char *villeArrivee) const
// Algorithme :
// 
{
    //Si la liste est vide, on renvoie un catalogue vide
    if (list->GetTaille() == 0)
        return new Catalogue();

    //Création d'une liste pour les trajets qui correspondent
    LinkedList *matching = new LinkedList(); 
                                            
    Element *current = list->GetHead();
    //On parcourt la liste, et on évalue l'égalité entre les villes
    for (int i = 0; i<list->GetTaille(); i++)
    {
        if (strcmp(current->GetTrajet()->GetVilleDepart(), villeDepart) == 0
        && strcmp(current->GetTrajet()->GetVilleArrivee(), villeArrivee) == 0)
        {
            matching->AddOrdreAlphabetique(current->GetTrajet(),false);
        }
        current = current->GetNext();
    }
    return new Catalogue(matching);
} //---- Fin de RechercheSimple

//-------------------------------------------- Constructeurs - destructeur



Catalogue::Catalogue (LinkedList *_list) : list(_list)
// Algorithme :
// aucun
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
// aucun
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

    delete list;

} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

