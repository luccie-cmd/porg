SRC_DIR=./src
PORG_DIR=../porg
CC=gcc
CFLAGS=-I./include -I$(PORG_DIR)/include
BUILD_DIR=../build
FILES=$(SRC_DIR)/*.c $(PORG_DIR)/src/ByteBuffer.c
OUTPUT_NAME=$(BUILD_DIR)/porgo

porgo:
	$(CC) $(CFLAGS) $(FILES) -o $(OUTPUT_NAME).exe