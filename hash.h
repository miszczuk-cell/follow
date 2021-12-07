#include "list.h"

#ifndef TEST
#define TEST
struct list {
	s_node * newNode;
	int nb_elem_list_chaine;
};

typedef struct list s_list;

struct tableHash {
	int size;
	s_list * list;
};

typedef struct tableHash s_tableHash;

// Création de la table
s_tableHash * create_table(int size);

// Destruction de la table
s_tableHash * destroyHash(s_tableHash * tableHash);

// Ajout d'un mot dans la table (si le mot concerné ne s'y trouve pas)
s_tableHash * appendTableHash(char * str, s_tableHash * tableHash);

// Ajout d'un mot dans la table (si le mot concerné ne s'y trouve pas)
s_tableHash * removeTableHash(char * str, s_tableHash * tableHash);

int hash(char * str, int nbEntrees);

int nbTotalElement(s_tableHash * laTable);

void afficheTableHash(s_tableHash * tableHash);

#endif