/* ====================================================================== */

%{


#define ACCEPT(x) \
{\
    assem_line_no++;\
    if (iter == 0 )\
    {\
        /*printf("%i\t%s\t\t\"%s\"\n", source_line_no, yytext, (char*)x);*/\
    }\
    else if (iter == 1 && strcmp((char*)x, "VARIABLE") == 0)\
    {\
        variable_push(yytext);\
    }\
    else if ( iter == 2 )\
    {\
        if ( strcmp( (char*) x, "A-INST") == 0)\
        {\
            int i;\
            int len = strlen(yytext);\
            char* str = (char*) malloc (len -1);\
            strcp(str, yytext, 1, len);\
            i = atoi(str);\
            padding(i);\
            itob(i);\
            putchar('\n');\
            free(str);\
        }\
        else if ( strcmp ( (char*)x, "PREDEFINED" ) == 0)\
        {\
            int i, j;\
            int len = strlen(yytext);\
            char* str = (char*) malloc (len -1);\
            strcp(str, yytext, 1, len);\
            for (i = 0; i < 23; i++)\
            {\
                if ( strcmp(str, predefined[i][0]) == 0 )\
                {\
                    j = atoi(predefined[i][1]);\
                    padding(j);\
                    itob(j);\
                    putchar('\n');\
                }\
            }\
            free(str);\
        }\
        else if ( strcmp ( (char*)x, "C-INST-A" ) == 0)\
        {\
            instruction(yytext, '0');\
        }\
        else if ( strcmp ( (char*)x, "C-INST-M" ) == 0)\
        {\
            instruction(yytext, '1');\
        }\
        else if ( strcmp ( (char*)x, "JUMP" ) == 0)\
        {\
            jump(yytext);\
        }\
        else if ( strcmp ( (char*)x, "VARIABLE" ) == 0)\
        {\
            variable(yytext);\
        }\
    }\
    else \
    {\
        /*printf("else : %i\t%s\t\t\"%s\"\n", source_line_no, yytext, (char*)x);*/\
    }\
    fflush(stdout); \
}


#define LABEL(x) \
{ \
    if (iter == 0)\
    {\
        label_push(yytext);\
        fflush(stdout);\
    }\
} 

#define LINE_COUNT() \
{ \
    int i=0; \
    char c; \
    while ( (c = *(yytext + i)) != '\0') \
    { \
        if (c == '\n'){ \
            source_line_no++; \
        } \
        i++; \
    } \
    fflush(stdout);\
} 

int iter = 0;
int source_line_no = 1;
int assem_line_no = 0;

int var_addr = 16;

char* predefined[23][2] = {
    {"SP", "0"},
    {"LCL", "1"}, 
    {"ARG", "2"}, 
    {"THIS", "3"}, 
    {"THAT", "4"},
    {"R0", "0"},
    {"R1", "1"},
    {"R2", "2"},
    {"R3", "3"},
    {"R4", "4"},
    {"R5", "5"},
    {"R6", "6"},
    {"R7", "7"},
    {"R8", "8"},
    {"R9", "9"},
    {"R10", "10"},
    {"R11", "11"},
    {"R12", "12"},
    {"R13", "13"},
    {"R14", "14"},
    {"R15", "15"},
    {"SCREEN", "16384"},
    {"KBD", "24576"},
};

char* comp_a[18][2] = {
    {"0",   "101010"},
    {"1",   "111111"},
    {"-1",  "111010"},
    {"D",   "001100"},
    {"A",   "110000"},
    {"!D",  "001101"},
    {"!A",  "110001"},
    {"-D",  "001111"},
    {"-A",  "110011"},
    {"D+1", "011111"},
    {"A+1", "110111"},
    {"D-1", "001110"},
    {"A-1", "110010"},
    {"D+A", "000010"},
    {"D-A", "010011"},
    {"A-D", "000111"},
    {"D&A", "000000"},
    {"D|A", "010101"},
};

char* comp_m[18][2] = {
    {"0",   "101010"},
    {"1",   "111111"},
    {"-1",  "111010"},
    {"D",   "001100"},
    {"M",   "110000"},
    {"!D",  "001101"},
    {"!M",  "110001"},
    {"-D",  "001111"},
    {"-M",  "110011"},
    {"D+1", "011111"},
    {"M+1", "110111"},
    {"D-1", "001110"},
    {"M-1", "110010"},
    {"D+M", "000010"},
    {"D-M", "010011"},
    {"M-D", "000111"},
    {"D&M", "000000"},
    {"D|M", "010101"},
};

char* jmp[8][2] = {
    {"", "000"},
    {"JGT", "001"},
    {"JEQ", "010"},
    {"JGE", "011"},
    {"JLT", "100"},
    {"JNE", "101"},
    {"JLE", "110"},
    {"JMP", "111"},
};

struct int_str {
    int i;
    char* str;
    struct int_str* next;
};

struct int_str* label = NULL;
struct int_str* var = NULL;

void strcp (char* dst, char* src, int start, int end)
{
    int i, j;

    for (j = 0, i = start; i < end; i++, j++)
    {
        dst[j] = src[i];
    }
}

void push (int i, char* str, struct int_str** table)
{
    struct int_str* new = (struct int_str*) malloc (sizeof (struct int_str));
    int len = strlen(str);
    new->i = i;
    new->str = (char*) malloc (len + 1);
    strcpy(new->str, str);

    if (*table == NULL)
    {
        *table = new;
        new->next = NULL;
    }
    else
    {
        new->next = *table;
        *table = new;
    }
}

void print (struct int_str** table)
{
    struct int_str* sel = *table;
    
    while (sel != NULL)
    {
        printf("%d %s\n", sel->i, sel->str);
        sel = sel->next;
    }
}

int check (char* str, struct int_str** table)
{
    struct int_str* sel = *table;
    
    while (sel != NULL)
    {
        if ( strcmp(str, sel->str) == 0 )
        {
            return sel->i;
        }
        
        sel = sel->next;
    }
    return -1;
}

void itob (int i)
{
    if ( i < 2 )
    {
        printf("%d", i);
        return;
    }
    else
    {
        itob(i / 2);
        printf("%d", i % 2);
    }
    
}

void padding (int i)
{
    int temp = 32768;
    
    if ( i == 0 | i == 1 )
    {
        printf("000000000000000");
        return;
    }

    while ( temp > i )
    {
        putchar('0');
        temp /= 2;
    }
}

void instruction (char* inst, char a)
{
    char cinst[17] = {[0 ... 16] = '0'};
    int i = 0;
    int j, k;
    char* str;
    int len = strlen(inst);

    cinst[0] = '1';
    cinst[1] = '1';
    cinst[2] = '1';
    cinst[3] = a;
    cinst[16] = '\0';



    while( *(inst + i) != '=' )
    {
        if ( *(inst + i) == 'A' )
        {
            cinst[10] = '1';
        }
        else if ( *(inst + i) == 'D')
        {
            cinst[11] = '1';
        }
        else if ( *(inst + i) == 'M')
        {
            cinst[12] = '1';
        }
        i++;
    }

    str = (char*) malloc ( len - i + 1);

    strcp (str, inst, i+1, len);

    for ( j = 0; j < 18; j++)
    {
        if ( a == '0' )
        {
            if ( strcmp (str, comp_a[j][0]) == 0 )
            {
                char temp[7];
                strcpy(temp, comp_a[j][1]);
                for ( k = 0; k < 6; k++ )
                {
                    cinst[4 + k] = temp[k];
                }
                break;
            }
        }
        else 
        {
            if ( strcmp (str, comp_m[j][0]) == 0 )
            {
                char temp[7];
                strcpy(temp, comp_m[j][1]);
                for ( k = 0; k < 6; k++ )
                {
                    cinst[4 + k] = temp[k];
                }
                break;
            }
        }
    }


    printf("%s\n", cinst);

    free(str);
}

void jump (char* inst) 
{
    char cinst[17] = {[0 ... 16] = '0'};
    int i = 0;
    int j, k;
    int len = strlen(inst);
    char* str = (char*) malloc ( len - 2 );
    char temp[7];

    strcp(str, inst, 2, len);    

    cinst[0] = '1';
    cinst[1] = '1';
    cinst[2] = '1';
    cinst[16] = '\0';

    if ( *(inst + 0) == '0')
    {
        cinst[3] = '0';
        strcpy(temp, comp_a[0][1]);
        for ( k = 0; k < 6; k++ )
        {
            cinst[4 + k] = temp[k];
        }        
    }
    else if ( *(inst + 0) == 'A')
    {
        cinst[3] = '0';
        strcpy(temp, comp_a[4][1]);
        for ( k = 0; k < 6; k++ )
        {
            cinst[4 + k] = temp[k];
        }
    }
    else if ( *(inst + 0) == 'D')
    {
        cinst[3] = '0';
        strcpy(temp, comp_a[3][1]);
        for ( k = 0; k < 6; k++ )
        {
            cinst[4 + k] = temp[k];
        }
    }
    else if ( *(inst + 0) == 'M')
    {
        cinst[3] = '1';
        strcpy(temp, comp_a[4][1]);
        for ( k = 0; k < 6; k++ )
        {
            cinst[4 + k] = temp[k];
        }
    }


    for ( i = 0; i < 8; i++)
    {
        if ( strcmp( str, jmp[i][0] ) == 0 )
        {
            strcpy(temp, jmp[i][1]);
            for ( k = 0; k < 3; k++ )
            {
                cinst[13 + k] = temp[k];
            }            
        }
    }

    free(str);
    printf("%s\n", cinst);

}

void variable(char* inst)
{
    int addr;
    int chk = 0;
    int len = strlen(inst);
    char* str = (char*) malloc (len);
    
    strcp(str, inst, 1, len);        
    *(str + len - 1) = '\0';

    addr = check(str, &label);    
    
    if (addr == -1){
        chk = 1;
        addr = check(str, &var);    
    }

    if( addr != -1 )
    {
        padding(addr);
        itob(addr);
        putchar('\n');
    }
    else
    {
        printf("%d, %s, %s, no addr\n", chk, str, inst);
    }
    
    free(str);
}

void label_push (char* text)
{
    int len = strlen(text);
    char* str = (char*) malloc (len - 1);
    int i = 1;

    if (str == NULL)
    {
        //printf("fail malloc\n");
    }

    //printf("LABEL: %s\n", str);

    while ( *(text + i) != ')' )
    {
        *(str + i - 1) = *(text + i);
        i++;
    }
    *(str + i -1) = '\0';


    //printf("LABEL: \"%s\", \"%s\", %d\n", str, text, len);
    
    push(assem_line_no, str, &label);
    //printf("%s\n", str);
    free(str);
}

void variable_push (char* text)
{
    int len = (int)strlen(text);
    char* str = (char*) malloc (len);
    strcp(str, text, 1, len);

    *(str + len - 1) = '\0';

    //printf("VAR :%s, %s, %c, %d\n", text, str, *(str + len - 1), len);
    if ( check(str, &label) == -1 && check (str, &var) == -1 )
    {
        push(var_addr, str, &var);
        var_addr++;
    }
    free(str);
}

%}

digit				[0-9]
letter				[a-zA-Z]

whitespace          [\t\r\n ]
comments			"/*"([^*]|(\*[^/]))*"*/"|(\/\/.*\n)
reg1                ("A")?("M")?("D")?
compa               ("&"|"!"|"|")?("+"|"-")?[AD]
compm               ("&"|"!"|"|")?("+"|"-")?[MD]

onez                ("0"|"1"|"+1"|"-1")

jump                [AMD0]";"("JGT"|"JEQ"|"JGE"|"JLT"|"JNE"|"JLE"|"JMP")

%%


"@SP"                            ACCEPT("PREDEFINED");
"@LCL"                           ACCEPT("PREDEFINED");
"@ARG"                           ACCEPT("PREDEFINED");
"@THIS"                          ACCEPT("PREDEFINED");
"@THAT"                          ACCEPT("PREDEFINED");
"@R0"                            ACCEPT("PREDEFINED");
"@R1"                            ACCEPT("PREDEFINED");
"@R2"                            ACCEPT("PREDEFINED");
"@R3"                            ACCEPT("PREDEFINED");
"@R4"                            ACCEPT("PREDEFINED");
"@R5"                            ACCEPT("PREDEFINED");
"@R6"                            ACCEPT("PREDEFINED");
"@R7"                            ACCEPT("PREDEFINED");
"@R8"                            ACCEPT("PREDEFINED");
"@R9"                            ACCEPT("PREDEFINED");
"@R10"                           ACCEPT("PREDEFINED");
"@R11"                           ACCEPT("PREDEFINED");
"@R12"                           ACCEPT("PREDEFINED");
"@R13"                           ACCEPT("PREDEFINED");
"@R14"                           ACCEPT("PREDEFINED");
"@R15"                           ACCEPT("PREDEFINED");
"@SCREEN"                        ACCEPT("PREDEFINED");
"@KBD"                           ACCEPT("PREDEFINED");


{jump}                          ACCEPT("JUMP");
{reg1}"="(({compa}|{onez})|{compa}({compa}|{onez})) ACCEPT("C-INST-A");
{reg1}"="(({compm}|{onez})|{compm}({compm}|{onez})) ACCEPT("C-INST-M");

@{digit}{digit}*			    ACCEPT("A-INST");
@([^\t\n\r ]*)                  ACCEPT("VARIABLE");

"("([^\t\n\r ]*)")"             LABEL("LABEL");



{comments}							LINE_COUNT();
{whitespace}						LINE_COUNT();


.					ACCEPT("UNDEFINED");

%%

/* ====================================================================== */
#include <fcntl.h>


int main(int argc, char *argv[])
{
    int fd;
    int temp;

    if(argc != 2) {
        fprintf(stderr, "usage: scanner file\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        fprintf(stderr, "%s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    yylex();
    
    source_line_no = 1;
    assem_line_no = 0;
    var_addr = 16;
    iter = 1;
    yyin = fopen(argv[1], "r");
    yylex();


    source_line_no = 1;
    assem_line_no = 0;
    var_addr = 16;
    iter = 2;
    yyin = fopen(argv[1], "r");

    int i = 0;
    int len = strlen(argv[1]);
    char* fname = (char*) malloc (len + 2);

    strcpy(fname, argv[1]);

    while( *(fname + i) != '.' )
    {
        i++;
    }
    i++;
    *(fname + i) = 'h';
    i++;
    *(fname + i) = 'a';
    i++;
    *(fname + i) = 'c';
    i++;
    *(fname + i) = 'k';
    i++;
    *(fname + i) = '\0';

    fd = open(fname, O_CREAT|O_WRONLY, 0664);
    close(1);
    temp = dup(fd);

    yylex();


    free(fname);

    return 0;
}

