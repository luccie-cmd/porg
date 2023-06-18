#include "Util.h"

int registers[4] = {
    [REG_EAX] = 0,
    [REG_EBX] = 0,
    [REG_ECX] = 0,
    [REG_EDX] = 0,
};

char * readFile(const char * path){
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
void writeBinFile(const char* file, ByteBuffer bb){}