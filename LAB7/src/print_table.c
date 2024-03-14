#include "print_table.h"

void print_table_chain(table_mas *table, int len)
{
    if (table->num == 0)
    {
        printf("Хэш-таблица пустая.\n");
        return;
    }
    for (int i = 0; i < len; i++)
    {
        table_n *cur = table->array[i];
        while (cur)
        {
            if (cur)
                printf("%d\t%c\n", cur->amount, cur->letter);
            cur = cur->next;
        }
    }
}

void print_table_simple(table_mas *table, int len)
{
    if (table->s_num == 0)
    {
        printf("Хэш-таблица пустая.\n");
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (table->array_simple[i])
        {
            printf("%d\t%c\n", table->array_simple[i]->amount,
             table->array_simple[i]->letter);
        }
    }
}