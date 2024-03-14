#include "info.h"
#include "input_int.h"
#include "errors.h"
#include "input_real.h"
#include "output.h"

void show_message(int rc) 
{
    printf("Ошибка!\n");
    switch (rc) 
    {
        case ERR_INP_LEN:
            printf("Неправильная длина строки.\n");
            break;
        case WRONG_INT:
            printf("Некоторые проблемы со вводом целого числа.\n");
            break;
        case ERR_EMPTY:
            printf("Была введена пустая строка.\n");
            break;
        case ERR_FORMAT:
            printf("Формат действительного числа ошибочен.\n");
            break;
        case ERR_DOT:
            printf("Некоторые проблемы с точками в действительном числе.\n");
            break;
        case ERR_ORDER:
            printf("Переполнение порядка, результат не может быть выведен.\n");
            break;
    }
}


int main(void) {
    int order = 0;
    int *porder = &order;
    int after = 0;
    int *pafter = &after;
    int before = 0;
    int *pbefore = &before;
    int minus = 0;
    int *pminus = &minus;
    int first_rev_fours[10] = {0};
    int second_rev_fours[8] = {0};
    char mantis[M_AMOUNT + 100];
    print_information();
    int rc1 = input_int(first_rev_fours, pminus);
    if (rc1)
    {
        show_message(rc1);
        return rc1;
    }
    int rc = input_real(second_rev_fours, porder, pafter, pbefore, pminus);
    if (rc)
    {
        show_message(rc);
        return rc;
    }
    if (before == 0 && after != 0)
        after -= 1;
    remake(first_rev_fours, second_rev_fours, mantis);
    print_in_end();
    int rc2 = output(pafter, pminus, mantis, porder);
    if (rc2)
    {
        show_message(rc2);
        return SUCCESS;
    }
    return SUCCESS;
}
