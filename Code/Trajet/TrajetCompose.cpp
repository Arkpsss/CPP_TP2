/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher() const {

    cout << "Ville de départ : " << villeDepart << endl;
    cout << "Ville d'arrivee : " << villeArrivee << endl;
    cout << "Etapes du trajet : " << endl

    Element *e = listTrajets->GetHead();

    for (int i = 1; i < listTrajets->GetTaille(); i++) {

        cout << "\t" << i << "/ ";

        e->GetTrajet()->Afficher();

        e = e->GetNext();
    }

    cout << "\t" << listTrajets->GetTaille() << "/ ";
    e->GetTrajet()->Afficher();

}


//-------------------------------------------- Constructeurs - destructeur



TrajetCompose::TrajetCompose (const LinkedList *l, const char *vD = "", const char *vA = "")
    : Trajet(vD, vA)

{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    
    if (strcmp(vD, "") == 0 || strcmp(vA, "") == 0) {
        Element *d = listTrajets->GetHead();
        Element *a = listTrajets->GetHead();

        for (int i = 1; i < listTrajets->GetTaille(); i++) {
            a = a->GetNext();
        }

        delete [] vD;
        delete [] vA;

        vD = new char[strlen(d->GetTrajet()->GetVilleDepart()) +1];
        vA = new char[strlen(a->GetTrajet()->GetVilleArrivee()) +1];

        strcpy(vD, d->GetTrajet()->GetVilleDepart());
        strcpy(vA, a->GetTrajet()->GetVilleArrivee());

    }
    

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    delete listTrajets;
    
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

