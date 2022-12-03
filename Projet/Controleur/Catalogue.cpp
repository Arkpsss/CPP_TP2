/*************************************************************************
                           Catalogue  -  Classe imlémentant un catalogue de Trajet
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et gabriel.canaple@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

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

    list->AddFirst(trajet);

} //---- Fin de Insert

const char* Catalogue::GetDescriptionOf(int numeroTrajet) const {

    if (numeroTrajet > list->GetTaille() || numeroTrajet < 0) {
        return NULL;
    }

    Element *e = list->GetHead();

    for (int i = 1; i < numeroTrajet; i++) {
        e = e->GetNext();
    }

    return e->GetTrajet()->GetDescription();

} //---- Fin de GetDescriptionOf



//-------------------------------------------- Constructeurs - destructeur



Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

    list = new LinkedList();

} //----- Fin de Catalogue


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

