#include "info.h"
#include "input.h"
#include "remake.h"
#include "output.h"
#include "multiply.h"

coord big_c;
coord string_c;
coord result_c1;
coord result_c2;

reg_matrix big_r;
reg_matrix string_r;
reg_matrix result_r;

sparse big_s;

void show_message(int number)
{
    printf("Ошибка!\n");
    switch (number)
    {
        case ERR_EL_INP:
            printf("Неправильно введен ненулевой элемент.\n");
            break;
        case ERR_ROW_INP:
            printf("Неправильно введена строка элемента.\n");
            break;
        case ERR_COL_INP:
            printf("Неправильно введен столбец элемента.\n");
            break;
        case ERR_MATRIX_SIZES:
            printf("Неправильно введены размерности матрицы.\n");
            break;
        case ERR_FILE_NAME:
            printf("Неправильно введено имя файла.\n");
            break;
        case ERR_OVERFILL_HAND:
            printf("Слишком много элементов введено.\n");
            break;
        case ERR_READ_SIZES_FILE:
            printf("Неправильные размерности матрицы в файле.\n");
            break;
        case ERR_A_INP:
            printf("Неверный формат массива ненулевых элементов в файле.\n");
            break;
        case ERR_AI_INP:
            printf("Неверный формат массива строк элементов в файле.\n");
            break;
        case ERR_AJ_INP:
            printf("Неверный формат массива столбцов элементов в файле.\n");
            break;
        case ERR_AMOUNT_A:
            printf("Неверная длина массива ненулевых элементов в файле.\n");
            break;
        case ERR_AMOUNT_IA:
            printf("Неверная длина массива строк элементов в файле.\n");
            break;
        case ERR_AMOUNT_JA:
            printf("Неверная длина массива столцов элементов в файле.\n");
            break;
        case ERR_AMOUNT_A_STR:
            printf("Неверная длина массива ненулевых элементов вектора-строки в файле.\n");
            break;
        case ERR_FILE_OPEN:
            printf("Невозможно открыть файл.\n");
            break;
        case ERR_EMPTY_MATRIX:
            printf("Матрица пустая.\n");
            break;
        case ERR_EMPTY_FILE:
            printf("Файл пустой.\n");
            break;
        case ERR_AMOUNT_JA_STR:
            printf("Неверная длина массива столбцов элементов вектора-строки в файле.\n");
            break;
    }
}

int main(void)
{
    print_info();
    int rc = input(&big_c, &string_c, &big_s);
    if (rc)
    {
        show_message(rc);
        return rc;
    }
    make_reg_big(&big_r, &big_c);
    
    make_reg_string(&string_r, &string_c);
    
    clock_t start1 = clock();
    reg_mult(&string_r, &big_r, &result_r);
    // reg_mult(&string_r, &big_r, &result_r);
    // reg_mult(&string_r, &big_r, &result_r);
    // reg_mult(&string_r, &big_r, &result_r);
    // reg_mult(&string_r, &big_r, &result_r);
    // reg_mult(&string_r, &big_r, &result_r);
    // reg_mult(&string_r, &big_r, &result_r);
    // reg_mult(&string_r, &big_r, &result_r);
    // reg_mult(&string_r, &big_r, &result_r);
    // reg_mult(&string_r, &big_r, &result_r);
    clock_t end1 = clock();
    double result1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    // result1 /= 10;
    
    make_coord(&result_r, &result_c1);
    
    form(&big_c, &big_s);
    
    clock_t start2 = clock();
    sparse_mult(&string_c, &big_s, &result_c2);
    // sparse_mult(&string_c, &big_s, &result_c2);
    // sparse_mult(&string_c, &big_s, &result_c2);
    // sparse_mult(&string_c, &big_s, &result_c2);
    // sparse_mult(&string_c, &big_s, &result_c2);
    // sparse_mult(&string_c, &big_s, &result_c2);
    // sparse_mult(&string_c, &big_s, &result_c2);
    // sparse_mult(&string_c, &big_s, &result_c2);
    // sparse_mult(&string_c, &big_s, &result_c2);
    // sparse_mult(&string_c, &big_s, &result_c2);
    clock_t end2 = clock();
    double result2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
    // result2 /= 10;
    
    int mem1 = result_r.rows * result_r.columns * sizeof(int) + 2 * sizeof(int) + 
    string_r.rows * string_r.columns * sizeof(int) + 2 * sizeof(int) + 
    big_r.rows * big_r.columns * sizeof(int) + 2 * sizeof(int);
    
    int mem2 = (big_s.len_a + big_s.rows + 1 + big_s.len_a) * sizeof(int) + 2 * sizeof(int) +
    (string_c.len_a + string_c.len_a + string_c.len_a) * sizeof(int) + 2 * sizeof(int) +
    (result_c1.len_a + result_c1.len_a + result_c1.len_a) * sizeof(int) + 2 * sizeof(int);
    
    printf("Результат в координатной форме при умножении 1м способом:");
    output_c(&result_c1);
    printf("Результат в координатной форме при умножении 2м способом:");
    output_c(&result_c2);
    // printf("Умножение 1м способом заняло: %lf секунд\n", result1);
    // printf("Умножение 2м способом заняло: %lf секунд\n", result2);
    // printf("При умножении 1м способом мы потратили %d байт памяти.\n", mem1);
    // printf("При умножении 2м способом мы потратили %d байт памяти.\n", mem2);
    
    return SUCCESS;
}