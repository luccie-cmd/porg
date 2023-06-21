CC=gcc
CFLAGS=-I./include -I../common -Wall -Wextra
BUILD_DIR=../build/porg
SRC_DIR=./src
FILES=$(SRC_DIR)/Main.c $(SRC_DIR)/Token.c $(SRC_DIR)/Util.c $(SRC_DIR)/Lexer.c $(SRC_DIR)/Tokenizer.c $(SRC_DIR)/ByteBuffer.c $(SRC_DIR)/Compiler.c
OUTPUT_NAME=$(BUILD_DIR)/porg

porg:
	$(CC) $(CFLAGS) $(FILES) -o $(OUTPUT_NAME).exe