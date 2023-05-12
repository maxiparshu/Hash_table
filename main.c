
#include "Hash_func.h"
#include "Menu_func.h"
#include "LAB_specific.h"


///////
int string_error(char* str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (if_letter(str[i]) != 1)
        {
            return 1;
        }
    }
    return 0;
}
void read_N_word_from_file(hash_table* hash, int N, FILE* fp) {
    char* string;
    int count = 0;
    char** str = malloc(N* sizeof(char*));
    while (count != N)
    {
        if (feof(fp))
        {
            printf("Not enough word");
            return;
        }
        str[count] = malloc(20);
        fscanf_s(fp,"%s", str[count]);
        if (string_error(str[count]) == 1)
        {
            printf("Error in string ");
            str_print(str[count]);
            exit(254);
        }
        count++;
    }
    for (int i = 0; i < N; i++) {
        insert(hash, str[i]);
    }
    printf("Successful been read %d words\n", N);

}
void Task_1(hash_table* hash, FILE* fp)
{
    int N;
    printf("Input N word to read\n");
    Correct_input(&N);
    read_N_word_from_file(hash,N,fp);
}
void file_add(FILE* fp, char* name)
{
    char* str = malloc(20);
    fgets(str,20,fp);
    fpos_t current = ftell(fp);
    FILE *temp;
    fopen_s(&temp,"D:\\Lab2sem\\Files\\temp.txt","w+");
    fseek(fp,0,SEEK_SET);

    while (ftell(fp)!= current)
    {
        fgets(str,20,fp);
        fputs(str, temp);
    }
    fprintf(temp, "%s\n",name);

    while (!feof(fp))
    {
        fgets(str,20,fp);
        fputs(str, temp);
    }
    fseek(temp,0,SEEK_SET);
    fclose(fp);
    fopen_s(&fp,"D:\\Lab2sem\\Files\\Database.txt","w+");
    while (!feof(temp))
    {
        fgets(str,20,temp);
        fputs(str, fp);
    }
    fclose(temp);
    remove("D:\\Lab2sem\\Files\\temp.txt");

}
void Task_2(hash_table* hash, FILE* fp)
{
    printf("Input name\n");
    char* name = str_get();
    insert(hash,name);
    file_add(fp,name);
}
void Task_3(hash_table* hash, FILE* fp)
{
    printf("Input name\n");
    char* name = str_get();
    del_node(hash, name);
}
void Task_4(hash_table* hash, FILE* fp)
{
    printf("Input name\n");
    char* name = str_get();
    str_print(find_name(hash,name));
}
void Task_5(hash_table* hash, FILE* fp)
{
    hash_info(hash);
}
void exit_lab(hash_table* hash, FILE* fp)
{
    fclose(fp);
    free(hash);
    exit(228);
}

void Lab()
{
    FILE* fp;
    fopen_s(&fp,"D:\\Lab2sem\\Files\\Database.txt","r+");
    hash_table* hash = Hash_table_create();
    void(*Menu[6])(hash_table* hash, FILE* fp) = {exit_lab, Task_1, Task_2, Task_3, Task_4, Task_5};
    tasks_info();
    do {
        char* comm = menu_command_get();
        int Task = str_comm_Task_num_get(comm);
        if (Task == -1)
            tasks_info();
        else
            Menu[Task](hash, fp);
    } while (1);
}


int main() {
    Lab();
    return 0;
}
