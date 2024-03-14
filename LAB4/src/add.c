#include "add.h"

int add_mas(mas *words_m)
{
    if (words_m->num >= (MAX_LEN - 1))
    {
        return ERR_OVERFLOW;
    }
    char word[WORD_LEN];
    printf("Введите слово чтобы добавить его в стек: ");
    if (scanf("%s", word) != 1)
    {
        return ERR_WORD_INPUT;
    }
    if (strlen(word) == 0)
    {
        return ERR_EMPTY_INPUT;
    }
    words_m->num += 1;
    strcpy(words_m->words[words_m->num], word);

    return SUCCESS;
}

int add_list(list **head, int *amount)
{
    char word[WORD_LEN];
    if (*amount >= MAX_LEN)
    {
        return ERR_OVERFLOW;
    }
    printf("Введите слово, которое хотите добавить в стек: ");
    if (scanf("%s", word) != 1)
    {
        return ERR_WORD_INPUT;
    }
    if (strlen(word) == 0)
    {
        return ERR_EMPTY_INPUT;
    }
    list *tmp;
    tmp = malloc(sizeof(list));
    if (!tmp)
    {
        return ERR_ALLOC;
    }
    tmp->next = *head;
    strcpy(tmp->word, word);
    *head = tmp;
    (*amount)++;
    return SUCCESS;
}