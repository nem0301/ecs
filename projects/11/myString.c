#include "myString.h"

int subString(char* dst, char* src, int start, int end)
{
    int i, j;
    // this means that outer scope must free memory
    dst = (char*) realloc (dst, end - start + 1); 

    for ( i = start, j = 0; i < end; i++, j++ )
    {   
        *(dst + j) = *(src + i); 
    }   
    
    *(dst + j) = '\0';

    return 0;
}

int stringReplace(char* dst, char* src, char* old, char* new)
{
    int len = strlen ( src );
    int oldLen = strlen ( old );
    int newLen = strlen ( new );
    int deltaLen = newLen - oldLen;
    int i, j = 0, k;

    char* temp = (char*) malloc (1);
    char* result = (char*) malloc (strlen(src) + 1); 

    for ( i = 0; i < len; i++ )
    {
        subString(temp, src, i, i + oldLen);
        if ( strcmp (temp, old) == 0 )
        {
            result = (char*) realloc (result, strlen(result) +  deltaLen + 1);
            i += oldLen - 1;

            for ( j, k=0; k < newLen; k++, j++ )
            {
                *(result + j) = *(new + k);
            }

        }
        else
        {
            *(result + j) = *(src + i);
            j++;
        }
    }

    *(result + j) = '\0';

    dst = (char*) realloc (dst, strlen(result) + 1);
    strcpy(dst, result);

    return 0;
}

int stringAppend(char* dst, char* str)
{
    int dstLen = strlen(dst);
    int strLen = strlen(str);
    int i, j;

    dst = (char*) realloc ( dst, dstLen + strLen + 1 );

    for ( i = dstLen, j = 0; i < dstLen + strLen ; i++, j++ )
    {
        *(dst + i) = *(str + j);
    }
    *(dst + i) = '\0';

    return 0;
}

