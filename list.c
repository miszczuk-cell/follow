#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Création d'une liste vide
s_node * list_create(void)
{
	s_node * node = malloc(sizeof(s_node));
	node->data = NULL;
	node->next = NULL;
	return node;
}

// Permet de lire la donnée d'un noeud
void * list_get_data(s_node * node)
{
	// Retourne la donnée d'un noeud
	if(node)
	{
		return node->data;
	}
	else
	{
		return NULL;
	}
}

// Permet d'écrire la donnée d'un noeud
void list_set_data(s_node * node, void * data)
{
	// Ecris la donnée dans un noeud
	if(node)
	{
		node->data = data;
	}
}

// Création et insertion d'un noeud en tête de liste et retourne la tête de liste
s_node * list_insert(s_node * head, void * data)
{
	//
	s_node * newNode = (s_node*) malloc(sizeof(s_node));

	// Appel de la fonction pour écrire la donnée d'un noeud
	list_set_data(newNode, data);

	//
	newNode->next = head;

	//
	return newNode;
}

// Création et ajout d'un noeud en queue de liste et retourne la tête de liste
s_node * list_append(s_node * head,void * data)
{

	s_node * newNode = (s_node*) malloc(sizeof(s_node));
	s_node * currentNode = head;

	// Appel de la fonction pour écrire la donnée d'un noeud
	list_set_data(newNode, data);

	newNode->next = NULL;

	if(head == NULL)
	{
		head = newNode;
		return newNode;
	}

	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}

	currentNode->next = newNode;

	// Retourne la tête de liste
	return head;
}

int compare_data(s_node * node , void * data)
{

	const char *str1 = (char *) list_get_data(node);
	const char *str2 = (char *) data;

	return strcmp(str1,str2);
}

// Ajout d'un noeud dans une liste ordonnée et selon le résultat de compare, si la donnée existe déjà, pas d'ajout
s_node * list_orderedAppend(s_node * head,
                            int (*compare)(s_node *, void *),
                            void *param)
{

	if (head == NULL)
	{
		printf("C'est pas bon :( ");
	}
	else
	{
		s_node * currentNode = head;
		s_node * previousNode = currentNode;
		while((*compare)(currentNode,param) < 0)
		{
			if(!currentNode->next)
			{
				break;
			}
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		if((*compare)(currentNode,param) == 0)
		{
			return head;
		}

		if(!currentNode->next && compare_data(currentNode,param) < 0)
		{
			head = list_append(head, param);
		}
		else
		{
			if(currentNode == previousNode)
			{
				head = list_insert(head,param);
			}
			else
			{
				s_node * newList = list_create();
				list_set_data(newList, param);
				newList->next = currentNode;
				previousNode->next = newList;
			}
		}
	}
	return head;
}

// Suppression de la première instance d'une donnée dans la liste et retourne la tête de liste
s_node * list_remove(s_node * head, void * data)
{
	
    if(head)
    {
		s_node * currentNode = head;

		if(list_get_data(currentNode) == data)
		{
			head = head->next;
			free(currentNode);
			return head;
		}

		while(currentNode->next->data != data)
		{
			if(currentNode->next == NULL)
			{
					return head;
			}
		currentNode = currentNode->next;
		}

		currentNode->next = currentNode->next->next;

    }

    return head;
}

// Suppression de la tête de liste et retourne la nouvelle tête de liste
s_node * list_headRemove(s_node * head)
{
	if(head)
	{
		s_node * currentHead = head;
		head = currentHead->next;

		// Libère la mémoire
		free(currentHead);
	}
	// Retourne la nouvelle tête de liste
	return head;
}

// Destruction de la liste et la libération des données n'est pas prise en charge
s_node * list_destroy(s_node * head)
{
	while(head)
	{
		head = list_headRemove(head);
	}
	return head;
}

void afficheListe(s_node * head)
{
    if(head == NULL)
    {
        printf("La liste est vide");
    }
    else
    {
        int numNode = 1;
        printf("La liste n'est pas vide : \n");
        s_node * currentNode = (s_node*) malloc(sizeof(s_node));
        currentNode = head;
        printf("Données sur le noeud n°1: %d\n",*(int*)currentNode->data);
        while(currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            numNode++;
            printf("Données sur le noeud n°%d: %d\n",numNode,*(int*)currentNode->data);
        }
    }
}
