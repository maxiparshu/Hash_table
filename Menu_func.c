//
// Created by user on 11.05.2023.
//

#include "Menu_func.h"
char* menu_command_get()
{
    char default_string[18][30]  = {"task 1","task 2","task 3","task 4","task 5",
                                    "1", "2", "3", "4", "5", "0", "exit",
                                    "info", "upload", "delete", "add","find", "hash"};
    char* str = (char *) malloc(1 * sizeof(char));
    int i = 0;
    char temp;
    do {
        printf("Input command(exit, info, task 1) or Task number\n");
        while ((temp = getchar()) != '\n' && temp != EOF) {
            str = (char *) realloc(str, (i + 2) * sizeof(char));
            str[i] = temp;
            i++;
        }
        str[i] = '\0';
        for (int j = 0; j < 18; j++) {
            if (strcmp(str,default_string[j]) == 0)
            {
                return str;
            }
        }
        printf("Wrong command\n");
        str = realloc(str,1);
        i =0;
    } while (1);

}
int str_comm_Task_num_get(char* command)
{
    if (strcmp(command, "exit") == 0)
        return 0;
    if (strcmp(command, "upload") == 0)
        return 1;
    if (strcmp(command, "add") == 0)
        return 2;
    if (strcmp(command, "delete") == 0)
        return 3;
    if (strcmp(command, "find") == 0)
        return 4;
    if (strcmp(command, "hash") == 0)
        return 5;
    else
    if (strcmp(command,"info") != 0)
        return (command[strlen(command) - 1] - '0');
    else
        return -1;
}