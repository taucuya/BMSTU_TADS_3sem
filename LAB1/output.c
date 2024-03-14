#include "output.h"

// Just output function, we merge sign, mantis, order
int output(int *pafter, int *minus, char *result, int *order)
{
    int length = strlen(result);
    int flag = 0;
    int *pflag = &flag;
    if (length > MAX_LEN)
    {
        rounding(result, pflag);
    }
    if (result[0] == '0')
    {        
        *order = 0;
    }
    else 
    {
        if (flag == 2)
        {
            *order += 1;
        }
        if (*pafter > length)
        {
            *order -= (*pafter - length);
        }
        else if (*pafter < length)
        {
            *order += (length - *pafter);
        }
        if (*order > 99999 || *order < -99999)
        {
            return ERR_ORDER;
        }
    }
    printf("  |----|----|----|----|----|----|----|----|\n");
    printf("-0.    1    2    3    4    5    6    7    8\n");
    if (*minus % 2 != 0)
    {
        printf("-0.%sE%d\n", result, *order);
    }
    else
    {
        printf("0.%sE%d\n", result, *order);
    }
    return SUCCESS;
}