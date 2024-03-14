#include "multiply.h"

void reg_mult(reg_matrix *string_r, reg_matrix *big_r, reg_matrix *result_r)
{
    result_r->columns = big_r->columns;
    result_r->rows = 1;
    for (int i = 0; i < string_r->columns; i++)
    {
        for (int j = 0; j < big_r->columns; j++)
        {
            result_r->matrix[i][j] = 0;
            for (int k = 0; k < string_r->columns; k++)
                result_r->matrix[i][j] += string_r->matrix[i][k] * big_r->matrix[k][j];
        }
    }
}

void sparse_mult(coord *string_c, sparse *big_s, coord *result_c)
{
    int cnt = 0;
    for (int i = 0; i < big_s->columns; i++)
    {
        int tmp = 0;
        int start = big_s->ja[i];
        int stop = big_s->ja[i + 1];
        int k;
        
        for (int j = start; j < stop; j++)
        {
            bool flag = false;
            k = 0;
            for (; k < string_c->len_a; k++)
            {
                if (big_s->ia[j] == string_c->ja[k])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                tmp += big_s->a[j] * string_c->a[k];
            }
        }
        if (tmp != 0)
        {
            result_c->a[cnt] = tmp;
            result_c->ia[cnt] = 0;
            result_c->ja[cnt] = i;
            cnt++;
        }
    }
    result_c->rows = 1;
    result_c->len_a = cnt;
}
