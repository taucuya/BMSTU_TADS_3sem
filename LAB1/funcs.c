#include "funcs.h"

// This function splits the string on fours beginning from the end, and 
// write them as digits in array 
void split(char *buf, int *nums, int n)
{
    int n_pos = 0;
    int cnt = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (buf[i] == '-')
        {
            nums[n_pos] *= -1;
            break;
        }
        else if (buf[i] == '+')
        {
            break;
        }
        else if (cnt > 1000)
        {
            cnt = 1;
            n_pos++;
        }
        nums[n_pos] += (buf[i] - '0') * cnt;
        cnt *= 10;
    }
}


// Function which multiplies one number on anoter using fours method.
// We write answer as int array of fours in the same order as we 
// multiplied it.
void multiplication(int *integer, int *real, int *number, int *len)
{
    int i = 0;
    int j = 0;
    while (i < 10)
    {
        if (integer[i++] == 0)
            break;
    }
    while (j < 8)
    {
        if (real[j++] == 0)
            break;
    }
    int length = 0;
    if (i == 1 || j == 1)
        length = i + j - 1;
    else
        length = i + j;
    int interval[length];
    for (int k = 0; k < (i + j); k++)
        interval[k] = 0;
    bool flag = false;
    for (int k = 0; k < i; k++)
    {
        for (int e = 0; e < j; e++)
        {
            interval[k + e] += integer[k] * real[e];
            if (i == 1 && j == 1)
            {
                flag = true;
            }
        }
    }
    int k = 0;
    if (i == 0 || j == 0)
        number[0] = 0;
    else
    {
        int tmp = 0;
        if (flag == true)
        {
            number[0] = interval[0];
        }
        else
        {
            for (; k < (i + j); k++)
            {
                interval[k] += tmp;
                number[k] = interval[k] % 10000;
                tmp = interval[k] / 10000;
            }
        }
    }
    if (k == 0 && number[k] == 0)
    {
        *len = 0;
    }
    else if (k == 0 && number[k] != 0)
    {
        *len = i + j - 1;
    }
    else
        *len = i + j;   
}

// Here we rewrite our answer as a string with right order of numbers
void remake(int *integer, int *real, char *result)
{
    int mantis[18];
    int length = 0;
    int *plen = &length;    
    multiplication(integer, real, mantis, plen);
    int i = length;
    int c = 4 * i;
    char signif[c];
    char part[4];
    int end = length - 1;
    int whole = c - 1;
    if (mantis[0] == 0)
    {
        result[0] = '0';
        result[1] = '\0';
    }
    else
    {
        for (;end > -1; end--)
        {
            add_nules(mantis[end], part);
            for (int j = 0; j < 4; j++)
            {
                signif[c - whole - 1] = part[j];
                whole--;
            }
        }
        signif[c] = '\0';
    }
    int cnt = 0;
    while (signif[cnt] == '0')
    {
        cnt++;
    }
    if (cnt == c)
    {
        result[0] = '0';
        result[1] = '\0';
    }
    else if (c > cnt)
    {
        int k = 0;
        while (signif[cnt] != '\0')
            result[k++] = signif[cnt++];
        result[k] = '\0';
    }
}

// We use this function to add zeroes to strings if their length is not four
// (as we need).
void add_nules(int num, char *part)
{
    int a;
    for (int i = 3; i > -1; i--)
    {
        a = num % 10;
        part[i] = a + '0';
        num /= 10;
    }
}

// This function is for rounding the number up to 40 symbols
void rounding(char *beg, int *flag)
{
    int tmp = beg[MAX_LEN] - '0';
    int prom = beg[MAX_LEN - 1] - '0';
    prom++;
    if (prom != 10 && tmp >= 5)
        beg[MAX_LEN - 1] = prom + '0';
    else if (prom == 10 && tmp >= 5)
    {
        for (int i = MAX_LEN - 1; i > -1; i--)
        {
            prom = beg[i] - '0';
            if (prom != 9)
            {
                prom++;
                beg[i] = prom + '0';
                break;
            }
            
            else if (prom == 9)
            {
                beg[i] = '0';
                if (i == 0)
                    *flag = 2;
            }
        }
    }   
    beg[MAX_LEN] = '\0';
    if (*flag == 2)
    {
        beg[0] = '1';
        beg[1] = '\0';
    }
}