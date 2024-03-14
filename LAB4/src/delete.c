#include "delete.h"

int delete_mas(mas *words_m)
{
    if (words_m->num == -1)
    {
        return ERR_NO_EL_TO_DELETE;
    }
    words_m->num -= 1;
    return SUCCESS;
}

int delete_list(list **head, int *amount, list **dl)
{
    if (!(*amount))  
    {
        return ERR_NO_EL_TO_DELETE;
    }
    list *out;
    *dl = *head;
    out = (*head)->next;
    free(*head);
    *head = out;
    (*amount)--;
    printf("Удаление прошло успешно!");
    return SUCCESS;
}