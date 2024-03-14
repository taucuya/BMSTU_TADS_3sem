#ifndef _TREE_FUNCS_H_
#define _TREE_FUNCS_H_

#include "gen.h"
#include "input.h"

tree_n *insert(tree_n *root, char name);
int insert_letter(tree_n **root);
tree_n *search(tree_n *l, char name);
tree_n *del(tree_n *root, char name);
int delete_letter(tree_n **root);
int search_letter(tree_n *root);
void inorder_del(tree_n *t, tree_n** root);
void removeDuplicates(char *str);

#endif