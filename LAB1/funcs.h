#include <stdio.h>
#include "errors.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 40  

void split(char *buf, int *nums, int n);
void multiplication(int *integer, int *real, int *number, int *len);
void remake(int *integer, int *real, char *mantis);
void add_nules(int num, char *part);
void rounding(char *beg, int *flag);