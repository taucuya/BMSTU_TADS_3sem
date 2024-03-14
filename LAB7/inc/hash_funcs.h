#ifndef _HASH_FUNCS_H_
#define _HASH_FUNCS_H_

#include "gen.h"
#include "input.h"
#include "print_table.h"

void insert_table_chain(table_mas *table, char letter, int len);
void search_table_chain(table_mas *chains, char letter, int len);
table_n *init_node_table_chain(char letter);
int hash_func(char letter, int len);
int rebuild_chain(table_mas *chains, char *tmp, int *len);
void free_mas_chain(table_mas *table, int len);

int insert_table_reg(table_mas *chains, char letter, int len);
table_s *init_node_table_simple(char letter);
void free_mas_simple(table_mas *table, int len);
void search_table_simple(table_mas *table, char letter, int len);
int rebuild_simple(table_mas *table, char *tmp, int *len);
void insert_table(table_mas *table, char letter, int len);

#endif