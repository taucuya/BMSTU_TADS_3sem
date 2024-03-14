OBJ_DIR = ./out
SRC_DIR = ./src
INC_DIR = ./inc
UNIT_DIR = ./unit_tests
FUNC_DIR = ./func_tests

CC = gcc
CFLAGS = -std=c99 -Wall -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal
INC_FLAGS = -I./inc
LSUB = -lsubunit
UNIT_FLAGS = -lcheck -lm $(LSUB)

SRC_ALL = $(wildcard $(SRC_DIR)/*.c)
SRC_EXEC = $(filter-out time_%, $(SRC_ALL))

SRC_CHECK = $(wildcard $(UNIT_DIR)/*.c)
SRC_TIME = $(wildcard $(SRC_DIR)/time_*.c)

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_EXEC))
OBJ_UNIT = $(patsubst $(UNIT_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_CHECK))
OBJ_TIME = $(patsubst $(SRC_DIR)/%.c,  $(OBJ_DIR)/%.o, $(SRC_TIME))


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c	 
	$(CC) -c $^ $(CFLAGS) $(INC_FLAGS) -o $@ 


$(OBJ_DIR)/%.o: $(UNIT_DIR)/%.c
	$(CC) -c $^ $(CFLAGS) $(INC_FLAGS) -o $@ 

app.exe: $(OBJ)
	$(CC) $^ -o $@

unit_tests.exe: $(OBJ_UNIT) ./out/add.o ./out/make_square.o ./out/mult.o
	$(CC) -o $@ $^ $(UNIT_FLAGS)

vg_units: unit_tests.exe
	valgrind --leak-check=full --show-leak-kinds=all --show-leak-kinds=all --log-file="unit_vglog.out" -v ./unit_tests.exe 

vg_exec: app.exe
	valgrind --leak-check=full --log-file="unit_execlog.out" -v ./app.exe < file_in2.txt

.PHONY: all clean

all: app.exe unit_tests.exe vg_units

clean:
	rm -f $(OBJ_DIR)/*.o ./app.exe ./unit_tests.exe
