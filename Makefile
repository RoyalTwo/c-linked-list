SRC_DIR := src/
OUT_DIR := bin/
IN_FILES := *.c
OUT_NAME := main

main: $(SRC_DIR)main.c
	clang $(SRC_DIR)${IN_FILES} -g -Ilib/ -o $(OUT_DIR)$(OUT_NAME)
