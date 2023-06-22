#include "Util.h"

int registers[4] = {
    [REG_EAX] = 0,
    [REG_EBX] = 0,
    [REG_ECX] = 0,
    [REG_EDX] = 0,
};

char *readFile(const char * path){
    FILE* file = fopen(path, "rb"); // make file object
    if(!file){
        fprintf(stderr, "Could not make file\n");
        exit(1);
    }

    // get the length of the file
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    // make buffer and read file
    char* buffer = malloc(length+1);
    if(!fread(buffer, 1, length, file)){
        fprintf(stderr, "Could not read file\n");
        free(buffer);
        return NULL;
    }
    buffer[length] = '\0';
    // return
    return buffer;
}

int getRegisterFromName(char *name){
    // Remove the newline character, if present
    size_t length = strlen(name);
    if (length > 0 && name[length-1] == '\n') {
        printf("Stripping new line\n");
        name[length] = '\0';
    }
    if(strcmp(name, "eax") == 0){
        return REG_EAX;
    } else if(strcmp(name, "ebx") == 0){
        return REG_EBX;
    } else if(strcmp(name, "ecx") == 0){
        return REG_ECX;
    } else if(strcmp(name, "edx") == 0){
        return REG_EDX;
    } else{
        printf("Invalid register named %s\n", name);
        exit(1);
    }
    return -1;
}
int getNumberFromName(char * name){
    return atoi(name);
}
void chopFirstChar(char *str) {
    if (str != NULL && *str != '\0') {
        char *newStr = str + 1;  // Increment the pointer by one to skip the first character
        strcpy(str, newStr);    // Copy the modified string back to the original memory location
    }
}
void chopLastCharOfRegister(char *str) {
    if(str[strlen(str)-1] == 'x'){
        return;
    }
    if (str == NULL || *str == '\0') {
        // Handle empty string or null pointer
        return;
    }

    int length = strlen(str);
    if (length > 0) {
        str[length - 1] = '\0';
    }
}
uint8_t* readBinFile(const char *path){
    FILE* file = fopen(path, "rb");
	if (!file) {
		printf("Could not open file '%s'\n", path);
		return 0;
	}

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);

	uint8_t* buffer = (uint8_t*) malloc(sizeof(uint8_t) * size);
	fread(buffer, 1, size, file);
	fclose(file);
    return buffer;
}
void writeBinFile(const char *file, ByteBuffer bb)
{
    FILE* f = fopen(file, "wb");
    if(!f){
        printf("could not make file for %s\n", file);
        return;
    }
    fwrite(bb.buffer, 1, bb.buffer_len, f);
	fclose(f);
}

// used from https://github.com/tsoding/bm/blob/master/common/path.c line: 119
char* shift(int* argc, char*** argv){
    assert(*argc > 0);
    char *result = **argv;
    *argv += 1;
    *argc -= 1;
    return result;
}