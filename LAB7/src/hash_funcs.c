#include "hash_funcs.h"



//////////CHAIN_HASH_TABLE//////


void insert_table_chain(table_mas *table, char letter, int len)
{
    int pos = hash_func(letter, len);
    if (!table->array[pos])
    {
        table->num++;
        table->array[pos] = init_node_table_chain(letter);
    }
    else if (letter != table->array[pos]->letter)
    {
        table_n *cur = table->array[pos];
        table_n *prev = cur;
        cur = cur->next;
        
        while (cur)
        {
            if (cur->letter == letter)
            {
                cur->amount++;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        table->num++;
        prev->next = init_node_table_chain(letter);
    }
    else if (letter == table->array[pos]->letter)
    {
        table->array[pos]->amount++;
    }
}

table_n *init_node_table_chain(char letter)
{
    table_n *node = malloc(sizeof(table_n));
    if (node)
    {
        node->letter = letter;
        node->amount = 1;
        node->next = NULL;
    }
    return node;
}

int hash_func(char letter, int len)
{    
    return letter % len;
}

void search_table_chain(table_mas *table, char letter, int len)
{
    int pos = hash_func(letter, len);
    if (!table->array[pos])
    {
        printf("Совпадений не найдено.\n");
        return;
    }
    if (table->array[pos]->letter != letter)
    {
        table_n *cur = table->array[pos];
        while(cur)
        {
            if (cur->letter == letter)
            {
                printf("%d\t%c\n", cur->amount, cur->letter);
                return;
            }
            cur = cur->next;
        }
    }
    if (table->array[pos]->letter != letter)
    {
        printf("Совпадений не найдено.\n");
    }
    else if (table->array[pos]->letter == letter)
        printf("%d\t%c\n", table->array[pos]->amount, table->array[pos]->letter);
}

int rebuild_chain(table_mas *table, char *tmp, int *len)
{
    int temp = table->num / 4 + 1;
    if (temp == *len)
        return SUCCESS;
    
    free_mas_chain(table, *len);
    *len = temp;
    table->array = malloc(*len * sizeof(table_n));
    if (!table->array)
    {
        return ERR_ALLOC;
    }
    table->num = 0;
    create_table_chain(table, tmp, *len);
    return SUCCESS;
}

void free_mas_chain(table_mas *table, int len)
{
    for (int i = 0; i < len; i++)
    {
        table_n *cur = table->array[i];
        while (cur)
        {
            table_n *temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(table->array);
}



////////REG_HASH_TABLE///////////


int hash(int i, int len)
{    
    return i % len;
}

int insert_table_reg(table_mas *table, char letter, int len)
{
    int pos = hash_func(letter, len);
    pos *= 4;
    if (!table->array_simple[pos])
    {
        table->s_num++;
        table->array_simple[pos] = init_node_table_simple(letter);
    }
    else if (letter != table->array_simple[pos]->letter)
    {
        pos++;
        while (table->array_simple[pos] && (pos < (len * 4)))
        {
            if (letter == table->array_simple[pos]->letter)
            {
                table->array_simple[pos]->amount++;
                return SUCCESS;
            }
            pos++;
        }
        if (pos == (len * 4))
        {
            free_mas_simple(table, pos);
            return ERR_OVERFLOW;
        }
        table->s_num++;
        table->array_simple[pos] = init_node_table_simple(letter);
    }
    else if (letter == table->array_simple[pos]->letter)
    {
        table->array_simple[pos]->amount++;
    }
    return SUCCESS;
}

table_s *init_node_table_simple(char letter)
{
    table_s *node = malloc(sizeof(table_s));
    if (node)
    {
        node->letter = letter;
        node->amount = 1;
    }
    return node;
}

void free_mas_simple(table_mas *table, int len)
{
    for (int i = 0; i < len; i++)
    {
        free(table->array_simple[i]);
    }
    free(table->array_simple);
    table->array_simple = NULL;
}

void search_table_simple(table_mas *table, char letter, int len)
{
    int pos = hash_func(letter, len);

    pos *= 4;
    if (!table->array_simple[pos])
    {
        printf("Совпадений не найдено.\n");
        return;
    }

    if (table->array_simple[pos]->letter != letter)
    {
        pos++;
        while (table->array_simple[pos] && (pos < (len * 10)))
        {
            if (letter == table->array_simple[pos]->letter)
            {
                printf("%d\t%c\n", table->array_simple[pos]->amount,
             table->array_simple[pos]->letter);
                return;
            }
            pos++;
        }
    }
    if (pos == (len * 4))
    {
        printf("Совпадений не найдено.\n");
    }
    else if (table->array_simple[pos]->letter == letter)
        printf("%d\t%c\n", table->array_simple[pos]->amount, table->array_simple[pos]->letter);
}

int rebuild_simple(table_mas *table, char *tmp, int *len)
{
    if (table->s_num == (*len * 4))
    {
        *len *= 4;
        return SUCCESS;
    }
    if (table->s_num != 0)
        free_mas_simple(table, *len);
    *len = table->num;
    table->array_simple = calloc(*len, sizeof(table_s));
    if (!table->array_simple)
    {
        return ERR_ALLOC;
    }
    table->s_num = 0;
    create_table_last(table, tmp, *len);
    return SUCCESS;
}

void insert_table(table_mas *table, char letter, int len)
{
    int pos = hash(table->s_num, len);
    // printf("pos = %d\n", pos);
    if (!table->array_simple[pos])
    {
        // printf("here\n");
        table->s_num++;
        table->array_simple[pos] = init_node_table_simple(letter);
    }
    else if (letter != table->array_simple[pos]->letter)
    {
        pos++;
        while (table->array_simple[pos] && (pos < len))
        {
            if (letter == table->array_simple[pos]->letter)
            {
                table->array_simple[pos]->amount++;
                return;
            }
            pos++;
        }
        table->s_num++;
        table->array_simple[pos] = init_node_table_simple(letter);
    }
    else if (letter == table->array_simple[pos]->letter)
    {
        table->array_simple[pos]->amount++;
    }
}