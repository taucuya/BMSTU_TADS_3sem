# Папки:
OBJ_DIR = ./out
SRC_DIR = ./src
INC_DIR = ./INC_DIR

# Настройки компилятора:
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal
INC_FLAGS = -I./inc
# LSUB = -lsubunit
# UNIT_FLAGS = -lcheck -lm $(LSUB)

# Файлы:
SRC_ALL = $(wildcard $(SRC_DIR)/*.c)
SRC_EXEC = $(filter-out time_%, $(SRC_ALL))

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_EXEC))

# Сборка проекта
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $^ $(CFLAGS) $(INC_FLAGS) -o $@ 


app.exe: $(OBJ)
	$(CC) $^ -o $@


vg_exec: app.exe
	valgrind --leak-check=full --log-file="unit_execlog.out" -v ./app.exe

.PHONY: all clean

all: app.exe #unit_tests.exe vg_units

clean:
	rm -f $(OBJ_DIR)/*.o ./app.exe 
