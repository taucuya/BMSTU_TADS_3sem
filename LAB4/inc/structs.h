#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#define MAX_LEN 1000
#define WORD_LEN 20

typedef struct  
{
    char words[MAX_LEN][WORD_LEN];
    int num;
} mas;

typedef struct li 
{
    char word[WORD_LEN];
    struct li *next;    
} list;

#endif