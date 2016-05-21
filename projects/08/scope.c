#include "scope.h"

void initScopeQueue(struct queue** q)
{
    (*q)->front = NULL;
    (*q)->rear = NULL;
}

void pushScope ( struct queue** q, int type, char* string )
{
    struct scope* new = (struct scope*) malloc ( sizeof(struct scope) );

    new->type = type;
    new->string = (char*) malloc ( strlen(string) + 1 );
    strcpy(new->string, string);
    new->next = NULL;

    if ( (*q)->rear == NULL )
    {

        (*q)->rear = new;
        (*q)->front = new;
        new->prev = NULL;
    }
    else
    {
        new->prev = (*q)->rear;
        (*q)->rear->next = new;
        (*q)->rear = new;
    }
}

void popScope (struct queue** q)
{
    struct scope* temp = (*q)->rear;

    (*q)->rear = (*q)->rear->prev;

    free(temp);
}

void printScope (struct queue** q, char* label)
{
    struct scope* sel = (*q)->front;

    putchar('(');
    while ( sel != NULL )
    {
        if ( sel->type == VM )
        {
            printf("%s.", sel->string);
        }
        else if ( sel->type == FUNC )
        {
            printf("%s:", sel->string);
        }
        sel = sel->next;
    }

    printf("%s", label);
    putchar(')');
    putchar('\n');

/*
    printf("(%s:%s)\n", sel->string, label);
    */
}
