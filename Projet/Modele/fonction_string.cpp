/*************************************************************************
                           fonction_string  - fonctions facilitant la 
                                              gestion des strings C
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et 
                                        Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et 
                           gabriel.canaple@insa-lyon.fr
*************************************************************************/

// Réalisation du module <fonction_string> (fichier fonction_string.cpp) 

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
// Algorithme :
// Récupère les caractères des stdin jusqu'à tomber sur un retour à la 
// ligne pour vider le buffer
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
 
int recup_saisi_string(char *chaine, int longueur)
// Algorithme :
// Vérifie que la récupération du string à partir de stdin s'est bien
// déroulée 
{
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n'); // recherche de la première
                                               // occurence du caractère
                                               // \n au sein de chaine

        if (positionEntree != NULL) //Signale la fin de la chaine
        {
            *positionEntree = '\0';
        }
        else //Si \n n'a pas été trouvé
        {
            vider_buffer();
        }
        return 1;
    }
    else //S'il y a eu un problème lors de la saisie
    {
        vider_buffer();
        return 0;
    }
}

char* realloc(char* text, int newSize) 
// Algorithme :
// Copie simplement un tableau de char dans un tableau de char plus grand
{

    char* res = new char[newSize];

    if (text != NULL) {
        strcpy(res, text);
        delete [] text;
    }

    return res;

}

void to_upper(char *dst, const char *src) {
// Algorithme :
// Utilise la fonction toupper pour mettre en majuscule chacun des caractères
    for (unsigned int i = 0; i < strlen(src); i++) {
        dst[i] = toupper(src[i]);
    }

}

ComparaisonAlphabetique ordre_alphabetique(const char* s1, const char* s2) {
// Algorithme :
// Recrée d'abord deux chaines de caractère modifiable afin de les mettre en
// majuscules pour faciliter la comparaison.
// Puis évalue chacun des cas possibles : 
// - d'abord l'égalité, avec strcmp
// - puis compare chacun des caractères individuellement pour obtenir l'ordre
// - puis, si deux mots ont le meme début (ex : diction et dictionnaire),
//   on compare leurs tailles respectives

    //Mise en majuscules
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    char *str1 = new char[len1+1];
    char *str2 = new char[len2+1];

    str1[len1] = '\0';
    str2[len2] = '\0';

    to_upper(str1, s1);
    to_upper(str2, s2);

    //Si les deux chaines sont égales
    if (strcmp(str1, str2) == 0) {

        delete [] str1;
        delete [] str2;

        return EGAL;
    }


    int min = min(len1, len2);
    //Comparaison individuelle
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
    //Comparaison des tailles
    if (min == len1) {
        return ARG1;
    }
    else {
        return ARG2;
    }

}
