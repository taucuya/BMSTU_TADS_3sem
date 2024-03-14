#include "input.h"

////////////////////////////
////////////TREE////////////
////////////////////////////

int create_tree(tree_n **root, char *tmp)
{
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

int max(int a, int b) {

    return (a > b) ? a : b;
}

int height(tree_n *node)
{
	return node ? node->height : 0;
}

tree_n *r_rotate(tree_n *root)
{
    tree_n *n_root = root->left;
    tree_n *tmp = n_root->right;

    n_root->right = root;
    root->left = tmp;

    root->height = max(height(root->left), height(root->right)) + 1;
    n_root->height = max(height(n_root->left), height(n_root->right)) + 1;

    return n_root;
}

tree_n *l_rotate(tree_n *root)
{
    tree_n *n_root = root->right;
    tree_n *tmp = n_root->left;

    n_root->left = root;
    root->right = tmp;

    root->height = max(height(root->left), height(root->right)) + 1;
    n_root->height = max(height(n_root->left), height(n_root->right)) + 1;

    return n_root;
}

int bfactor(tree_n *node)
{
    if (node == NULL)
    {
        return SUCCESS;
    }
    int a = height(node->left) - height(node->right);
	return a;
}


////////////////////////////
///////////TABLE////////////
////////////////////////////

void create_table_chain(table_mas *chains, char *tmp, int len)
{
    int i = 0;
    while (tmp[i] != '\0')
    {
        if (isalpha(tmp[i]))
        {
            insert_table_chain(chains, tmp[i], len);
        }
        i++;
    }
}

void create_table_simple(table_mas *chains, char *tmp, int len)
{
    int i = 0;
    while (tmp[i] != '\0')
    {
        if (isalpha(tmp[i]))
        {
            int err = insert_table_reg(chains, tmp[i], len);
            if (err)
            {
                printf("\tПри попытке заполнить хэш-таблицу с открытой адресацией\n\
        произошло переполнение. Таким образом пользование этой\n\
        таблицей невозможно. Для дальнейшего использования ее нужно\n\
        реструктурировать.\n\n");
                chains->s_num = 0;
                return;
            }
        }
        i++;
    }
}

void create_table_last(table_mas *chains, char *tmp, int len)
{
    int i = 0;
    while (tmp[i] != '\0')
    {
        if (isalpha(tmp[i]))
        {
            // printf("here\n");
            // printf("%d\n", chains->s_num);
            insert_table(chains, tmp[i], len);
        }
        i++;
    }
    // printf("%d\n", chains->s_num);
}