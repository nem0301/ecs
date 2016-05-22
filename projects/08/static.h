#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 11

struct stt {
    char* name;
    int base;
    int offset;
    struct stt* next;
};

struct hash {
    int offset;
    char* name;
    struct stt* list[HASH_SIZE];
};

int hashing (char* name);
struct hash* createTable ( char* name );


struct stt* insertStatic (struct hash* table, char* name, int base, int offset);
struct stt* isInHashTable (struct hash* table, char* name);

void printTable(struct hash* table);
