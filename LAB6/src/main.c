#include "input.h"
#include "print_tree.h"
#include "info.h"

int main()
{
    tree_n *root = NULL;
    // clock_t start1;
    // clock_t end1;
    // start1 = clock();
    int rc = create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // root = NULL;
    // create_tree(&root);
    // end1 = clock();
    // double result1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC * 1000000;
    // printf("%lf\n", result1);
    if (rc)
    {
        printf("Ошибка!\nВы неправильно ввели строку!\n");
    }
    int action = 1;
    while (action)
    {
        print_info();
        printf("Введите номер действия, которое хотите совершить.\n"
            "Чтобы завершить ввод, напишите 0.\n");
        __fpurge(stdin);
        if (scanf("%d",&action) != 1)
            return ERR_NUM_INPUT;
        if (action == 0)
        {
            printf("Программа была завершена.\n");
            break;
        }
        else if (action == 1)
        {
            if (root == NULL)
                printf("Невозможно построить дерево, отсутствуют его элементы.\n");
            else
            {
                tree_to_dot(root);
                printf("Дерево было успешно построено.\n");
            }
        }
        else if (action == 2)
        {
            if (insert_letter(&root))                
                printf("Ошибка!\nВы неправильно ввели букву для вставки.\n");
            else 
                printf("Вставка успешно завершена.\n");
        }
        else if (action == 3)
        {
            if (delete_letter(&root))
                printf("Ошибка!\nВы неправильно ввели букву для удаления.\n");
            else 
                printf("Удаление успешно завершено. Если удаляемого элемента не было в дереве, дерево не изменилось.\n");
        }
        else if (action == 4)
        {
            
            int rc1 = search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            // search_letter(root);
            if (rc1)
                printf("Ошибка!\nВы неправильно ввели букву для поиска.\n");
            else 
                printf("Поиск успешно завершен.\n");
        }
        else if (action == 5)
        {
            // clock_t start2;
            // clock_t end2;
            // start2 = clock();
            inorder_del(root, &root);
            // end2 = clock();
            // double result2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC * 1000000;
            // printf("Tree %lf\n", result2);
            // create_str();
            inorder_print(root);
            printf("\n");
        }
    }
    return SUCCESS;
}