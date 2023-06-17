CC=gcc
CFLAGS=-I../include
BUILD_DIR=./
SRC_DIR=../src
FILES=$(SRC_DIR)/Main.c $(SRC_DIR)/Token.c $(SRC_DIR)/Util.c $(SRC_DIR)/Lexer.c $(SRC_DIR)/Tokenizer.c
OUTPUT_NAME=$(BUILD_DIR)/porg

Compile:
	$(CC) $(CFLAGS) $(FILES) -o $(OUTPUT_NAME).exe

Test:
	gcc tect.c -o test.exe