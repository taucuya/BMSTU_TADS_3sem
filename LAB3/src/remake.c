#include "remake.h"

void form(coord *big_c, sparse *big_s)
{
    for (int i = 0; i < big_s->len_a; i++)
    {
        big_s->ja[big_c->ja[i] + 1] += 1;
    }
    for (int i = 2; i < big_s->columns + 1; i++)
    {
        big_s->ja[i] += big_s->ja[i - 1];
    }
}

void make_reg_big(reg_matrix *big_r, coord *big_c)
{
    for (int i = 0; i < big_c->len_a; i++)
    {
        big_r->matrix[big_c->ia[i]][big_c->ja[i]] = big_c->a[i];
    }
    big_r->rows = big_c->rows;
    big_r->columns = big_c->columns;
}

void make_reg_string(reg_matrix *string_r, coord *string_c)
{
    for (int j = 0; j < string_c->len_a; j++)
    {
        string_r->matrix[0][string_c->ja[j]] = string_c->a[j];
    }
    string_r->rows = 1;
    string_r->columns = string_c->columns;
}

void make_coord(reg_matrix *result_r, coord *result_c)
{
    int cnt = 0;
    for (int i = 0; i < result_r->rows; i++)
    {
        for (int j = 0; j < result_r->columns; j++)
        {
            if (result_r->matrix[i][j] != 0)
            {
                result_c->a[cnt] = result_r->matrix[i][j];
                result_c->ia[cnt] = i;
                result_c->ja[cnt] = j;
                cnt++;
            }
        }
    }
    result_c->len_a = cnt;
}