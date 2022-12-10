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

#include <iostream>
using namespace std;

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

void to_upper(char *dst, const char *src) {

    for (unsigned int i = 0; i < strlen(src); i++) {
        dst[i] = toupper(src[i]);
    }

}

ComparaisonAlphabetique ordre_alphabetique(const char* s1, const char* s2) {

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    char *str1 = new char[len1+1];
    char *str2 = new char[len2+1];

    str1[len1] = '\0';
    str2[len2] = '\0';

    to_upper(str1, s1);
    to_upper(str2, s2);

    if (strcmp(str1, str2) == 0) {

        delete [] str1;
        delete [] str2;

        return EGAL;
    }


    int min = min(len1, len2);

    for (int i = 0; i < min; i++) {

        if (str1[i] < str2[i]) {

            delete [] str1;
            delete [] str2;

            return ARG1;
        }
        else if (str2[i] < str1[i]) {

            delete [] str1;
            delete [] str2;

            return ARG2;
        }

    }

    delete [] str1;
    delete [] str2;

    if (min == len1) {
        return ARG1;
    }
    else {
        return ARG2;
    }

}