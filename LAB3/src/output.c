#include "output.h"

void output_c(coord *big_c)
{
    printf("\n");
    printf("Ненулевые значения:\n");
    if (big_c->len_a == 0)
        printf("Все нули.\n");
    for (int i = 0; i < big_c->len_a; i++)
    {
        printf("%d ", big_c->a[i]);
    }
    printf("\nИх строки:\n");
    if (big_c->len_a == 0)
        printf("Все нули.\n");
    for (int i = 0; i < big_c->len_a; i++)
    {
        printf("%d ", big_c->ia[i]);
    }
    printf("\nИх столбцы:\n");
    if (big_c->len_a == 0)
        printf("Все нули.\n");
    for (int i = 0; i < big_c->len_a; i++)
    {
        printf("%d ", big_c->ja[i]);
    }
    printf("\n");
}

void output_r_big(reg_matrix big_r)
{
    for (int i = 0; i < big_r.rows; i++)
    {
        for (int j = 0; j < big_r.columns; j++)
        {
            printf("%d ", big_r.matrix[i][j]);
        }
        printf("\n");
    }
}

void output_r_string(reg_matrix big_r)
{
    for (int j = 0; j < big_r.columns; j++)
    {
        printf("%d ", big_r.matrix[0][j]);
    }
    printf("\n");
}

void output_s(sparse big_s)
{
    printf("\n");
    printf("Ненулевые значения:\n");
    for (int i = 0; i < big_s.len_a; i++)
    {
        printf("%d ", big_s.a[i]);
    }
    printf("\nИх строки:\n");
    for (int i = 0; i < big_s.len_a; i++)
    {
        printf("%d ", big_s.ia[i]);
    }
    printf("\nТретий массив:\n");
    for (int i = 0; i < (big_s.columns + 1); i++)
    {
        printf("%d ", big_s.ja[i]);
    }
}