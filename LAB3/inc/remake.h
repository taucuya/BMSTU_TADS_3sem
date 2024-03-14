#ifndef _REMAKKE_H_
#define _REMAKE_H_

#include "gen.h"
#include "input.h"

void form(coord *big_c, sparse *big_s);
void make_reg_big(reg_matrix *big_r, coord *big_c);
void make_reg_string(reg_matrix *big_r, coord *big_c);
void make_coord(reg_matrix *result_r, coord *result_c);

#endif