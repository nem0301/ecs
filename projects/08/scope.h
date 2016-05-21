
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef SCOPE_H
#define SCOPE_H

#define VM 1
#define FUNC 2

struct scope {
    int type;
    char* string;
    struct scope* next;
    struct scope* prev;
};

struct queue {
    struct scope* front;
    struct scope* rear;
};

void initScopeQueue ( struct queue** q );

void pushScope ( struct queue** q, int type, char* string );
void popScope ( struct queue** q);

void printScope( struct queue** q, char* label);

#endif
