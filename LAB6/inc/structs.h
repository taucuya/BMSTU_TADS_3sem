#ifndef _STRUCTS_H_
#define _STRUCTS_H_

typedef struct node
{
    bool sign;
    char name;
    struct node *left;
    struct node *right;
    int height;
} tree_n;


#endif