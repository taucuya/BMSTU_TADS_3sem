#include "gen.h"
#include "info.h"
#include "switch.h"
#include "func.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        show_message(ERR_COMMAND);
        return ERR_COMMAND;
    }
    int number;
    print_start_info();

    // Entering the command number

    book all[INITIAL + LENGTH];
    key_table key[INITIAL + LENGTH];
    
    int rows;

    int rc = read_from_file(argv[1], all, &rows);
    if (rc)
    {
        show_message(rc);
        return rc; 
    }
    make_key(all, key, rows);
    printf("\nВведите номер действия, которое хотите совершить с таблицей: \n");
    if (scanf("%d", &number) != 1)
    {
        show_message(ERR_ACTION);
        return ERR_ACTION;
    }
    if (number < 0 || number > 8)
    {
        show_message(ERR_ACTION);
        return ERR_ACTION; 
    }
    int r = 0;
    int check;
    char save[10];
    while (number)
    {
        r = action(number, all, key, &rows); 
        if (r)
            return r;
        make_key(all, key, rows);
        print_start_info();
        printf("\nВведите номер действия, которое хотите совершить с таблицей: \n");
        if (scanf("%d", &number) != 1)
        {
            show_message(ERR_ACTION);
            return ERR_ACTION;
        }
        if (number < 0 || number > 8)
        {
            show_message(ERR_ACTION);
            return ERR_ACTION; 
        }
    }
    
    printf("Хотите сохранить таблицу в файл?(да/нет)\n");
    check = scanf("%s", save);
    if (check == 1 && strcmp("да", save) == 0)
    {
        write_to_file(all, argv[1], rows);
        return SUCCESS;
    }
    if (check == 1 && strcmp("нет", save) == 0)
    {
        return SUCCESS;
    }
    else
        return ERR_SAVING;
}