#include "input_int.h"

int input_int(int *nums, int *pminus)
{
    char buf[M_LEN + 100];
    char no_nules[M_LEN + 10];
    printf("Введите первое число:\n");
    printf("|----|----|----|----|----|----|----|----|\n");
    printf("-    1    2    3    4    5    6    7    8\n");
    if (!fgets(buf, sizeof(buf), stdin))
        return ERR_INPUT;
    int len = strlen(buf);
    if (len == 1)
        return ERR_EMPTY;
    buf[len - 1] = '\0';
    int cnt = 0;
    int p = 0;
    int plus = 0;
    // If we have space signs before our number we just ignore them
    while (isspace(buf[p])) 
        p++;
    int flag = 0;
    // Here we check if there any signs before the number, and if there is a minus
    // we add it in the array for our integer
    if ((buf[p] == '-') || (buf[p] == '+'))
    {
        if (buf[p] == '-')
        {
            *pminus += 1;
        }
        else
            plus++;
        p++;
    }
    // If there are any zeroes before the number we just skip them, as spaces
    while (buf[p] == '0')
        p++;
    // Here we add digits in our final number and if there are any spaces after 
    // the number we check if there is only one number in input
    for (;p < (len - 1); p++)
    {
        if (isspace(buf[p]))
            flag++;
        if (flag == 0 && !isdigit(buf[p]))
            return WRONG_INT;
        else if (flag == 0 && !isspace(buf[p]) && buf[p] != '\0')
        {
            no_nules[cnt] = buf[p];
            cnt++;
        }
        else if (flag > 0 && !isspace(buf[p]) && buf[p] != '\0')
            return WRONG_INT;
    }
    no_nules[cnt] = '\0';
    len = strlen(no_nules);
    // Here we check the length of a number
    if (len > M_LEN)
    {
        return ERR_INP_LEN; 
    }
    int i = 0;
    // Here we check if number consists only of digits
    for (; i < (len - 1); i++)
    {
        if (!isdigit(no_nules[i]))
        {
            return WRONG_INT;
        }
    }
    split(no_nules, nums, len);
    return SUCCESS;
}