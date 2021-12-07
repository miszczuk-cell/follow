// Fichier de test unitaire module 1
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "testListHelpers.h"

int main()
{
        // Données
	int val1 = 1;
	int val2 = 2;
	int val3 = 3;
	int val4 = 4;
	int val5 = 5;
	int val6 = 6;

	void * pV1 = &val1;
	void * pV2 = &val2;
	void * pV3 = &val3;
	void * pV4 = &val4;
	void * pV5 = &val5;
	void * pV6 = &val6;

        // Création d'une liste
        s_node * tList = list_create();

    /* ------------ Tests : ------------ */

	list_set_data(tList,pV2);

    // ***** Insertion et Append *****
    tList = list_insert(tList,pV1);
    tList = list_append(tList,pV3);
	// Fct d'affichage
	printf("** list_insert_append [2,1,3] ** : %s\n", list_to_string(tList,node_to_string));

    // ***** orderedAppend *****
	tList = list_orderedAppend(tList,&compare_data,pV4);
	tList = list_orderedAppend(tList,&compare_data,pV1);
	printf("** list_orderedAppend [val 4,1] ** : %s\n", list_to_string(tList,node_to_string));

	// ***** Remove *****
    tList = list_remove(tList,pV2);
	printf("** list_remove [val 2] ** : %s\n", list_to_string(tList,node_to_string));

	// ***** OrderedAppend *****
	tList = list_orderedAppend(tList,compare_data,pV2);
	printf("** list_orderedAppend [val 2]** : %s\n", list_to_string(tList,node_to_string));

    // ***** HeadRemove *****
    tList = list_headRemove(tList);
	printf("** list_headRemove [val 1] ** : %s\n", list_to_string(tList,node_to_string));

	tList = list_append(tList,pV6);
	tList = list_orderedAppend(tList,compare_data,pV1);
	tList = list_orderedAppend(tList,compare_data,pV5);
	printf("** list_append_orderedAppend [val 6,1,5] ** : %s\n", list_to_string(tList,node_to_string));

        // ***** Destroy *****
        tList = list_destroy(tList);
	// Fct d'affichage
	printf("** list_destroy ** : %s\n", list_to_string(tList,node_to_string));

        /* ------------ Fin des tests ------------ */

}

