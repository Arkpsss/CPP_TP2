/*************************************************************************
           TrajetCompose  -  Classe implémentant un trajet composé
                             -------------------
    début                : 28/11/2022
    copyright            : (C) 2022 par Julien Bondyfalat et 
                                        Gabriel Canaple
    e-mail               : gabriel.canaple@insa-lyon.fr, 
                           julien.bondyfalat@insa-lyon.fr
*************************************************************************/

//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"


//------------------------------------------------------------- Constantes

#define NB_CHIFFRES 4  //nombre de chiffre que peut contenir une étape 
                       //-> utile pour la conversion int to char*
#define DESC 100       //taille du superflux de description

//----------------------------------------------------------------- PUBLIC


//-------------------------------------------- Constructeurs - destructeur


TrajetCompose::TrajetCompose( Trajet **tab, int nb, const char *vD, 
    const char *vA ) : Trajet(vD, vA)
// Algorithme :
// Ajoute d'abord chaque trajet en veillant à ce qu'ils soient
// valides.
// Ensuite, initialise les villes de départ et d'arrivée en fonction 
// de s'ils sont renseignés ou non.
// Finalement, construit la description du trajet.
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

    list = new LinkedList();
    
    //Ajout des trajets
    for (int i = nb-1; i >= 0; i--) {
        if (list->AddCoherent(tab[i]) == false) {
            delete list;
            throw MauvaiseComposition(tab, i);
        }
    }
    
    //Initialisation de vA et vD s'ils ne sont pas renseignés
    if (vD == NULL && vA == NULL) {
        SetVilleDepart(list->GetHead()->GetTrajet()->GetVilleDepart());

        Element *e = list->GetHead();
        for (int i = 1; i < list->GetTaille(); i++) {
            e = e->GetNext();
        }

        SetVilleArrivee(e->GetTrajet()->GetVilleArrivee());
    }
    
    description = ToString();
} //---- Fin du constructeur de TrajetCompose



TrajetCompose::~TrajetCompose ()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    delete list;
    
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes privées

char* TrajetCompose::ToString() const 
// Algorithme :
// Construit la description du trajet en concaténant ses caracéristiques.
// Effectue cette opération pour chaque sous-trajet.
{

    int taille = strlen(villeDepart) + strlen(villeArrivee) + DESC;

    char *res = new char[taille];
    res[0] = '\0';

    strcat(res, "   Ville de départ : ");
    strcat(res, villeDepart);
    strcat(res, "\n   Ville d'arrivee : ");
    strcat(res, villeArrivee);
    strcat(res, "\nEtapes du trajet : \n");

    Element *e = list->GetHead();

    for (int i = 1; i <= list->GetTaille(); i++) {

        const char *text = e->GetTrajet()->GetDescription();

        while (strlen(text) + 15 >= taille - strlen(res)-1) {
            res = realloc(res, taille*2);
            taille *= 2;
        }

        //conversion i to char*
        char etape[NB_CHIFFRES];
        sprintf(etape, "%d", i);

        strcat(strcat(strcat(res, "\t"), etape), "/ \n");

        strcat(res, text);

        Trajet::deleteDescription(e->GetTrajet());

        e = e->GetNext();
    }

    return res;

}
