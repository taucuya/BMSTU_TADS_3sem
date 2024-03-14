#ifndef _INPUT_H_
#define _INPUT_H_

#include "gen.h"

#define FILE_NAME_LEN 20
#define MAX_LEN 1000

typedef struct 
{
    int a[MAX_LEN * MAX_LEN];
    int ia[MAX_LEN * MAX_LEN];
    int ja[MAX_LEN * MAX_LEN];
    int len_a;
    int rows;
    int columns;
} coord;

typedef struct
{
    int matrix[MAX_LEN][MAX_LEN];
    int rows;
    int columns;
} reg_matrix;

typedef struct 
{
    int a[MAX_LEN * MAX_LEN];
    int ia[MAX_LEN * MAX_LEN];
    int ja[MAX_LEN * MAX_LEN];
    int len_a;
    int rows;
    int columns;
} sparse;



int input(coord *big_c, coord *string_c, sparse *big_s);
int hand_input(coord *big_c, coord *string_c, sparse *big_s);
int read_file(char *file_name, coord *big_c, coord *string_c, sparse *big_s);

#endif