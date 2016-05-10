/* ====================================================================== */

%{
#define C_ARITHMETIC    0
#define C_PUSH          1
#define C_POP           2
#define C_LABEL         3
#define C_GOTO          4
#define C_IF            5
#define C_FUNCTION      6
#define C_RETURN        7
#define C_CALL          8
#define C_UNDEFINED     9

#define ACCEPT(x) { accept((int)x, yytext); fflush(stdout); }

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

char* type[10] = {
    "C_ARITHMETIC",
    "C_PUSH",
    "C_POP",
    "C_LABEL",
    "C_GOTO",
    "C_IF",
    "C_FUNCTION",
    "C_RETURN",
    "C_CALL",
    "C_UNDEFINED",
};

int source_line_no = 1;

int eq = 0;
int lt = 0;
int gt = 0;

void untitle (int cmd, char* REG, int index)
{
    //printf("%s,       %s,         ,%d\n", type[cmd], REG, index);
    printf("@%d\n", index);
    printf("D=A\n");

    printf("%s\n", REG);
    printf("D=D+M\n");          
    printf("@i\n");
    printf("M=D\n");            //i = *(@REG) + index;

    if ( cmd == C_POP )
    {               

        printf("@SP\n");
        printf("AM=M-1\n");
        printf("D=M\n");            //D = pop();
        
        printf("@i\n");
        printf("A=M\n");
        printf("M=D\n");            //M[i] = D;
    }
    else 
    {
        printf("@i\n");
        printf("A=M\n");
        printf("D=M\n");            //D = M[i];

        printf("@SP\n");
        printf("A=M\n");
        printf("M=D\n");
        printf("@SP\n");
        printf("M=M+1\n");          //push(D);
    }
}

void pushAndPop (int cmd, char* segment, int index)
{
    //printf("%s,\t%s,\t%d\n", type[cmd], segment, index);

    if ( strcmp(segment, "argument") == 0 )
    {
        untitle(cmd, "@ARG", index);
    }
    else if ( strcmp(segment, "local") == 0 )
    {
        untitle(cmd, "@LCL", index);
    }
    else if ( strcmp(segment, "static") == 0 )
    {
        printf("@%d\n", 16 + index);
        
        if ( cmd == C_POP )
        {
            printf("@SP\n");
            printf("AM=M-1\n");
            printf("D=M\n");

            printf("M=D\n");
        }
        else 
        {
            printf("D=M\n");

            printf("@SP\n");
            printf("A=M\n");
            printf("M=D\n");
            printf("@SP\n");
            printf("M=M+1\n");
        }
    }
    else if ( strcmp(segment, "constant") == 0 )
    {
        printf("@%d\n", index);

        printf("D=A\n");
        printf("@SP\n");
        printf("A=M\n");
        printf("M=D\n");
        printf("@SP\n");
        printf("M=M+1\n");
    }
    else if ( strcmp(segment, "this") == 0 )
    {
        untitle(cmd, "@THIS", index);
    }
    else if ( strcmp(segment, "that") == 0 )
    {
        untitle(cmd, "@THAT", index);
    }
    else if ( strcmp(segment, "pointer") == 0 )
    {
        if ( cmd == C_POP )
        {
            printf("@SP\n");
            printf("AM=M-1\n");
            printf("D=M\n");

            if ( index == 0 ) 
            {
                printf("@THIS\n");
                printf("M=D\n");
            }
            else 
            {
                printf("@THAT\n");
                printf("M=D\n");
            }
        }
        else
        {
            if ( index == 0 ) 
            {
                printf("@THIS\n");
                printf("D=M\n");
            }
            else 
            {
                printf("@THAT\n");
                printf("D=M\n");
            }

            printf("@SP\n");
            printf("A=M\n");
            printf("M=D\n");
            printf("@SP\n");
            printf("M=M+1\n");
        }
    }
    else if ( strcmp(segment, "temp") == 0 )
    {
        printf("@%d\n", 5 + index);
        printf("D=A\n");
        printf("@i\n");
        printf("M=D\n");
        
        if ( cmd == C_POP )
        {
            printf("@SP\n");
            printf("AM=M-1\n");
            printf("D=M\n");
            
            
            printf("@i\n");
            printf("A=M\n");
            printf("M=D\n");
        }
        else 
        {
            printf("@i\n");
            printf("A=M\n");
            printf("D=M\n");

            printf("@SP\n");
            printf("A=M\n");
            printf("M=D\n");
            printf("@SP\n");
            printf("M=M+1\n");
        }
    }

}

void accept(int token, char* lexeme)
{
    char* ctx = NULL;
    char* tok;
    char* str;
    //printf("%d,\t%s,\t\'%s\'\n", source_line_no, type[token], lexeme);
    //printf("%s\n", lexeme);
    if ( token == C_ARITHMETIC )
    {
        if ( strcmp(lexeme, "add") == 0 )
        {
            pushAndPop(C_POP, "temp", 0);
            pushAndPop(C_POP, "temp", 1);           
            printf("@R5\n");
            printf("M=D+M\n");
            pushAndPop(C_PUSH, "temp", 0);
            
        }
        else if ( strcmp(lexeme, "sub") == 0 )
        {
            pushAndPop(C_POP, "temp", 0);
            pushAndPop(C_POP, "temp", 1);           
            printf("@R5\n");
            printf("M=D-M\n");
            pushAndPop(C_PUSH, "temp", 0);
        }
        else if ( strcmp(lexeme, "and") == 0 )
        {
            pushAndPop(C_POP, "temp", 0);
            pushAndPop(C_POP, "temp", 1);           
            printf("@R5\n");
            printf("M=D&M\n");
            pushAndPop(C_PUSH, "temp", 0);
        }
        else if ( strcmp(lexeme, "or") == 0 )
        {
            pushAndPop(C_POP, "temp", 0);
            pushAndPop(C_POP, "temp", 1);           
            printf("@R5\n");
            printf("M=D|M\n");
            pushAndPop(C_PUSH, "temp", 0);
        }
        else if ( strcmp(lexeme, "not") == 0 )
        {
            pushAndPop(C_POP, "temp", 0);
            printf("@R5\n");
            printf("M=!M\n");
            pushAndPop(C_PUSH, "temp", 0);
        }
        else if ( strcmp(lexeme, "neg") == 0 )
        {
            pushAndPop(C_POP, "temp", 0);
            printf("@R5\n");
            printf("M=-M\n");
            pushAndPop(C_PUSH, "temp", 0);
        }
           }
    else if ( token == C_PUSH | token == C_POP )
    {   
        char* seg;
        int ind;
        int cnt = 0;

        str = (char*) malloc (strlen(lexeme) + 1);
        strcpy(str, lexeme);

        tok = strtok_r(str, " ", &ctx);
        while( tok ) 
        {
            int len = strlen(tok);
            //printf("%s, %d\n", tok, (int)strlen(tok));
            switch (cnt) 
            {
                case 1:
                    seg = (char*) malloc (len + 1);
                    strcpy(seg, tok);
                    break;
                case 2:
                    ind = atoi(tok);
                    break;
            }
            
            tok = strtok_r(NULL, " ", &ctx);
            cnt++;
        }

        pushAndPop ( token, seg, ind );

        free(str);
        free(seg);
    }
    else if ( token == C_IF )
    { 
        if ( strcmp(lexeme, "eq") == 0 )
        {   
            pushAndPop(C_POP, "temp", 0);
            pushAndPop(C_POP, "temp", 1);           
            printf("@R5\n");
            printf("D=D-M\n");
            printf("@EQ%d\n", eq);
            printf("D;JEQ\n");


            printf("@0\n");
            printf("D=A\n");
            printf("@R5\n");
            printf("M=D\n");
            pushAndPop(C_PUSH, "temp", 0);

            printf("@EQEND%d\n", eq);
            printf("0;JMP\n");

            printf("(EQ%d)\n", eq);

            
            printf("@0\n");
            printf("D=A\n");
            printf("D=!D\n");
            printf("@R5\n");
            printf("M=D\n");
            pushAndPop(C_PUSH, "temp", 0);

            printf("(EQEND%d)\n", eq);

            eq++;
        }
        else if ( strcmp(lexeme, "lt") == 0 )
        {   
            pushAndPop(C_POP, "temp", 0);
            pushAndPop(C_POP, "temp", 1);           
            printf("@R5\n");
            printf("D=D-M\n");
            printf("@LT%d\n", lt);
            printf("D;JLT\n");

            printf("@0\n");
            printf("D=A\n");
            printf("@R5\n");
            printf("M=D\n");
            pushAndPop(C_PUSH, "temp", 0);

            printf("@LTEND%d\n", lt);
            printf("0;JMP\n");

            printf("(LT%d)\n", lt);

            printf("@0\n");
            printf("D=A\n");
            printf("D=!D\n");
            printf("@R5\n");
            printf("M=D\n");
            pushAndPop(C_PUSH, "temp", 0);

            printf("(LTEND%d)\n", lt);

            lt++;
        }
        else if ( strcmp(lexeme, "gt") == 0 )
        {   
            pushAndPop(C_POP, "temp", 0);
            pushAndPop(C_POP, "temp", 1);           
            printf("@R5\n");
            printf("D=D-M\n");
            printf("@GT%d\n", gt);
            printf("D;JGT\n");

            printf("@0\n");
            printf("D=A\n");
            printf("@R5\n");
            printf("M=D\n");
            pushAndPop(C_PUSH, "temp", 0);

            printf("@GTEND%d\n", gt);
            printf("0;JMP\n");

            printf("(GT%d)\n", gt);

            printf("@0\n");
            printf("D=A\n");
            printf("D=!D\n");
            printf("@R5\n");
            printf("M=D\n");
            pushAndPop(C_PUSH, "temp", 0);

            printf("(GTEND%d)\n", gt);

            gt++;
        }

    }
}

%}
whitespace          [\t\r\n ]
comments            "/*"([^*]|(\*[^/]))*"*/"|(\/\/.*\n)
arithmetic          "add"|"sub"|"neg"|"and"|"or"|"not"
digit				[0-9]
letter				[a-zA-Z]

%%

"push"[^\t\n\r]*        ACCEPT(C_PUSH);
"pop"[^\t\n\r]*         ACCEPT(C_POP);
"eq"|"lt"|"gt"          ACCEPT(C_IF);
{arithmetic}            ACCEPT(C_ARITHMETIC);


{comments}              LINE_COUNT();
{whitespace}            LINE_COUNT();

.                       ACCEPT(C_UNDEFINED);



%%

/* ====================================================================== */

#include <fcntl.h>

/*
void init ()
{
    printf("@256\n");
    printf("D=A\n");
    printf("@SP\n");
    printf("M=D\n");
}
*/


int main(int argc, char *argv[])
{
    int fd, i = 0;
    char* fname;
    if(argc != 2) {
        fprintf(stderr, "usage: scanner file\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        fprintf(stderr, "%s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    fname = (char*) malloc ( strlen(argv[1]) + 2 );
    strcpy ( fname, argv[1] );
    while ( *(fname + i) != '.' )
    {
        i++;
    }
    i++;
    *(fname + i) = 'a';
    i++;
    *(fname + i) = 's';
    i++;
    *(fname + i) = 'm';
    i++;
    *(fname + i) = '\0';

    remove(fname);

    fd = open ( fname, O_CREAT | O_WRONLY, 0664 );
    close(1);
    fd = dup(fd);
    
    yylex();

    printf("(END)\n");
    printf("@END\n");
    printf("0;JMP\n");

    free(fname);

    return 0;
}

/* ====================================================================== */
