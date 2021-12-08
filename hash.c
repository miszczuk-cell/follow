#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

s_tableHash * create_table(int size)
{
    s_tableHash * tableHash;

    tableHash = malloc(sizeof(s_tableHash));

    tableHash->size = size;

    tableHash->list = malloc(sizeof(s_list)* size);

    tableHash->list->newNode = malloc(sizeof(s_node));
    tableHash->list->nb_elem_list_chaine = 0;

    return tableHash;
}

s_tableHash * destroyHash(s_tableHash * tableHash)
{
    for (int i = 0 ; i < tableHash->size ; i++)
    {
        if(tableHash->list[i].nb_elem_list_chaine != 0)
        {
            list_destroy(tableHash->list[i].newNode);
        }    
    }
    free(tableHash);
}

// Ajout d'un mot
s_tableHash * appendTableHash(char * str, s_tableHash * tableHash)
{
    int key = hash(str, tableHash->size);

    if (tableHash->list[key].nb_elem_list_chaine == 0)
    {
        tableHash->list[key].newNode = list_create();
        list_set_data(tableHash->list[key].newNode, str);
        tableHash->list[key].nb_elem_list_chaine++;
    }
    else
    {
        list_orderedAppend(tableHash->list[key].newNode, compare_data, str);
        tableHash->list[key].nb_elem_list_chaine++;
    }

}

// Retirer un mot
s_tableHash * removeTableHash(char * str, s_tableHash * tableHash)
{
    if(str && tableHash)
    {
        int key = hash(str, tableHash->size);
        if(tableHash->list[key].newNode->next != NULL)
        {
            s_node * leNode = list_remove(tableHash->list[key].newNode, str);
            tableHash->list[key].newNode = leNode;
        }
        else
        {
            tableHash->list[key].newNode = NULL;
        }
        tableHash->list[key].nb_elem_list_chaine--;
    }
}



void afficheTableHash(s_tableHash * tableHash)
{
    if(tableHash == NULL)
    {
        printf("La table n'existe pas !\n");
    }

    else
    {
        for(int i = 0; i < tableHash->size; i++)
        {
            printf("Liste n°%d : [",i);
            if(tableHash->list[i].newNode != NULL)
            {
                s_node * currentNode = tableHash->list[i].newNode;
                printf("%s ", (char *) list_get_data(currentNode));
                while(currentNode->next != NULL)
                {
                    currentNode = currentNode->next;
                    printf("%s", (char *) list_get_data(currentNode));
                }
            }
        printf("]\n");
        }

    }
    

}

int hash(char * str, int nbEntrees)
{
    int cle = 0;
    char car = ' ';
    int i = 0;
    while(car != '\0')
    {
        cle = cle * 2;
        car = str[i];
        cle = cle + str[i];
        i++;
    }

    cle = cle % nbEntrees;
    return cle;

}


// Afficher le nombre total d'élement
int nbTotalElement(s_tableHash * laTable)
{
    int nbTotalElement1 = 0;
    for(int i = 0;i<(laTable->size);i++)
    {
        nbTotalElement1 = nbTotalElement1 + laTable->list[i].nb_elem_list_chaine;
    }
    return nbTotalElement1;
}

double ecartType(s_tableHash * laTable)
{
    double moyenne = 0;
    double variance = 0;
    double ecartType;

    for(int i = 0;i<(laTable->size);i++)
    {
        moyenne = moyenne + laTable->list[i].nb_elem_list_chaine;
    }
    moyenne = moyenne / laTable->size;
    printf("La moyenne est : %f\n",moyenne);

    for(int i = 0;i<(laTable->size);i++)
    {
        variance = variance + pow(laTable->list[i].nb_elem_list_chaine - moyenne,2);
        printf("(%d - %f)² = %f\n",laTable->list[i].nb_elem_list_chaine,moyenne,pow(laTable->list[i].nb_elem_list_chaine - moyenne,2));
    }

    variance = variance / laTable->size;
    printf("Variance : %f\n",variance);
    ecartType = sqrt(variance);

    return ecartType;
}

// Afficher le max et min 
void afficheStats(s_tableHash * table)
{
    int max = table->list[0].nb_elem_list_chaine;
    int min = table->list[0].nb_elem_list_chaine;

    for(int i = 0; i < table->size; i++)
    {
        if(max < table->list[i].nb_elem_list_chaine)
        {
            max = table->list[i].nb_elem_list_chaine;
        }

        if(min > table->list[i].nb_elem_list_chaine)
        {
            min = table->list[i].nb_elem_list_chaine;
        }
    }

    printf("Nombre maximum d'entrées : %d\n", max);
    printf("Nombre minimum d'entrées : %d\n", min);
}