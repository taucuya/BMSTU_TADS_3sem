#include "tree_funcs.h"

tree_n *insert(tree_n *root, char name)
{
    if (root == NULL)
        return init_node(name);

    if (name < root->name)
    {
        root->left = insert(root->left, name);
    }
    if (name > root->name)
    {
        root->right = insert(root->right, name);
    }
    if (name == root->name)
    {
        root->sign = true;
    }
    return root;
}

int insert_letter(tree_n **root)
{
    char letter;
    printf("Введите букву, которую хотите вставить в дерево: ");
    __fpurge(stdin);
    if (scanf("%c", &letter) != 1)
        return ERR_READ_LETTER;
    if (!isalpha(letter))
    {
        return ERR_READ_LETTER;
    }
    *root = insert(*root, letter);
    return SUCCESS;
}

tree_n *search(tree_n *l, char name)
{
    // printf("%c\n", name);
    if (!l)
    {
        return NULL;
    }
    if (l->name == name)
    {
        return l;
    }
    if (name < l->name)
    {
        return (search(l->left, name));
    }
    else 
    {
        return (search(l->right, name));
    }
}

int search_letter(tree_n *root)
{
    char letter;
    printf("Введите букву, узел которой хотите вывести: ");
    __fpurge(stdin);
    if (scanf("%c", &letter) != 1)
        return ERR_READ_LETTER;
    if (!isalpha(letter))
    {
        return ERR_READ_LETTER;
    }
    // clock_t start2;
    // clock_t end2;
    // start2 = clock();
    tree_n *node = search(root, letter);
    // end2 = clock();
    // double result2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC * 1000000;
    // printf("%lf\n", result2);
    if (!node)
    {
        return ERR_NO_MATCH;
    }
    printf("   %c   \n", node->name);
    if (node->left && !node->right)
    {
        printf("  /\n");
        printf(" %c\n", node->left->name);
    }
    else if (!node->left && node->right)
    {
        printf("    \\  \n");
        printf("     %c \n", node->right->name);
    }
    else if (node->left && node->right)
    {
        printf("  / \\  \n");
        printf(" %c   %c \n", node->left->name, node->right->name);
    }
    return SUCCESS;
    
}

tree_n *min(tree_n *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

tree_n *del(tree_n *root, char name)
{
    if (root == NULL)
    {
        return root;
    }
    
    if (name < root->name) 
    {
        root->left = del(root->left, name);
    } 
    else if (name > root->name) 
    {
        root->right = del(root->right, name);
    } 
    else 
    {
        if (root->left == NULL) {
            tree_n *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tree_n *temp = root->left;
            free(root);
            return temp;
        }
        
        tree_n *temp = min(root->right);
        root->name = temp->name;
        root->sign = temp->sign;
        root->right = del(root->right, temp->name);
    }
    return root;
}

int delete_letter(tree_n **root)
{
    char letter;
    printf("Введите букву, которую хотите удалить из дерева: ");
    __fpurge(stdin);
    if (scanf("%c", &letter) != 1)
        return ERR_READ_LETTER;
    if (!isalpha(letter))
    {
        return ERR_READ_LETTER;
    }
    *root = del(*root, letter);
    return SUCCESS;
}

void inorder_del(tree_n *t, tree_n** root)
{
    if (t) 
    {
        inorder_del(t->left, root);
        inorder_del(t->right, root);
        if (t->sign)
        {
            *root = del(*root, t->name);
        }
    }
}

void freeTree(tree_n* root) 
{
    if (root == NULL)
    {
        return;
    }
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}