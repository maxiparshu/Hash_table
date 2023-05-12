//
// Created by user on 11.05.2023.
//

#include "Default_func.h"

int Correct(int* First) {
    char temp = 0;
    int scan = scanf_s("%d", First);
    if (scan != 1 || (First <= 0))
        return 0;
    while ((temp = getchar()) != '\n') {
        if ((temp > '9') || (temp < '0') && (temp != ',') && (temp != '.'))
            return 2;
        if (temp == ',' || (temp == '.')) {
            continue;
        }
        else
        if (temp == '0')
            continue;
        else
            return 2;
        continue;
    }
    return 1;
}
void Correct_input(int *value)
{
    while (Correct(value) != 1)
    {
        rewind(stdin);
        printf("Wrong input\n");
    }
}

void str_print(char* str)
{
    int i =0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
    putchar('\n');
}
int if_letter(char s)
{
    if ((s >= 'a' && s <= 'z') || ((s >= 'A') && (s <= 'Z')))
        return 1;
    return -1;
}
char* str_get()
{
    char* str;
    char temp;
    int i = 0;
    int Not_letter =0;
    do {
        Not_letter =0;
        str = (char *) malloc(1 * sizeof(char));
        while ((temp = getchar()) != '\n' && temp != EOF) {
            str = (char *) realloc(str, (i + 2) * sizeof(char));
            str[i] = temp;
            if(if_letter(temp) == -1)
            {
                Not_letter = 1;
            }
            i++;
        }
        if(Not_letter == 1)
        {
            printf("Wrong input\n");
            i =0 ;
            str = (char *) realloc(str, 1 * sizeof(char));

        }
        if(i == 0) {
            Not_letter = 1;
            str = (char *) realloc(str, 1 * sizeof(char));
        }
    }while(Not_letter != 0);
    if (str[0] < 'A' || str[0] > 'Z')
        str[0] -=32;
    str[i] = '\0';
    return str;
}





