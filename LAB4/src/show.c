#include "show.h"

void show_mas(mas *words_m)
{
    if (words_m->num == -1)
    {
        printf("\nСтек пустой.\n");
    }
    else
    {
        printf("\nСтек на массиве:\n");
        for (int i = words_m->num; i >= 0; i--)
        {
            printf("%s\n", words_m->words[i]);
        }
    }
}

void show_list(list **head, int amount)
{
    if (amount == 0)
    {
        printf("\nСтек пустой\n");
    }
    else
    {
        int cnt = 0;
        list *cur = *head;
        printf("\nСтек на одномерном списке:\n");
        while (cur->next != NULL) 
        {
            printf("%20s - %20p\n", cur->word, (void *) cur);
            cur = cur->next;
            cnt++;
        }
    }
}

void show_adresses(list **adress, int amount)
{
    printf("\nМассив адресов удаленных элементов стека:\n");
    for (int i = 0; i < amount; i++)
    {
        printf("%p\n", (void *) adress[i]);
    }
}

void show_mas_reversed(mas *words_m)
{
    if (words_m->num == -1)
    {
        printf("\nСтек пустой.\n");
    }
    else
    {
        printf("\nСтек на массиве:\n");
        for (int i = words_m->num; i >= 0; i--)
        {
            reverse_print(words_m->words[i]);
            printf("\n");
        }
    }
}

void show_list_reversed(list **head, int amount)
{
    if (amount == 0)
    {
        printf("\nСтек пустой\n");
    }
    else
    {
        int cnt = 0;
        list *cur = malloc(sizeof(list));
        cur = *head;
        printf("\nСтек на одномерном списке:\n");
        while (cur->next != NULL) 
        {
            reverse_print(cur->word);
            printf("\t\t- %15p\n", (void *) cur);
            cur = cur->next;
            cnt++;
        }
    }
}

void reverse_print(char *word)
{
    for (int i = strlen(word); i >= 0; i--)
    {
        printf("%c", word[i]);
    }
}

void free_list(list *head)
{
    list *pNode = head, *pNext;

    while (NULL != pNode)
    {
        pNext = pNode->next;
        free(pNode);
        pNode = pNext;
    }
}