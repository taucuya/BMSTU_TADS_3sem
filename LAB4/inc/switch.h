#ifndef _SWITCH_H_
#define _SWITCH_H_

#include "gen.h"
#include "add.h"
#include "delete.h"
#include "show.h"


int action(int num, mas *words_m, int *amount, list **adress, list **head, int *cnt, double *result1, double *result2, double *result3, double *result4, double *result5, double *result6);
void show_message(int err_num);

#endif