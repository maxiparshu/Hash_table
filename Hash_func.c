//
// Created by user on 11.05.2023.
//

#include "Hash_func.h"
int capacity = 351;


char* id_generate()
{
    int data;
    char* id = malloc(9);
    srand(time(NULL));
    int i = 0;
    for (i = 0; i < 8; i++) {
        data = rand() % 10;
        data %= (i + 2);
        id[i] = data + '0';
    }
    id[i] = '\0';
    return id;
}
H_node* set_node(char* key, char* id)
{
    H_node* node = (H_node*) (malloc(1 * sizeof(H_node)));
    node->next = NULL;
    node->id = id;
    node->name = key;
    return node;
}
hash_table* Hash_table_create()
{
    hash_table *hash = (hash_table*)malloc(1 * sizeof(hash_table));
    hash->index = 0;
    hash->nodes = (H_node**)(malloc(capacity* sizeof(H_node*)));
    for (int i = 0; i < capacity; i++) {
        hash->nodes[i] = NULL;
    }
    return hash;
}
int hash_function(char* key)
{
    int i =0;
    int result = 0;
    while (key[i] != '\0')
    {
        result += key[i];
        i++;
    }
    return result % capacity;
}
void insert(hash_table* hash, char* name)
{
    time_t start = clock();
    int index = hash_function(name);
    H_node* new_node = set_node(name, id_generate());
    if (hash->nodes[index] == NULL)
    {
        hash->nodes[index] = new_node;

    }
    else
    {
        hash->nodes[index]->next = hash->nodes[index];
        hash->nodes[index] = new_node;
    }
    time_t stop = clock();
    printf("Time of insertion is %d\n", start - stop);

}
void del_node(hash_table* hash, char* name)
{
    int index = hash_function(name);
    H_node* prev = NULL;
    H_node* current = hash->nodes[index];
    time_t start = clock();
    while (current != NULL)
    {
        if(strcmp(name,current->name) == 0)
        {
            if(current == hash->nodes[index])
            {
                hash->nodes[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            time_t stop = clock();
            printf("Successful delete word\n");
            printf("Time of delete is %d\n", stop - start);
            return;
        }
        prev = current;
        current= current->next;
    }
    printf("No word in hash\n");
    return;
}
char* find_name (hash_table* hash, char* name)
{
    char* error_message = malloc(30);
    error_message = "No name in hash";
    int index = hash_function(name);
    H_node* current = hash->nodes[index];
    time_t start = clock();
    while(current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            time_t stop = clock();
            printf("Time of finding is %d\n", stop - start);
            printf("Id of this name: ");
            return current->id;
        }
        current = current->next;
    }
    return error_message;
}
void hash_info(hash_table* hash)
{
    H_node* current;
    printf("Hash: \n");
    for (int i = 0; i <capacity; i++) {
        if (hash->nodes[i] != NULL)
        {
            current = hash->nodes[i];
            while (current != NULL) {
                str_print(current->name);
                current = current->next;
            }
        }
    }
}