#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "testListHelpers.h"

int main(int argc, char const *argv[])
{

    // Création de la table avec 5 listes
    s_tableHash * table = create_table(5);

    // Initialisation des données
    char * str1 = "Coucou1";
    char * str2 = "Coucou2";
    char * str3 = "Coucou3";
    char * str4 = "Coucou4";
    char * str5 = "Coucou5";
    char * str6 = "Coucou6";
    char * str7 = "Coucou7";
    char * str8 = "Coucou8";

    // Insertion des données
    appendTableHash(str1,table);
    appendTableHash(str2,table);
    appendTableHash(str3,table);
    appendTableHash(str4,table);
    appendTableHash(str5,table);
    appendTableHash(str6,table);
    appendTableHash(str7,table);
    appendTableHash(str8,table);

    // On enlève la 2ème donnée ("Coucou2")
    removeTableHash(str2, table);

    // On affiche notre table avec la donnée supprimée 
    afficheTableHash(table);
  
    // On affiche le nombre total d'éléments dans notre table
    printf("Nombre total d'élement : %d \n", nbTotalElement(table));

    // On affiche le minimum et maximum d'entrées
    afficheStats(table);
    
    // On supprime les données présentes
    // table = destroyHash(table);

    // On affiche notre table (vide)
    // afficheTableHash(table);

    return 0;
}

