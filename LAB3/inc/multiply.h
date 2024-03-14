#ifndef _MULTIPLY_H_
#define _MULTIPLY_H_

#include "gen.h"
#include "input.h"

void reg_mult(reg_matrix *string_r, reg_matrix *big_r, reg_matrix *result_r);
void sparse_mult(coord * string_c, sparse *big_s, coord *result_c);

#endif
