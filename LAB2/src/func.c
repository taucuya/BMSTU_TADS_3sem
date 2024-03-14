#include "func.h"

// Main functions

int read_from_file(char *file_name, book *all, int *rows)
{
    FILE *f = fopen(file_name, "r");

    if (!f)
        return ERR_FILE_OPEN;
    char symb;
    int cnt = 0;
    while (!feof(f))
    { 
        // Reading nonvariant
        if (fgets(all[cnt].surname, LENGTH, f) == NULL)
        {
            if (cnt == 0 && feof(f))
                return ERR_EMPTY_FILE;
        }           
        if (isspace(all[cnt].surname[strlen(all[cnt].surname) - 1]))
            all[cnt].surname[strlen(all[cnt].surname) - 1] = '\0';
        if (strlen(all[cnt].surname) == 0)
        {
            continue;
        }
        if (fgets(all[cnt].book_name, LENGTH, f) == NULL)
            return ERR_BOOK_NAME_READ;
        if (isspace(all[cnt].book_name[strlen(all[cnt].book_name) - 1]))
            all[cnt].book_name[strlen(all[cnt].book_name) - 1] = '\0';
        if (strlen(all[cnt].book_name) == 0)
            return ERR_BOOK_NAME_READ;
        if (fgets(all[cnt].publication, LENGTH, f) == NULL)
            return ERR_PUBLICATION_READ;
        if (isspace(all[cnt].publication[strlen(all[cnt].publication) - 1]))
            all[cnt].publication[strlen(all[cnt].publication) - 1] = '\0';
        if (strlen(all[cnt].publication) == 0)
            return ERR_PUBLICATION_READ;
        if (fscanf(f, "%d%c", &all[cnt].page_number, &symb) != 2 || symb != '\n')
            return ERR_PAGE_NUMBER_READ;
        if (fgets(all[cnt].literature_type, LENGTH, f) == NULL)
            return ERR_LITERATURE_TYPE_READ;
        if (isspace(all[cnt].literature_type[strlen(all[cnt].literature_type) - 1]))
            all[cnt].literature_type[strlen(all[cnt].literature_type) - 1] = '\0';
        if (strlen(all[cnt].literature_type) == 0)
            return ERR_LITERATURE_TYPE_READ;
        
        // Reading variant
        
        if (strcmp(all[cnt].literature_type, "техническая") == 0)
        {
            if (fgets(all[cnt].type.tech.branch, LENGTH, f) == NULL)
                return ERR_BRANCH_READ;
            if (isspace(all[cnt].type.tech.branch[strlen(all[cnt].type.tech.branch) - 1]))
                all[cnt].type.tech.branch[strlen(all[cnt].type.tech.branch) - 1] = '\0';
            if (strlen(all[cnt].type.tech.branch) == 0)
                return ERR_BRANCH_READ;
            if (fgets(all[cnt].type.tech.country, LENGTH, f) == NULL)
                return ERR_COUNTRY_READ;
            if (isspace(all[cnt].type.tech.country[strlen(all[cnt].type.tech.country) - 1]))
                all[cnt].type.tech.country[strlen(all[cnt].type.tech.country) - 1] = '\0';
            if (strlen(all[cnt].type.tech.country) == 0)
                return ERR_COUNTRY_READ;
            if (strcmp("отечественная", all[cnt].type.tech.country)
            && strcmp("переводная", all[cnt].type.tech.country))
                return ERR_COUNTRY_READ;
            if (fscanf(f, "%d%c", &all[cnt].type.tech.year, &symb) != 2 || symb != '\n')
                return ERR_YEAR_READ;
        }
        else if (strcmp(all[cnt].literature_type, "художественная") == 0)
        {
            if (fgets(all[cnt].type.artistic.type, LENGTH, f) == NULL)
                return ERR_TYPE_ART_READ;
            if (isspace(all[cnt].type.artistic.type[strlen(all[cnt].type.artistic.type) - 1]))
                all[cnt].type.artistic.type[strlen(all[cnt].type.artistic.type) - 1] = '\0';
            if (strlen(all[cnt].type.artistic.type) == 0)
                return ERR_TYPE_ART_READ;
            if (strcmp("роман", all[cnt].type.artistic.type)
            && strcmp("пьеса", all[cnt].type.artistic.type))
            {
                printf("%s\n", all[cnt].type.artistic.type);
                return ERR_TYPE_ART_READ;
            }
        }
        else if (strcmp(all[cnt].literature_type, "детская") == 0)
        {
            if (fscanf(f, "%d%c", &all[cnt].type.child.min_age, &symb) != 2 || symb != '\n')
                return ERR_MIN_AGE_READ;
            if (fgets(all[cnt].type.child.type, LENGTH, f) == NULL)
                return ERR_TYPE_CHILD_READ;
            if (isspace(all[cnt].type.child.type[strlen(all[cnt].type.child.type) - 1]))
                all[cnt].type.child.type[strlen(all[cnt].type.child.type) - 1] = '\0';
            if (strlen(all[cnt].type.child.type) == 0)
                return ERR_TYPE_CHILD_READ;
            if (strcmp("сказки", all[cnt].type.child.type) 
                && strcmp("стихи", all[cnt].type.child.type))
                return ERR_TYPE_CHILD_READ;
        }   
        cnt++;
    }
    fclose(f);
    *rows = cnt;
    return SUCCESS;
}

void make_key(book *all, key_table *key, int rows)
{
    int i = 0;
    while (i < rows)
    {
        key[i].page_number = all[i].page_number;
        key[i].base_num = i;
        i++;
    }
}

void view_all(book *all, int rows)
{
    int i = 0;
    while (i < rows)
    {
        printf("\n\n");
        printf("-----------------------------------------------------\n");
        printf("\tКнига %d\n", i + 1);
        printf("-----------------------------------------------------\n");
        print_to_view_all(all, i);
        i++;
        printf("-----------------------------------------------------\n");
        printf("\n\n");
    }
}

void view_key(key_table *key, int rows)
{
    int i = 0;
    printf("\n Таблица ключей:\n");
    printf("\n-----------------------\n");
    while (i < rows)
    {
        print_to_view_key(key, i++);
    }
    printf("\n");
}

int delete_row(book *all, key_table *key, int *rows)
{
    char input[INITIAL + LENGTH ];
    printf("Введите название книги строчку с которой хотите удалить: ");
    __fpurge(stdin);
    if (fgets(input, LENGTH, stdin) == NULL)
        return ERR_BOOK_NAME_READ;
    if (isspace(input[strlen(input) - 1]))
        input[strlen(input) - 1] = '\0';
    if (strlen(input) == 0)
        return ERR_BOOK_NAME_READ;
    int i = 0;
    int cnt = 0;
    while (i < *rows)
    {
        if (strcmp(input, all[i].book_name) == 0)
        {
            delete_all(all, i, *rows);
            delete_key(key, i, *rows);
            (*rows)--;
            cnt++;
        }
        else 
            i++;
    }
    if (cnt == 0)
        return ERR_NO_MATCHES;
    return SUCCESS;
}

int add_row(book *all, key_table *key, int *rows)
{
    __fpurge(stdin);
    printf("Введите фамилию автора: ");
    if (fgets(all[*rows].surname, LENGTH, stdin) == NULL)
        return ERR_SURNAME_READ;
    if (isspace(all[*rows].surname[strlen(all[*rows].surname) - 1]))
        all[*rows].surname[strlen(all[*rows].surname) - 1] = '\0';
    if (strlen(all[*rows].surname) == 0)
        return ERR_SURNAME_READ;
    printf("Введите название книги: ");
    if (fgets(all[*rows].book_name, LENGTH, stdin) == NULL)
        return ERR_BOOK_NAME_READ;
    if (isspace(all[*rows].book_name[strlen(all[*rows].book_name) - 1]))
        all[*rows].book_name[strlen(all[*rows].book_name) - 1] = '\0';
    if (strlen(all[*rows].book_name) == 0)
        return ERR_BOOK_NAME_READ;
    printf("Введите название издательства: ");
    if (fgets(all[*rows].publication, LENGTH, stdin) == NULL)
        return ERR_PUBLICATION_READ;
    if (isspace(all[*rows].publication[strlen(all[*rows].publication) - 1]))
        all[*rows].publication[strlen(all[*rows].publication) - 1] = '\0';
    if (strlen(all[*rows].publication) == 0)
        return ERR_PUBLICATION_READ;
    printf("Введите количество страниц как одно целое число: ");
    char symb;
    if (fscanf(stdin, "%d%c", &all[*rows].page_number, &symb) != 2 || symb != '\n')
            return ERR_PAGE_NUMBER_READ;
    printf("Введите один из трех типов литературы (техническая/художественная/детская): ");
    if (fgets(all[*rows].literature_type, LENGTH, stdin) == NULL)
        return ERR_LITERATURE_TYPE_READ;
    if (isspace(all[*rows].literature_type[strlen(all[*rows].literature_type) - 1]))
        all[*rows].literature_type[strlen(all[*rows].literature_type) - 1] = '\0';
    if (strlen(all[*rows].literature_type) == 0)
        return ERR_LITERATURE_TYPE_READ;
    if (strcmp("техническая", all[*rows].literature_type)
        && strcmp("художественная", all[*rows].literature_type)
        && strcmp("детская", all[*rows].literature_type))
        return ERR_COUNTRY_READ;
    
    // Reading variant

    if (strcmp(all[*rows].literature_type, "техническая") == 0)
    {
        printf("Введите отрасль технической литературы: ");
        if (fgets(all[*rows].type.tech.branch, LENGTH, stdin) == NULL)
            return ERR_BRANCH_READ;
        if (isspace(all[*rows].type.tech.branch[strlen(all[*rows].type.tech.branch) - 1]))
            all[*rows].type.tech.branch[strlen(all[*rows].type.tech.branch) - 1] = '\0';
        if (strlen(all[*rows].type.tech.branch) == 0)
            return ERR_BRANCH_READ;
        printf("Введите отечественная или переводная это книга: ");
        if (fgets(all[*rows].type.tech.country, LENGTH, stdin) == NULL)
            return ERR_COUNTRY_READ;
        if (isspace(all[*rows].type.tech.country[strlen(all[*rows].type.tech.country) - 1]))
            all[*rows].type.tech.country[strlen(all[*rows].type.tech.country) - 1] = '\0';
        if (strlen(all[*rows].type.tech.country) == 0)
            return ERR_COUNTRY_READ;
        if (strcmp("отечественная", all[*rows].type.tech.country)
            && strcmp("переводная", all[*rows].type.tech.country))
            return ERR_COUNTRY_READ;
        printf("Введите год издания как одно целое число: ");
        if (fscanf(stdin, "%d%c", &all[*rows].type.tech.year, &symb) != 2 || symb != '\n')
            return ERR_YEAR_READ;
    }
    else if (strcmp(all[*rows].literature_type, "художественная") == 0)
    {
        printf("Введите пьеса это или роман: ");
        if (fgets(all[*rows].type.artistic.type, LENGTH, stdin) == NULL)
            return ERR_TYPE_ART_READ;
        if (isspace(all[*rows].type.artistic.type[strlen(all[*rows].type.artistic.type) - 1]))
            all[*rows].type.artistic.type[strlen(all[*rows].type.artistic.type) - 1] = '\0';
        if (strlen(all[*rows].type.artistic.type) == 0)
            return ERR_TYPE_ART_READ;
        if (strcmp("роман", all[*rows].type.artistic.type)
            && strcmp("пьеса", all[*rows].type.artistic.type))
            return ERR_TYPE_ART_READ;
    }
    else if (strcmp(all[*rows].literature_type, "детская") == 0)
    {
        printf("Введите минимальный возраст читателя как одно целое число: ");
        if (fscanf(stdin, "%d%c", &all[*rows].type.child.min_age, &symb) != 2 || symb != '\n')
            return ERR_MIN_AGE_READ;
        printf("Введите сказки это или стихи: ");
        if (fgets(all[*rows].type.child.type, LENGTH, stdin) == NULL)
            return ERR_TYPE_CHILD_READ;
        if (isspace(all[*rows].type.child.type[strlen(all[*rows].type.child.type) - 1]))
            all[*rows].type.child.type[strlen(all[*rows].type.child.type) - 1] = '\0';
        if (strlen(all[*rows].type.child.type) == 0)
            return ERR_TYPE_CHILD_READ;
        if (strcmp("сказки", all[*rows].type.child.type) 
            && strcmp("стихи", all[*rows].type.child.type))
            return ERR_TYPE_CHILD_READ;
    }

    key[*rows].page_number = all[*rows].page_number;
    key[*rows].base_num = *rows;

    (*rows)++;
    return SUCCESS;
}

int search_nov_by_name(book *all, int rows)
{
    char surname[LENGTH];
    int cnt = 0;
    __fpurge(stdin);
    printf("Ведите фамилию автора, чьи романы вы хотите увидеть: ");
    if (fgets(surname, LENGTH, stdin) == NULL)
        return ERR_SURNAME_READ;
    if (isspace(surname[strlen(surname) - 1]))
        surname[strlen(surname) - 1] = '\0';
    if (strlen(surname) == 0)
        return ERR_SURNAME_READ;
    int names = 0;
    int i = 0;
    for (; i < rows; i++)
    {
        if (strcmp(surname, all[i].surname) == 0)
        {
            names++;
            if (all[i].type.artistic.type && 
                strcmp("роман", all[i].type.artistic.type) == 0)
            {
                printf("-----------------------------------------------------\n");
                printf("\tКнига\n");
                printf("-----------------------------------------------------\n");
                print_to_view_all(all, i);
                printf("-----------------------------------------------------\n");
                printf("\n\n");
                cnt++;
            }
        }
    }
    if (i == rows && !names)
    {
        printf("\nВ списке нет такого автора.\n\n");
        return ERR_NO_MATCHES;
    }
    if (i == rows && names && !cnt)
    {
        printf("\nУ этого автора нет романов.\n\n");
        return ERR_NO_MATCHES;
    }
    return SUCCESS;
}


void bubble_sort_all(int rows, book *all)
{
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = (rows - 1); j > i; j--)
        {
            if (all[j - 1].page_number > all[j].page_number)
            {
                book temp = all[j - 1];
                all[j - 1] = all[j];
                all[j] = temp;
            }
        }
    }
}

void bubble_sort_key(int rows, key_table *key)
{
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = (rows - 1); j > i; j--)
        {
            if (key[j - 1].page_number > key[j].page_number)
            {
                key_table temp = key[j - 1];
                key[j - 1] = key[j];
                key[j] = temp;
            }
        }
    }
}

void view_base_sort_key(book *all, key_table *key, int rows)
{
    int i = 0;

    while (i < rows)
    {
        printf("\n\n");
        printf("-----------------------------------------------------\n");
        printf("\tКнига %d\n", i + 1);
        printf("-----------------------------------------------------\n");
        print_to_view_all(all, key[i].base_num);
        printf("-----------------------------------------------------\n");
        printf("\n\n");
        i++;
    }
}


book all[2500];
key_table key[2500];


void measure_results()
{
    
    char *array[4] = {"file_in_15.txt", "file_in_160.txt","file_in_480.txt"};

    int rows = 0;
    int *prows = &rows;

    printf("\n");
    printf("-------------------------------------------------\n");
    printf("|   Длина массива   |     СП      |      БС     |\n");

    for (int j = 0; j < 3; j++)
    {
        double sum = 0;
        for (int i = 0; i < 1000; i++)
        {
            int rc = read_from_file(array[j], all, prows);
            if (rc)
                printf("%d\n", rc);
            clock_t start1 = clock();
            bubble_sort_all(rows, all);
            clock_t end1 = clock();
            double result1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
            sum += result1;
        }
        double res1 = sum / 1000;
        sum = 0;
        for (int i = 0; i < 1000; i++)
        {
            make_key(all, key, rows);
            clock_t start2 = clock();
            bubble_sort_key(rows, key);
            clock_t end2 = clock();
            double result2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC;
            sum += result2;
        }
        double res2 = sum / 1000;
        sum = 0;
        for (int i = 0; i < 1000; i++)
        {
            read_from_file(array[j], all, prows);
            clock_t start3 = clock();
            qsort(all, rows, sizeof(book), comp_page_number_all);
            clock_t end3 = clock();
            double result3 = ((double)(end3 - start3)) / CLOCKS_PER_SEC;
            sum += result3;
        }
        double res3 = sum / 1000;
        sum = 0;
        for (int i = 0; i < 1000; i++)
        {
            make_key(all, key, rows);
            clock_t start4 = clock();
            qsort(key, rows, sizeof(key_table), comp_page_number_key);
            clock_t end4 = clock();
            double result4 = ((double)(end4 - start4)) / CLOCKS_PER_SEC;
            sum += result4;
        }
        double res4 = sum / 1000;
        printf("--------------------время-в-%%--------------------\n");
        printf("----------------------полная---------------------\n");
        printf("|%19s|%13lf|%13lf|\n", array[j], res1, res3);
        printf("----------------------ключи----------------------\n");
        printf("|%19s|%13lf|%13lf|\n", array[j], res2, res4);
        printf("-----------------память-в-байтах-----------------\n");
        printf("----------------------полная---------------------\n");
        printf("|%19s|%13zu|%13zu|\n", array[j], rows * sizeof(book), rows * sizeof(book));
        printf("----------------------ключи----------------------\n");
        printf("|%19s|%13zu|%13zu|\n", array[j], rows * (sizeof(book) 
            + sizeof(key_table)), rows * (sizeof(book) + sizeof(key_table)));
        printf("-------------------------------------------------\n");

    }

    printf("\nСП - сортировка пузырьком\nБС - быстрая сортировка\n");
    printf("проценты показывают насколько медленнее эта сортировка для \n"
    "массива полных структур, чем для массива ключей и наоборот.\n");

    printf("\n");
}

void write_to_file(book *all, char *file_name, int rows)
{
    FILE *f = fopen(file_name, "w");

    int i = 0;
    while (i < rows)
    {
        print_to_view_all_in_file(all, i, f);
        if (i != (rows - 1))
            fprintf(f, "\n");   
        i++;
    }
}

// Additionall functions

void delete_all(book *all, int num, int rows)
{
    book tmp;
    for (; num < rows; num++)
    {
        tmp = all[num + 1];
        all[num + 1] = all[num];
        all[num] = tmp;
    }
}

void delete_key(key_table *key, int num, int rows)
{
    key_table tmp;
    for (; num < rows; num++)
    {
        tmp = key[num + 1];
        key[num + 1] = key[num];
        key[num] = tmp;
    }
}

void print_to_view_all(book *all, int i)
{
    printf(" Фамилия автора          : %s\n Название книги          : %s\n "
    "Название издательства   : %s\n Количество страниц      : %d\n "
    "Тип литературы          : %s\n ", all[i].surname, 
    all[i].book_name, all[i].publication, all[i].page_number, all[i].literature_type);
    if (strcmp(all[i].literature_type, "техническая") == 0)
    {
        printf("Отрасль                 : %s\n"
        " Страна                  : %s\n Год издания             : %d\n", all[i].type.tech.branch, 
        all[i].type.tech.country, all[i].type.tech.year);
    }
    else if (strcmp(all[i].literature_type, "художественная") == 0)
    {
        printf("Вид                     : %s\n", all[i].type.artistic.type);
    }
    else if (strcmp(all[i].literature_type, "детская") == 0)
    {
        printf("Минимальный возраст     : %d\n Вид                     : %s\n", 
        all[i].type.child.min_age, all[i].type.child.type);
    }
}

void print_to_view_all_in_file(book *all, int i, FILE *f)
{
    fprintf(f, "%s\n%s\n%s\n%d\n%s\n", all[i].surname, 
    all[i].book_name, all[i].publication, all[i].page_number, all[i].literature_type);
    if (strcmp(all[i].literature_type, "техническая") == 0)
    {
        fprintf(f, "%s\n%s\n%d", all[i].type.tech.branch, 
        all[i].type.tech.country, all[i].type.tech.year);
    }
    else if (strcmp(all[i].literature_type, "художественная") == 0)
    {
        fprintf(f, "%s", all[i].type.artistic.type);
    }
    else if (strcmp(all[i].literature_type, "детская") == 0)
    {
        fprintf(f, "%d\n%s", all[i].type.child.min_age, all[i].type.child.type);
    }
}

void print_to_view_key(key_table *key, int i)
{
    printf("|%10d|%10d|\n", key[i].base_num, key[i].page_number);
    printf("-----------------------\n");
}

int comp_page_number_all(const void * a, const void * b)
{
    const book *first = a;
    const book *second = b;
    return first->page_number - second->page_number;
}

int comp_page_number_key(const void * a, const void * b)
{
    const key_table *first = a;
    const key_table *second = b;
    return first->page_number - second->page_number;
}

void copy_to_new_all(book *all, book *all1, int rows)
{
    int i = 0;
    while (i < rows)
    {
        all1[i] = all[i];
        i++;
    }
}

void copy_to_new_key(key_table *key, key_table *key1, int rows)
{
    int i = 0;
    while (i < rows)
    {
        key1[i] = key[i];
        i++;
    }
}