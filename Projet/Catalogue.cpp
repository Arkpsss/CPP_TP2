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

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Insert(Trajet *trajet) {

    list->AddFirst(trajet);

}

void Catalogue::Afficher() {

    Element *e = list->GetHead();

    for (int i = 1; i < list->GetTaille(); i++) {

        cout << "\t\t" << "Trajet n° " << i << "/ " << endl;

        e->GetTrajet()->Afficher();

        e = e->GetNext();
    }

    cout << "\t" << list->GetTaille() << "/ " << endl;
    e->GetTrajet()->Afficher();
    
}



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

