#ifndef _FUNC_H_
#define _FUNC_H_

#include "gen.h"

#define INITIAL 40
#define LENGTH 100

// Structures


typedef struct 
{
    char branch[LENGTH];
    char country[LENGTH];
    int year;
} s_tech;

typedef struct 
{
    char type[LENGTH];
} s_artistic;

typedef struct 
{
    int min_age;
    char type[LENGTH];
} s_child;

typedef union
{
    s_tech tech;
    s_artistic artistic;
    s_child child; 
} u_type;
 typedef struct 
{
    char surname[LENGTH];
    char book_name[LENGTH];
    char publication[LENGTH];
    int page_number;
    char literature_type[LENGTH];
    u_type type;
} book;


typedef struct 
{
    int base_num;
    int page_number;
} key_table;


// Main functions

int read_from_file(char *file_name, book *all, int *rows);
void write_to_file(book *all, char *file_name, int rows);
void make_key(book *all, key_table *key, int rows);
int delete_row(book *all, key_table *key, int *rows);
int add_row(book *all, key_table *key, int *rows);
int search_nov_by_name(book *all, int rows);
void view_all(book *all, int rows);
void view_key(key_table *key, int rows);
void view_base_sort_key(book *all, key_table *key, int rows);
void bubble_sort_all(int rows, book *all);
void bubble_sort_key(int rows, key_table *key);
void measure_results();

// Additionsl functions

void delete_all(book *all, int num, int rows);
void delete_key(key_table *key, int num, int rows);
void print_to_view_all(book *all, int i);
void print_to_view_key(key_table *key, int i);
void print_to_view_all_in_file(book *all, int i, FILE *f);
int comp_page_number_all(const void * a, const void * b);
int comp_page_number_key(const void * a, const void * b);
void copy_to_new_all(book *all, book *all1, int rows);
void copy_to_new_key(key_table *key, key_table *key1, int rows);

#endif