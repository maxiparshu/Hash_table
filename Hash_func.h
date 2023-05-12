//
// Created by user on 11.05.2023.
//

#ifndef LB_F_HASH_FUNC_H
#define LB_F_HASH_FUNC_H

#include "Default_func.h"
typedef struct Hash_Set
{
    char* name; // key (odno iz imen// )
    char* id; // value ()
    struct Hash_Set* next; // for chain
}H_node;

typedef struct Hash
{
    H_node** nodes;
    int index;
}hash_table;
H_node* set_node(char* key, char* id);
hash_table* Hash_table_create();
int hash_function(char* key);
void insert(hash_table* hash, char* name);
void del_node(hash_table* hash, char* name);
char* find_name (hash_table* hash, char* name);
void hash_info(hash_table* hash);
#endif //LB_F_HASH_FUNC_H
