#include "info.h"

void print_info()
{
    printf("\nПрограмма строит бинарное дерево, хэш-таблицы с открытой и закрытой\n\
адресацией из букв введенной строки. Реализовать удаление повторяющихся\n\
букв из бинарного дерева, поиск во всех видах структур, реструктуризацию\n\
обоих видов хэш-таблиц. Провести замеры времени для поиска элементов во\n\
всех структурах.\n\n\
Пункты меню: \n\n\
(чтобы выполнить какую-то команду, после предложения программы ввести номер \n\
этой команды)\n\n\
0. Искусственное завершение программы.\n\
1. Удаляет все повторяющиеся вершины из дерева и обновляет файл с графиком,\n\
учитывая последние изменения.\n\
2. Перестраивает хэш-таблицу с закрытой адресацией с учетом наиболее\n\
удобного для нас размера.\n\
3. Перестраивает хэш-таблицу с открытой адресацией с учетом наиболее\n\
удобного для нас размера.\n\
4. Выводит хэш-таблицу с закрытой адресацией.\n\
5. Выводит хэш-таблицу с открытой адресацией.\n\
6. Ищет букву в дереве и выводит, при наличие ее сыновей.\n\
7. Ищет букву в хэш-таблице с закрытой адресацией, выводит ее и количество\n\
ее повторений.\n\
8. Ищет букву в хэш-таблице с открытой адресацией, выводит ее и количество\n\
ее повторений.\n\n");
}