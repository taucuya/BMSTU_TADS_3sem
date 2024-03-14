#ifndef _STRUCTS_H_
#define _STRUCTS_H_

typedef struct tree
{
    bool sign;
    char name;
    struct tree *left;
    struct tree *right;
    int height;
} tree_n;

typedef struct table_node
{
    int amount;
    char letter;
    struct table_node *next;

} table_n;

typedef struct 
{
    int amount;
    char letter;
} table_s;

typedef struct
{
    table_n **array;
    table_s **array_simple;
    int num;
    int s_num;
} table_mas;

#endif