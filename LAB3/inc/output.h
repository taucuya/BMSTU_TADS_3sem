#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include "gen.h"
#include "input.h"

void output_c(coord *big_c);
void output_r_big(reg_matrix big_r);
void output_r_string(reg_matrix big_r);
void output_s(sparse big_s);

#endif