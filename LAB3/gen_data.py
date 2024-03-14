import random

rows = int(input("Введите количество строк: "))
columns = int(input("Введите количество столбцов: "))
fill_percent = int(input("Введите процент заполнения матрицы ненулевыми элементами: "))
filename = input("Введите название файла для записи: ")

non_zero = int(rows * columns * fill_percent / 100)

matrix = [[0 for j in range(columns)] for i in range(rows)]

indexes = set() 
while len(indexes) < non_zero:
    row = random.randint(0, rows-1)
    column = random.randint(0, columns-1)
    index = (column, row)
    if index not in indexes:
        indexes.add(index)
        value = random.randint(1, 10)
        matrix[row][column] = value


a = []
b = []

with open(filename, "w") as f:
    f.write(f"{rows} {columns}\n")
    for i in range(columns):
        for j in range(rows):
            if matrix[j][i] != 0:
                f.write(f"{matrix[j][i]} ")
                a.append(j)
                b.append(i)

    f.write("\n")
    for i in range(len(a)):
        if i == (len(a) - 1):
            f.write(f"{a[i]}")
        else:
            f.write(f"{a[i]} ")
    f.write("\n")
    for j in range(len(b)):
        if j == (len(b) - 1):
            f.write(f"{b[j]}")
        else:
            f.write(f"{b[j]} ")
    f.write("\n")
    for i in range(rows):
        if i == (rows - 1):
            f.write(f"{i + 1}")
        else:
            f.write(f"{i + 1} ")
    f.write("\n")
    for i in range(rows):
        if i == (rows - 1):
            f.write(f"{i}")
        else:
            f.write(f"{i} ")
    f.write("\n")

