#include "switch.h"

int action(int num, mas *words_m, int *amount, list **adress, list **head, int *cnt, double *result1, double *result2, double *result3, double *result4, double *result5, double *result6)
{
    list *dl = NULL;
    int rc = 0;
    clock_t start1;
    clock_t end1;
    clock_t start2;
    clock_t end2;
    clock_t start3;
    clock_t end3;
    clock_t start4;
    clock_t end4;
    clock_t start5;
    clock_t end5;
    clock_t start6;
    clock_t end6;
    switch (num)
    {
        case 1:
            start1 = clock();
            rc = delete_mas(words_m);
            end1 = clock();
            (*result1) += ((double)(end1 - start1)) / CLOCKS_PER_SEC;
            if (rc)
                return rc;
            break;
        case 2:
            start2 = clock();
            rc = delete_list(head, amount, &dl);
            end2 = clock();
            (*result2) += ((double)(end2 - start2)) / CLOCKS_PER_SEC;
            if (rc)
                return rc;
            adress[(*cnt)++] = dl;
            break;
        case 3:
            start3 = clock();
            rc = add_mas(words_m);
            end3 = clock();
            (*result3) += ((double)(end3 - start3)) / CLOCKS_PER_SEC;
            if (rc)
                return rc;
            break;
        case 4:
            start6 = clock();
            rc = add_list(head, amount);
            end6 = clock();
            (*result4) += ((double)(end6 - start6)) / CLOCKS_PER_SEC;
            if (rc)
                return rc;
            break;
        case 5:
            start4 = clock();
            show_mas(words_m);
            end4 = clock();
            (*result5) += ((double)(end4 - start4)) / CLOCKS_PER_SEC;
            break;
        case 6:
            start5 = clock();
            show_list(head, *amount);
            end5 = clock();
            (*result6) += ((double)(end5 - start5)) / CLOCKS_PER_SEC;
            break;
        case 7:
            show_adresses(adress, *cnt);
            break;
        case 8:
            show_mas_reversed(words_m);
            break;
        case 9:
            show_list_reversed(head, *amount);
            break;
    }
    return SUCCESS;
}

void show_message(int err_num)
{
    printf("Ошибка!");
    switch (err_num)
    {
        case ERR_WORD_INPUT:
            printf("Неправильно введено слово.\n");
            break;
        case ERR_NUM_INPUT:
            printf("Неправильно введен номер действия.\n");
            break;
        case ERR_NO_EL_TO_DELETE:
            printf("Нет элементов для удаления.\n");
            break;
        case ERR_ALLOC:
            printf("Невозможно выделить память.\n");
            break;
        case ERR_OVERFLOW:
            printf("Переполнение стека.\n");
            break;
        case ERR_EMPTY_INPUT:
            printf("Пустой ввод.\n");
            break;
    }
}