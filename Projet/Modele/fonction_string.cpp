/*************************************************************************
                           fonction_string  - fonctions facilitant la gestion des strings C
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et gabriel.canaple@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <fonction_string> (fichier fonction_string.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "fonction_string.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

#define min(a,b) a > b ? b : a

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void vider_buffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
 
int recup_saisi_string(char *chaine, int longueur)
{
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            vider_buffer();
        }
        return 1;
    }
    else
    {
        vider_buffer();
        return 0;
    }
}

char* realloc(char* text, int newSize) 
{

    char* res = new char[newSize];

    if (text != NULL) {
        strcpy(res, text);
        delete [] text;
    }

    return res;

}

ComparaisonAlphabetique ordre_alphabetique(const char* s1, const char* s2) {

    if (strcmp(s1, s2) == 0) {
        return EGAL;
    }

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int min = min(len1, len2);

    for (int i = 0; i < min; i++) {

        if (s1[i] < s2[i]) {
            return ARG1;
        }
        else if (s2[i] < s1[i]) {
            return ARG2;
        }

    }

    if (min == len1) {
        return ARG1;
    }
    else {
        return ARG2;
    }

}