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

#define NB_CHIFFRES 4

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

char* TrajetCompose::ToString() const {

    int taille = strlen(villeDepart) + strlen(villeArrivee) + DESC;

    char *res = new char[taille];

    strcat(res, "   Ville de départ : ");
    strcat(res, villeDepart);
    strcat(res, "\n   Ville d'arrivee : ");
    strcat(res, villeArrivee);
    strcat(res, "\nEtapes du trajet : \n");

    Element *e = list->GetHead();

    for (int i = 1; i <= list->GetTaille(); i++) {

        char *text = e->GetTrajet()->GetDescription();

        while (strlen(text) + 15 >= taille - strlen(res)-1) {
            res = TrajetCompose::realloc(res, taille*2);
            taille *= 2;
        }

        //conversion i to char*
        char etape[NB_CHIFFRES];
        sprintf(etape, "%d", i);

        strcat(strcat(strcat(res, "\t"), etape), "/ \n");

        strcat(res, text);

        e->GetTrajet()->deleteDescription();

        e = e->GetNext();
    }

    /*
    char *text = e->GetTrajet()->GetDescription();

    while (strlen(text) + 10 >= taille - strlen(res)-1) {
        res = TrajetCompose::realloc(res, taille*2);
        taille *= 2;
    }

    char etape[NB_CHIFFRES];
    sprintf(etape, "%d", i);

    strcat(strcat(strcat(res, "\t"), etape), "/ \n");
    strcat(res, e->GetTrajet()->GetDescription());
    e->GetTrajet()->deleteDescription();*/

    return res;

}



//-------------------------------------------- Constructeurs - destructeur


/*
TrajetCompose::TrajetCompose (LinkedList *l, const char *vD, const char *vA)
    : Trajet(vD, vA)

{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

    listTrajets = l;
    
    if (strcmp(vD, "") == 0 || strcmp(vA, "") == 0) {
        Element *d = listTrajets->GetHead();
        Element *a = listTrajets->GetHead();

        for (int i = 1; i < listTrajets->GetTaille(); i++) {
            a = a->GetNext();
        }

        delete [] villeDepart;
        delete [] villeArrivee;

        villeDepart = new char[strlen(d->GetTrajet()->GetVilleDepart()) +1];
        villeArrivee = new char[strlen(a->GetTrajet()->GetVilleArrivee()) +1];

        strcpy(villeDepart, d->GetTrajet()->GetVilleDepart());
        strcpy(villeArrivee, a->GetTrajet()->GetVilleArrivee());

    }
    

} //----- Fin de TrajetCompose
*/

TrajetCompose::TrajetCompose( Trajet **tab, int nb, const char *vD, const char *vA )
    : Trajet(vD, vA)
{

#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

    list = new LinkedList();

    for (int i = nb-1; i >= 0; i--) {
        list->AddFirst(tab[i]);
    }


    description = ToString();

}



TrajetCompose::~TrajetCompose ()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    delete list;
    
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

