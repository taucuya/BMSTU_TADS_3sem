#ifndef _INPUT_H_
#define _INPUT_H_

#include "gen.h"
#include "tree_funcs.h"

#define LEN 100

int create_tree(tree_n **root);
tree_n *init_node(char sym);
int max(int a, int b);
void create_str();

#endif