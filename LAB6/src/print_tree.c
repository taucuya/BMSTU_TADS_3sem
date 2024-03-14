#include "print_tree.h"

void node_to_dot(FILE *fp, tree_n *node)
{
    if (node == NULL)
        return;
    if (node->left) 
    {
        if (node->sign)
            fprintf(fp, "  \"%c\"[color=\"red\"];\n", node->name);
        fprintf(fp, "  \"%c\" -> \"%c\";\n", node->name, node->left->name);
        node_to_dot(fp, node->left);
    }
    if (node->right)
    {
        if (node->sign)
            fprintf(fp, "  \"%c\"[color=\"red\"];\n", node->name);
        fprintf(fp, "  \"%c\" -> \"%c\";\n", node->name, node->right->name);
        node_to_dot(fp, node->right);
    }
    if (node && !node->right && !node->left)
    {
        if (node->sign)
            fprintf(fp, "  \"%c\"[color=\"red\"];\n", node->name);
        if (!node->sign)
            fprintf(fp, "  \"%c\";\n", node->name);
    }
}

void tree_to_dot(tree_n *root)
{
    FILE *file = fopen("tree.dot", "w");
    fprintf(file, "digraph G {\n");
    node_to_dot(file, root);
    fprintf(file, "}\n");
    fclose(file);

    system("dot -Tpng tree.dot -o tree.png");
}

void inorder_print(tree_n *root)
{
    if (root) 
    {
        inorder_print(root->left);
        inorder_print(root->right);
        printf("%c ", root->name);
    }
}