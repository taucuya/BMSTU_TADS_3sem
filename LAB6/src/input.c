#include "input.h"

int create_tree(tree_n **root)
{
    printf("Ведите строку, чтобы сформировать из букв в ней дерево: ");
    char tmp[LEN];
    if (!fgets(tmp, LEN, stdin))
        return ERR_READ;
    tmp[strlen(tmp) - 1] = '\0';
    if (strlen(tmp) == 0)
    {
        return ERR_EMPTY_INPUT;
    }
    int i = 0;
    while (tmp[i] != '\0')
    {
        if (isalpha(tmp[i]))
        {
            *root = insert(*root, tmp[i]);
        }
        i++;
    }
    return SUCCESS;
}

void create_str()
{
    __fpurge(stdin);
    char tmp[LEN];
    fgets(tmp, LEN, stdin);
    tmp[strlen(tmp) - 1] = '\0';
    // clock_t start1;
    // clock_t end1;
    // start1 = clock();
    removeDuplicates(tmp);
    // end1 = clock();
    // double result1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC * 100000;
    // printf("Str %lf\n", result1);
}

tree_n *init_node(char sym)
{
    tree_n *node = malloc(sizeof(tree_n));

    if (node)
    {
        node->name = sym;
        node->left = NULL;
        node->right = NULL;
        node->sign = false;
        node->height = 1;
    }
    return node;
}