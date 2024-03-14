#ifndef _SHOW_H_
#define _SHOW_H_

#include "gen.h"

void show_mas(mas *words_m);
void show_list(list **head, int amount);
void show_adresses(list **adress, int amount);
void show_mas_reversed(mas *words_m);
void show_list_reversed(list **head, int amount);
void reverse_print(char *word);
void free_list(list *head);

#endif