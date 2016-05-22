#include "static.h"

int hashing (char* name)
{
    int hashValue;

    for ( hashValue = 0; *name != '\0';)
    {
        hashValue += *name++;
    }

    return hashValue % HASH_SIZE;
}

struct hash* createTable ( char* name ) 
{
    struct hash* table;
    int i;

    if ( (table = (struct hash*) malloc ( sizeof (*table))) == NULL )
    {
        error("create table : %s\n", name);
    }
    
    table->offset = 15;
    table->name = name;
    for ( i = 0; i < HASH_SIZE; i++)
    {
        table->list[i] = NULL;
    }
    return table;
}

struct stt* insertStatic ( struct hash* table, char* name, int base, int offset)
{
    int hashValue;
    struct stt* stte;

    if ( (stte = (struct stt*) malloc ( sizeof (*stte))) == NULL )
    {
        error("insert static : %s\n", name);
    }

    hashValue = hashing(name);
    stte->name = name;
    stte->base = base;
    stte->offset = offset;

    stte->next = table->list[hashValue];
    table->list[hashValue] = stte;
    return stte;
}

struct stt* isInHashTable ( struct hash* table, char* name)
{
    struct stt* stte;

    for ( stte = table->list[hashing(name)]; stte != NULL; stte = stte->next)
    {
        if ( strcmp ( name, stte->name ) == 0 )
        {
            return stte;
        }
    }
    return NULL;
}

void printTable (struct hash* table)
{
    struct stt* stte;
    int i;

    printf("\t\t%s\n", table->name);

    for ( i = 0; i < HASH_SIZE; i++ )
    {
        printf("-------table %d -------\n", i);
        for (stte = table->list[i]; stte != NULL; stte = stte->next )
        {
            printf("%s\t%d\t%d\n", stte->name, stte->base, stte->offset);
        }
    }
}

/*
int main()
{
    struct hash* table = createTable("static");
    struct stt* stte;
    stte = insertStatic(table, "class1", 8, 2);
    stte = insertStatic(table, "class2", 8, 2);
    stte = insertStatic(table, "class3", 8, 2);
    stte = insertStatic(table, "class4", 8, 2);

    printTable(table);

    if (isInHashTable (table, "class1"))
    {
        printf("true\n");
    }
    else 
    {
        printf("false\n");
    }

    if (isInHashTable (table, "class5"))
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
