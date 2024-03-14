#ifndef _INPUT_H_
#define _INPUT_H_

#include "gen.h"
#include "tree_funcs.h"
#include "hash_funcs.h"

#define LEN 100000


///TREE///
int create_tree(tree_n **root, char *tmp);
tree_n *init_node(char sym);
int max(int a, int b);
int height(tree_n *node);
tree_n *r_rotate(tree_n *root);
tree_n *l_rotate(tree_n *root);
int bfactor(tree_n *node);


///TABLE///
void create_table_chain(table_mas *chains, char *tmp, int len);
void create_table_simple(table_mas *chains, char *tmp, int len);
void create_table_last(table_mas *chains, char *tmp, int len);

#endif