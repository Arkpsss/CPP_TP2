/*************************************************************************
                           fonction_string  - fonctions facilitant la gestion des strings C
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Julien Bondyfalat et Gabriel Canaple
    e-mail               : julien.bondyfalat@insa-lyon.fr et gabriel.canaple@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <fonction_string> (fichier fonction_string.h) -------------------
#if ! defined ( FONCTION_STRING_H )
#define FONCTION_STRING_H

//------------------------------------------------------------------------
// Rôle du module <fonction_string>
// 
// Ce module inclut les fonctions de la bibliothèque cstring
// et implémente de nouvelles fonctions ordinaires utilisées dans le projet
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

#include <cstring>
#include <cstdio>
#include <cctype>

//------------------------------------------------------------- Constantes

#define TAILLE_MAX 1000

//------------------------------------------------------------------ Types

typedef enum ComparaisonAlphabetique {

  ARG1, ARG2, EGAL

} ComparaisonAlphabetique;

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void vider_buffer();
// Mode d'emploi : 
// élimine les caractères restants saisi par l'utilisateur qui n'ont pas été
// traité par le programme

int recup_saisi_string(char *chaine, int longueur);
// Mode d'emploi : 
// Lit tout une ligne saisi par l'utilisateur d'au plus longueur-1 caractères
// et la met dans chaine en rajoutant le caractère de fin de chaine '\0'
// Vide le buffer au cas où l'utilisateur a saisi plus 
// Retourne 1 si tout c'est bien passé
// 0 sinon

char* realloc(char* text, int newSize); 
// Mode d'emploi :
// Recopie le text dans une nouvelle chaine de caractère plus grande (newSize)
// delete le text


ComparaisonAlphabetique ordre_alphabetique(const char* s1, const char* s2);
// Mode d'emploi : 
// Compare 2 chaines de caractère par rapport à leur ordre alphabetique.


void to_upper(char *dst, const char *src);
// Mode d'emploi :
// Copie le contenu de la chaine src dans la chaine dst en mettant en majuscules 
// chaque caractères.


#endif // FONCTION_STRING_H

