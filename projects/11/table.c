
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 11

#define CLASS_KIND 0
#define FIELD_KIND 1
#define STATIC_KIND 2
#define ARGUMENT_KIND 3
#define LOCAL_KIND 4
#define CONSTRUCTOR_KIND 5
#define FUNCTION_KIND 6
#define METHOD_KIND 7;

#define BOOLEAN_TYPE 0
#define VOID_TYPE 1
#define INT_TYPE 2
#define CHAR_TYPE 3
#define CLASS_TYPE 4
#define OBJECT_TYPE 5

char *kind_list[] = {
    "class",
    "field",
    "static",
    "argument",
    "local",
    "constructor",
    "function",
    "method",
    "",
};

char *type_list[] = {
    "boolean",
    "void",
    "int",
    "char",
    "class",
    "object",
    "",
};


struct symbol {
    char *name;
    unsigned char kind;
    unsigned char type;
    unsigned int num;
    char *type_name;
    struct symbol *next;
};

struct table {
    int offset;
    char *name;
    struct symbol *list[HASH_SIZE];
};

struct table *global_table;
struct table *local_table;
struct table *current_table;


int hashing (char *name)
{
    int hashValue;

    for ( hashValue = 0; *name != '\0';)
    {
        hashValue += *name++;
    }

    return hashValue % HASH_SIZE;
}

struct table *createTable ( char *name ) 
{
    struct table *tb;
    int i;

    if ( (tb = (struct table*) malloc ( sizeof (*tb))) == NULL )
    {
        error("create table : %s\n", name);
    }
    
    tb->offset = 15;
    tb->name = name;
    for ( i = 0; i < HASH_SIZE; i++)
    {
        tb->list[i] = NULL;
    }
    return tb;
}

struct symbol *insertTable (struct table *tb,
                            char *name,
                            unsigned char kind,
                            unsigned char type,
                            unsigned int num,
                            char *type_name)
{
    struct symbol *symbole = (struct symbol*) malloc (sizeof(struct symbol));
    int hashValue;

    
    //symbole->name = (char*) malloc (strlen(name) + 1);
    //strcpy(symbole->name, name);
    symbole->name = name;
    symbole->kind = kind;
    symbole->num = num;
    symbole->type = type;

    if ( type == OBJECT_TYPE )
    {
        symbole->type_name = type_name;
    }

    hashValue = hashing(symbole->name);

    symbole->next = tb->list[hashValue];
    tb->list[hashValue] = symbole;
    return symbole;
}

struct symbol *isInHashTable ( struct table *tb, char *name)
{
    struct symbol *symbole;

    for ( symbole = tb->list[hashing(name)]; symbole != NULL; symbole = symbole->next)
    {
        if ( strcmp ( name, symbole->name ) == 0 )
        {
            return symbole;
        }
    }
    return NULL;
}

struct symbol *lookupTable (char* name)
{
    struct symbol *symbole;
    if ( (symbole = isInHashTable ( current_table, name )) != NULL )
    {
        return symbole;
    }
    else
    {
        return isInHashTable (global_table, name);
    }
}

void printTable (struct table *tb)
{
    struct symbol *symbole;
    int i;

    printf("\t\t%s\n", tb->name);

    printf("---------- ---------- ---------- ---------- ----------\n");

    for ( i = 0; i < HASH_SIZE; i++ )
    {
        for (symbole = tb->list[i]; symbole != NULL; symbole = symbole->next )
        {
            printf("%-10s %-10s %-10s %-10s %10d\n", 
                symbole->name,
                kind_list[symbole->kind],
                type_list[symbole->type], 
                symbole->type_name,
                symbole->num);
                                    
        }
    }
    printf("---------- ---------- ---------- ---------- ----------\n");
}
/*
int main()
{
    struct table *g_table = createTable("static");
    struct symbol *symbole;
    symbole = insertTable(g_table, "class1", 8, 2);
    symbole = insertTable(g_table, "class2", 8, 2);
    symbole = insertTable(g_table, "class3", 8, 2);
    symbole = insertTable(g_table, "class4", 8, 2);

    printTable(g_table);

    if (isInHashTable (g_table, "class1"))
    {
        printf("true\n");
    }
    else 
    {
        printf("false\n");
    }

    if (isInHashTable (g_table, "class5"))
    {
        printf("true\n");
    }
    else 
    {
        printf("false\n");
    }
    return 0;
}
*/
