#include "print_info.h"
#include "structs.h"
#include "switch.h"

int main(void)
{
    int n = 1;
    list *adress[MAX_LEN];
    mas words_mas;
    words_mas.num = -1;
    int amount = 0;
    list *head = NULL;
    head = malloc(sizeof(list));
    head->next = NULL;
    if (!head)
    {
        return ERR_ALLOC;
    }
    int cnt = 0;
    int rc;
    double result1, result2, result3, result4, result5, result6;
    while(n)
    {
        print_info();
        printf("\nВведите номер действия, которое хотите совершить: ");
        if (scanf("%d", &n) != 1)
        {
            return ERR_NUM_INPUT;
        }
        if (n > 9 || n < 0)
        {
            return ERR_NUM_INPUT;
        }
        rc = action(n, &words_mas, &amount, adress, &head, &cnt, &result1, &result2, &result3, &result4, &result5, &result6);
        if (rc)
        {
            free_list(head);
            show_message(rc);
            return rc;
        }
    }
    free_list(head);
    printf("sizeof(list) = %zu\n", sizeof(list) * amount);
    printf("sizeof(mas) = %zu\n", sizeof(mas));

    printf("\n%lf\n", result1);
    printf("%lf\n", result2);
    printf("%lf\n", result3);
    printf("%lf\n", result4);
    printf("%lf\n", result5);
    printf("%lf\n", result6);
    return SUCCESS;
}