#include "switch.h"

int action(int number, book *all, key_table *key, int *rows)
{
    int rc = 0;
    switch (number)
    {
        case 1:
            rc = delete_row(all, key, rows);
            if (rc)
            {
                show_message(rc);
                return rc;
            }
            break;
        case 2:
            rc = add_row(all, key, rows);
            if (rc)
            {
                show_message(rc);
                return rc;
            }
            break;
        case 3:
            rc = search_nov_by_name(all, *rows);
            if (rc)
            {
                show_message(rc);
                return rc;
            }
            break;
        // View sorted key table, base table is unsorted
        case 4:
            bubble_sort_key(*rows, key);
            view_key(key, *rows);
            break;
        // View sorted base table (we sorting base)
        case 5:
            bubble_sort_all(*rows, all);
            view_all(all, *rows);
            break;
        // View sorted base table (we sort key table)
        case 6:
            bubble_sort_key(*rows, key);
            view_base_sort_key(all, key, *rows);
            break;
        // Resuls of compare programm speed in graph two tables (key and base)
        case 7:
            measure_results();
            break;
        case 8:
            view_all(all, *rows);
            break;
    }
    return SUCCESS;
}

void show_message(int number)
{
    printf("Ошибка!\n");
    switch (number)
    {
        case ERR_ACTION:
            printf("Вы ввели не номер действия.\n");
            break;
        case ERR_SURNAME_READ:
            printf("Неправильно введена фамамилия автора.\n");
            break;
        case ERR_BOOK_NAME_READ:
            printf("Неправильно введено название книги.\n");
            break;
        case ERR_PUBLICATION_READ:
            printf("Неправильно введено название издательства.\n");
            break;
        case ERR_PAGE_NUMBER_READ:
            printf("Неправильно введено количество страниц в книге.\n");
            break;
        case ERR_LITERATURE_TYPE_READ:
            printf("Неправильно введен вид литературы.\n");
            break;
        case ERR_BRANCH_READ:
            printf("Неправильно введена отрасль технической литературы.\n");
            break;
        case ERR_COUNTRY_READ:
            printf("Неправильно введено название страны.\n");
            break;
        case ERR_YEAR_READ:
            printf("Неправильно введен год издания.\n");
            break;
        case ERR_TYPE_ART_READ:
            printf("Неправильно введен тип художественной литературы.\n");
            break;
        case ERR_MIN_AGE_READ:
            printf("Неправильно введен минимальный возраст читателей детской литературы.\n");
            break;
        case ERR_TYPE_CHILD_READ:
            printf("Неправильно введен тип детской литературы.\n");
            break;
        case ERR_FILE_OPEN:
            printf("Неправильно введено название файла.\n");
            break;
        case ERR_EMPTY_FILE:
            printf("Пустой файл.\n");
            break;
        case ERR_NO_MATCHES:
            printf("Совпадений не найдено.\n");
            break;
        case ERR_KEY_FILL:
            printf("Проблема в заполнении массива ключей.\n");
            break;
        case ERR_COMMAND:
            printf("Неверный формат командной строки.\n");
            break;
        case ERR_SAVING:
            printf("Неверно введено подтверждение или опровержение сохранения.\n");
            break;
    }
}