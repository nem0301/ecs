
#include <stdlib.h>
#include <string.h>

#ifdef MY_STRING_H
#define MY_STRING_H

int subString(char* dst, char* src, int start, int end);
int stringReplace(char* dst, char* src, char* old, char* new);
int stringAppend(char* dst, char* str);

#endif
