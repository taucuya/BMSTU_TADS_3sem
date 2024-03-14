#include "input_real.h"

int input_real(int *nums, int *porder, int *pafter, int  *pbefore, int *pminus)
{
    char buf[M_LEN + 100];
    char order[M_ORD + 10];
    char mantis[M_AMOUNT + 10];
    char no_nules_mantis[M_AMOUNT + 10];
     char final_number[M_AMOUNT + 10];
    int cnt_ord = 0;
    printf("Введите второе число:\n");
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
    while (isspace(buf[p])) 
        p++;
    // If we have a minus we add 1 to our minus counter
    if (buf[p] == '-')
    {
        *pminus += 1;
        p++;
    }
    if (buf[p] == '+')
    {
        p++;
    }
    bool dot = false;
    int zeros = 0;
    if (isspace(buf[p]))
    {
        return ERR_FORMAT;
    }
    // Here we delete leading zeroes
    while (buf[p] == '0')
    {
        if (buf[p] == '0')
        {
            zeros++;
            if (buf[p + 1] != '.')
                p++;
            else if (buf[p + 1] == '.')
            {
                break;
            }
        }
    }
    // Here we add mantis to mantis array
    while (isdigit(buf[p]) || buf[p] == '.')
    {
        if (buf[p] == '\0')
        {
            break;
        }
        else if (buf[p] == '.' && dot == false)
        {
            mantis[cnt++] = buf[p];
            dot = true;
        }
        else if (buf[p] == '.' && dot == true)
        {
            return ERR_DOT;
        }
        else if (isdigit(buf[p]))
        {
            mantis[cnt++] = buf[p];
        }
        p++;    
    }
    mantis[cnt] = '\0';
    if (dot == true)
    {
        int l = strlen(mantis) - 1;
        int cnt_zeroes = 0;
        // This part of code we us to delete zeroes which are leading if the number with point 
        while (mantis[l] == '0')
        {
            cnt_zeroes++;
            l--;
        }
        l = strlen(mantis);
        int length_no_nules = l - cnt_zeroes;
        int h = 0;
        for (; h < length_no_nules; h++)
        {
            no_nules_mantis[h] = mantis[h];
        }
        no_nules_mantis[h] = '\0';
    } 

    // Here we check format of the string

    if (buf[p] != '\0' && buf[p] != 'e' && buf[p] != 'E' && !isspace(buf[p]))
        return ERR_FORMAT;

    // If there are e`s in the string
    else if (buf[p] == 'E' || buf[p] == 'e')
    {
        p++;
        if (buf[p] != '+' && buf[p] != '-' && !isdigit(buf[p]))
            return ERR_FORMAT;
        else if (buf[p] == '+')
            p++;
        else if (buf[p] == '-')
        {
            order[0] = '-';
            p++;
            cnt_ord = 1;
        }   
        int space = 0;
        if (!isdigit(buf[p]))
            return ERR_FORMAT;
        else
        {
            while (buf[p] != '\0')
            {
                if (space > 0 && !isspace(buf[p]))
                    return ERR_FORMAT;
                else if (isdigit(buf[p]) && space == 0)
                    order[cnt_ord++] = buf[p++];
                else if (isspace(buf[p]))
                {
                    printf("HERE\n");
                    p++;
                    space++;
                }
            }
        }
        order[cnt_ord] = '\0';
        if (order[0] == '-' && strlen(order) > M_ORD + 1) 
        {            
            return ERR_INP_LEN;
        }
        else if (isdigit(order[0]) && strlen(order) > M_ORD)
        {
            return ERR_INP_LEN;
        }
    }
    *porder = atoi(order);
    bool flag = false;
    // Here we count the amount of symbols after and before the point and 
    // make a 'final number' which contains just significant figures
    int i = 0;
    if (dot == true)
    {
        int counter = 0;
        while (no_nules_mantis[i] == '0' || no_nules_mantis[i] == '.')
        {
            if (no_nules_mantis[i] == '.')
            {
                flag = true;
            }
            if (flag == true)
                *pafter += 1;
            i++;
        }
        for (; no_nules_mantis[i] != '\0'; i++)
        {
            if (no_nules_mantis[i] == '.')
                flag = true;
            else if (flag == true)
            {
                *pafter += 1;
                final_number[counter] = no_nules_mantis[i];
                counter++;
            }
            else
            {
                *pbefore += 1;
                final_number[counter] = no_nules_mantis[i];
                counter++;
            }
        }
        final_number[counter] = '\0';
    }
    else
    {
        for (; mantis[i] != '\0'; i++)
        {
            final_number[i] = mantis[i];
        }
        final_number[i] = '\0';
    }
    if (strlen(final_number) > M_AMOUNT)
        return ERR_INP_LEN;
    split(final_number, nums, strlen(final_number));
    return SUCCESS;
}