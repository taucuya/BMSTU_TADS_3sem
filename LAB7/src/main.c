#include "input.h"
#include "print_tree.h"
#include "info.h"
#include "print_table.h"

int main()
{
    tree_n *root = NULL;
    table_mas *table = malloc(sizeof(table_mas));
    // printf("%zu %zu", sizeof(table_n), sizeof(table_s));
    printf("Введите строку, которую хотите обработать.\n");
    __fpurge(stdin);
    char tmp[LEN];
    if (!fgets(tmp, LEN, stdin))
    {
        return ERR_READ;
    }
    tmp[strlen(tmp) - 1] = '\0';
    if (strlen(tmp) == 0)
    {
        return ERR_EMPTY_INPUT;
    }
    create_tree(&root, tmp);
    printf("Введите максимальную длину хэш-таблицы.\n");
    int len;
    if (scanf("%d", &len) != 1)
        return ERR_READ;
    if (len < 1)
    {
        return ERR_READ;
    }
    int for_s = len;
    table->array = malloc(len * sizeof(table_n));
    if (!table->array)
    {
        return ERR_ALLOC;
    }
    table->array_simple = malloc((10 * len) * sizeof(table_s));
    if (!table->array_simple)
    {
        return ERR_ALLOC;
    }
    table->num = 0;
    table->s_num = 0;
    
    create_table_chain(table, tmp, len);
    create_table_simple(table, tmp, len);

    bool flag = false;
    int action = 1;
    while (action)
    {
        print_info();
        printf("Введите номер действия, которое хотите совершить.\n"
            "Чтобы завершить работу программы, напишите 0.\n");
        __fpurge(stdin);
        if (scanf("%d",&action) != 1 || action < 0 || action > 8)
            return ERR_NUM_INPUT;
        if (action == 0)
        {
            printf("Программа успешно завершена.\n");
            break;
        }
        else if (action == 1)
        {
            inorder_del(root, &root);
            if (root)
                tree_to_dot(root);
            else
                printf("Дерево пустое.\n");
            // inorder_print(root);
            // printf("\n");
            
        }
        else if (action == 2)
        {
            rebuild_chain(table, tmp, &len);
        }
        else if (action == 3)
        {
            rebuild_simple(table, tmp, &for_s);
            flag = true;
        }
        else if (action == 4)
        {
            print_table_chain(table, len);
            // printf("it is %d\n", table->num);
        }
        else if (action == 5)
        {
            int length = len * 4;
            // printf("\t%d\n", for_s);
            if (flag)
                print_table_simple(table, for_s);
            else
                print_table_simple(table, length);
        }
        else if (action == 6)
        {
            if (!root)
                printf("Дерево пустое.\n");
            search_letter(root);
        }
        else if (action == 7)
        {
            char let;
            __fpurge(stdin);
            if (scanf("%c", &let) != 1)
            {
                return ERR_READ;
            }
            search_table_chain(table, let, len);
        }
        else if (action == 8)
        {
            char let;
            __fpurge(stdin);
            if (scanf("%c", &let) != 1)
            {
                return ERR_READ;
            }
            search_table_simple(table, let, len);
        }
    }
    return SUCCESS;
}