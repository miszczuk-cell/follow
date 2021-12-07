#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "testListHelpers.h"

int main(int argc, char const *argv[])
{
    s_tableHash * table = create_table(5);
    char * str1 = "Coucou1";
    char * str2 = "Coucou2";
    char * str3 = "Coucou3";
    char * str4 = "Coucou4";
    char * str5 = "Coucou5";
    char * str6 = "Coucou6";
    char * str7 = "Coucou7";
    char * str8 = "Coucou8";

    appendTableHash(str1,table);
    appendTableHash(str2,table);
    appendTableHash(str3,table);
    appendTableHash(str4,table);
    appendTableHash(str5,table);
    appendTableHash(str6,table);
    appendTableHash(str7,table);
    appendTableHash(str8,table);

    afficheTableHash(table);

    // printf("Nombre d'élément dans la liste 0 : %d\n",table->list[0].nb_elem_list_chaine);
    // removeTableHash(str5, table);
    // afficheTableHash(table);

    // printf("Nombre d'élément dans la liste 0 : %d\n",table->list[0].nb_elem_list_chaine);
    // appendTableHash(str5,table);
    // afficheTableHash(table);

    // printf("Nombre d'élément dans la liste 0 : %d\n",table->list[0].nb_elem_list_chaine);
    // appendTableHash(str5,table);
    // afficheTableHash(table);

    // printf("Nombre d'élément dans la liste 0 : %d\n",table->list[0].nb_elem_list_chaine);

    printf("Le nombre total d'élement %d",nbTotalElement(table));

    //printf("%s",(char*) list_get_data(table->list[2].newNode));
    //afficheTableHash(table);
    //appendTableHash(str5,table);
    //afficheTableHash(table);


    return 0;
}

