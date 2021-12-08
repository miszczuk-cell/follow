#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

s_tableHash * create_table(int size)
{
    s_tableHash * tableHash;

    tableHash = malloc(sizeof(s_tableHash));

    tableHash->size = size;

    tableHash->list = malloc(sizeof(s_list)* size);

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

s_tableHash * appendTableHash(char * str, s_tableHash * tableHash)
{
    int key = hash(str, tableHash->size);

    //On vérifie si la liste correspondant à la clef
    //contient déjà des elements
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

s_tableHash * appendTableHash1(char * str, s_tableHash * tableHash)
{
    int key = hash(str, tableHash->size);

    s_node * previousNode = tableHash->list->newNode;
    s_node * currentNode = previousNode->next;

    if(compare_data(previousNode,str) > 0)
    {
        
    }

    while(currentNode->next != NULL)
    {
        
    }
}

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

int nbTotalElement(s_tableHash * laTable)
{
    int nbTotalElement1 = 0;
    for(int i = 0;i<(laTable->size);i++)
    {
        nbTotalElement1 = nbTotalElement1 + laTable->list[i].nb_elem_list_chaine;
    }
    return nbTotalElement1;
}