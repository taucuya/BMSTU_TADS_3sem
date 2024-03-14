#include "input.h"

int input(coord *big_c, coord *string_c, sparse *big_s)
{
    printf("Введите имя файла, из которого хотите ввести матрицы,\n"
    " или напишите: \"нет\", если хотите ввести матрицы вручную.\n");
    char filename[FILE_NAME_LEN];
    if (scanf("%s", filename) != 1)
    {
        return ERR_FILE_NAME;
    }
    if (strcmp("нет", filename) == 0)
    {
        printf("С помощью координатного метода ввведите разреженную матрицу.\n"
        "Чтобы закончить заполнять матрицу введите \"0\".\n");
        int rc = hand_input(big_c, string_c, big_s);
        if (rc)
        {
            return rc;
        }
    }
    else 
    {
        int rc1 = read_file(filename, big_c, string_c, big_s);
        if (rc1)
        {
            return rc1;
        }
        
    }
    return SUCCESS;
}


 int hand_input(coord *big_c, coord *string_c, sparse *big_s)
{
    int i = 0;
    
    printf("\nВведите размерности разреженой матрицы \n"
    "сначала количество строк, потом количество столбцов): ");
    int rc = scanf("%d%d", &big_c->rows, &big_c->columns);
    if (rc != 2)
    {
        return ERR_MATRIX_SIZES;
    }
    if (big_c->rows < 1 || big_c->columns < 1 || big_c->rows > 1000 || big_c->columns > 1000)
    {
        return ERR_MATRIX_SIZES;
    }
    
    big_s->rows = big_c->rows;
    big_s->columns = big_c->columns;
    int check = 1;

    while (check != 0)
    {
        printf("Введите элемент матрицы: ");
        if (scanf("%d", &check) != 1)
        {
            return ERR_EL_INP;
        }
        if (check != 0)
        {
            big_c->a[i] = check;
            big_s->a[i] = check;
            printf("Введите строку, в которой он находится: ");
            if (scanf("%d", &big_c->ia[i]) != 1)
            {
                return ERR_ROW_INP;
            }
            if (big_c->ia[i] < 0 || big_c->ia[i] > big_c->rows - 1)
            {
                return ERR_ROW_INP;
            }
            big_s->ia[i] = big_c->ia[i];
            printf("Введите столбец, в котором он находится: ");
            if (scanf("%d", &big_c->ja[i]) != 1)
            {
                return ERR_COL_INP;
            }
            if (big_c->ja[i] < 0 || big_c->ja[i] > big_c->columns - 1)
            {
                return ERR_COL_INP;
            }
            i++;
        }
    }
    if (i == 0)
    {
        return ERR_EMPTY_MATRIX;
    }
    if (i > big_c->rows * big_c->columns)
    {
        return ERR_OVERFILL_HAND;
    }
    big_c->len_a = i;
    big_s->len_a = i;

    int j = 0;

    check = 1;

    string_c->rows = 1;
    string_c->columns = big_c->rows;

    printf("\nВведите разреженный вектор строку. Ввод продолжается пока не введен \"0\".\n");
    while (check != 0)
    {
        printf("Введите элемент разреженного вектора-строки: ");
        if (scanf("%d", &check) != 1)
        {
            return ERR_EL_INP;
        }
        if (check != 0)
        {
            string_c->a[j] = check;
            string_c->ia[j] = 0;
            printf("Введите столбец, в котором он находится: ");
            if (scanf("%d", &string_c->ja[j]) != 1)
            {
                return ERR_COL_INP;
            }
            if (string_c->ja[j] < 0 || string_c->ja[j] > big_c->rows - 1)
            {
                return ERR_COL_INP;
            }
            j++;
        }
    }
    if (j == 0)
    {
        return ERR_EMPTY_MATRIX;
    }

    if (j > big_c->rows)
    {
        return ERR_OVERFILL_HAND;
    }
    string_c->len_a = j;
    return SUCCESS;
}



int read_file(char *file_name, coord *big_c, coord *string_c, sparse *big_s)
{
    FILE *f1 = fopen(file_name, "r");
    if (!f1)
    {
        return ERR_FILE_OPEN;
    }
    int i = 0;
    if (getc(f1) == EOF)
    {
        fclose(f1);
        return ERR_EMPTY_FILE;
    }
    fclose(f1);

    FILE *f = fopen(file_name, "r");
    
    if (fscanf(f, "%d%d\n", &big_c->rows, &big_c->columns) != 2)
    {
        fclose(f);
        return ERR_READ_SIZES_FILE;
    }
    if (big_c->rows < 1 || big_c->columns < 1)
    {
        fclose(f);
        return ERR_READ_SIZES_FILE;
    }
    big_s->rows = big_c->rows;
    big_s->columns = big_c->columns;

    string_c->rows = 1;
    string_c->columns = big_c->rows;
    
    
    int err;
    char sym;
    int flag = 0;
    while (fscanf(f, "%d%c", &err, &sym) == 2)
    {
        if (!err)
        {
            fclose(f);
            return ERR_A_INP;
        }
        
        big_c->a[i] = err;
        big_s->a[i] = err;
        i++;
        if (sym == '\n')
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        fclose(f);
        return ERR_A_INP;
    }
    if (i == 0)
    {
        fclose(f);
        return ERR_EMPTY_MATRIX;
    }

    if (i > big_c->columns * big_c->rows)
    {
        fclose(f);
        return ERR_AMOUNT_A;
    }
    big_c->len_a = i;
    big_s->len_a = i;

    i = 0;
    flag = 0;
    while (fscanf(f, "%d%c", &err, &sym) == 2)
    {
        if (err >= big_c->rows)
        {
            fclose(f);
            return ERR_AI_INP;
        }
        big_c->ia[i] = err;
        big_s->ia[i] = err;
        i++;
        if (sym == '\n')    
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        fclose(f);
        return ERR_A_INP;
    }

    if (i == 0)
    {
        fclose(f);
        return ERR_EMPTY_MATRIX;
    }

    if (i > big_c->len_a)
    {
        fclose(f);
        return ERR_AMOUNT_IA;
    }

    i = 0;
    flag = 0;
    while (fscanf(f, "%d%c", &err, &sym) == 2)
    {
        if (err >= big_c->columns)
        {
            fclose(f);
            return ERR_AJ_INP;
        }
        big_c->ja[i] = err;
        i++;
        if (sym == '\n')
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        fclose(f);
        return ERR_A_INP;
    }

    if (i == 0)
    {
        fclose(f);
        return ERR_EMPTY_MATRIX;
    }

    if (i > big_c->len_a)
    {
        fclose(f);
        return ERR_AMOUNT_JA;
    }

    i = 0;
    flag = 0;
    while (fscanf(f, "%d%c", &err, &sym) == 2)
    {
        if (!err)
        {
            return ERR_A_INP;
        }
        string_c->a[i] = err;
        i++;
        if (sym == '\n')
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        fclose(f);
        return ERR_A_INP;
    }
    if (i == 0)
    {
        fclose(f);
        return ERR_EMPTY_MATRIX;
    }

    if (i > big_c->columns * big_c->rows)
    {
        fclose(f);
        return ERR_AMOUNT_A_STR;
    }

    string_c->len_a = i;

    i = 0;
    flag = 0;
    while (fscanf(f, "%d%c", &err, &sym) == 2)
    {
        if (err >= string_c->columns)
        {
            fclose(f);
            return ERR_AJ_INP;
        }
        string_c->ja[i] = err;
        string_c->ia[i] = 0;
        i++;
        if (sym == '\n')
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        fclose(f);
        return ERR_A_INP;
    }

    if (i == 0)
    {
        fclose(f);
        return ERR_EMPTY_MATRIX;
    }

    if (i > string_c->len_a)
    {
        fclose(f);
        return ERR_AMOUNT_JA_STR;
    }
    fclose(f);

    return SUCCESS;
}