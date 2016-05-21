/* ====================================================================== */

%{
#include "myString.h"
#include "scope.h"

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

char opt = '0';
int source_line_no = 1;

int eq = 0;
int lt = 0;
int gt = 0;

int return_address = 0;

char* scope;

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

//dst = *(addr - i)
void assignFromAddr (char* dst, char* addr, int i)
{
    printf("@%d\n", i);         //A = i
    printf("D=A\n");            //D = A; D = i
    printf("@%s\n", addr);      //A = &addr
    printf("A=M-D\n");          //A = M[A] - D; A = addr - i;
    printf("D=M\n");            //D = M[A]; D = *(addr - i)
    
    printf("@%s\n", dst);       //A = &dst
    printf("M=D\n");            //M[A] = D; dst = *(addr - i);
}

//push(regi)
void pushRegister (char* regi)
{
    printf("@%s\n", regi);          //A = &regi
    printf("D=M\n");                //D = M[A]; D = regi

    printf("@SP\n");                
    printf("A=M\n");
    printf("M=D\n");                //*(SP) = regi
    printf("@SP\n");
    printf("M=M+1\n");              //SP = SP + 1
}

void accept(int token, char* lexeme)
{
    char* ctx = NULL;
    char* tok;
    char* str;
    
    if (opt == 't') 
    {
        printf("%d,\t%s,\t\'%s\'\n", source_line_no, type[token], lexeme);
        //printf("%s\n", lexeme);
        //return;
    }
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
    else if ( token == C_LABEL )
    {   
        str = (char*) malloc (strlen(lexeme) + 1);
        strcpy(str, lexeme);

        tok = strtok_r(str, " ", &ctx);
        tok = strtok_r(NULL, " ", &ctx);

        if ( scope != NULL ) 
        {
            printf("(%s:%s)\n", scope, tok);
            //printScope( &scopeQueue, tok );
        }
        else
        {
            printf("(%s)\n", tok);
        }


        //printf("(%s)\n", tok);

        free(str);
    }
    else if ( token == C_GOTO)
    {   
        str = (char*) malloc (strlen(lexeme) + 1);
        strcpy(str, lexeme);

        tok = strtok_r(str, " ", &ctx);

        if ( strcmp(tok, "goto") == 0 )
        {
            tok = strtok_r(NULL, " ", &ctx);

            if ( scope != NULL ) 
            {
                printf("@%s:%s\n", scope, tok);
            }
            else 
            {
                printf("@%s\n", tok);
            }
            printf("0;JMP\n");
        }
        else 
        {
            tok = strtok_r(NULL, " ", &ctx);

            printf("@SP\n");
            printf("AM=M-1\n");
            printf("D=M\n");

            if ( scope != NULL ) 
            {
                printf("@%s:%s\n", scope, tok);
            }
            else 
            {
                printf("@%s\n", tok);
            }
            printf("D;JNE\n");

        }

        free(str);
    }
    else if ( token == C_FUNCTION )
    {   
        char* func;
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
                    func = (char*) malloc (len + 1);
                    strcpy(func, tok);
                    break;
                case 2:
                    ind = atoi(tok);
                    break;
            }
            
            tok = strtok_r(NULL, " ", &ctx);
            cnt++;
        }

        printf("(%s)\n", func);
        
        while ( ind-- > 0)
        {
            pushAndPop(C_PUSH, "constant", 0);
        }

        if ( scope != NULL )
        {
            free (scope);
        }
        scope = (char*) malloc (strlen(func) + 1);
        strcpy(scope, func);

        

        free(str);
        free(func);
    }
    else if ( token == C_RETURN )
    {
        printf("@LCL\n");                   //A = &LCL
        printf("D=M\n");                    //D = M[A]; D = LCL
        printf("@frame\n");                 //A = &frame
        printf("M=D\n");                    //M[A] = D; frame = LCL

        //ret = *(frame - 5)
        assignFromAddr("ret", "frame", 5);

        //*arg = pop()
        pushAndPop(C_POP, "argument", 0);

        //sp = arg + 1
        printf("@ARG\n");                   //A = &ARG
        printf("D=M\n");                    //D = M[A]; D = ARG
        printf("@SP\n");                    //A = &SP
        printf("M=D+1\n");                  //M[A] = D + 1; SP = ARG + 1
        
        //that = *(frame - 1);
        assignFromAddr("THAT", "frame", 1);
        //this = *(frame - 2);
        assignFromAddr("THIS", "frame", 2);
        //arg = *(frame - 3);
        assignFromAddr("ARG", "frame", 3);
        //lcl = *(frame - 4);
        assignFromAddr("LCL", "frame", 4);

        printf("@ret\n");                   //A = &ret
        printf("A=M\n");                    //A = M[A]; A = ret
        printf("0;JMP\n");                  //jump to A; jump to ret

        if ( scope != NULL )
        {
            free(scope);
        }

    }
    else if ( token == C_CALL )
    {

        // push return-address
        printf("@return_address%d\n", return_address);  // A = &retrun_address
        printf("D=A\n");                                // D = A; D = &return_addr

        printf("@SP\n");                                // A = &SP
        printf("A=M\n");                                // A = M[A]; A = SP
        printf("M=D\n");                                // M[A] = D; *(SP) = &ret
        printf("@SP\n");                                // A = &SP
        printf("M=M+1\n");                              // M[A] = M[A] + 1; SP=SP+1

        // push address of others

        pushRegister("LCL");
        pushRegister("ARG");
        pushRegister("THIS");
        pushRegister("THAT");
        
        // parsing lexeme f and n
        char* func;
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
                    func = (char*) malloc (len + 1);
                    strcpy(func, tok);
                    break;
                case 2:
                    ind = atoi(tok);
                    break;
            }
            
            tok = strtok_r(NULL, " ", &ctx);
            cnt++;
        }

        // configure ARG and LCL
        // ARG = SP - ( n + 5 )
        printf("@SP\n");            //A = &SP
        printf("D=M\n");            //D = M[A]; D = SP
        printf("@%d\n", ind + 5);   //A = ind + 5
        printf("D=D-A\n");          //D = D - A; SP = SP - (ind + 5)
        printf("@ARG\n");           //A = &ARG
        printf("M=D\n");            //M[A] = D; ARG = SP - (ind + 5)

        // LCL = SP
        printf("@SP\n");
        printf("D=M\n");
        printf("@LCL\n");
        printf("M=D\n");
        
        printf("@%s\n", func);
        printf("0;JMP\n");

       
        // return label
        printf("(return_address%d)\n", return_address);
        return_address++;
    }


}

%}
whitespace          [\t\r\n ]
comments            "/*"([^*]|(\*[^/]))*"*/"|(\/\/.*\n)
arithmetic          "add"|"sub"|"neg"|"and"|"or"|"not"
digit				[0-9]
letter				[a-zA-Z]

%%


"push "{letter}{letter}*" "{digit}{digit}*  ACCEPT(C_PUSH);
"pop "{letter}{letter}*" "{digit}{digit}*   ACCEPT(C_POP);
"eq"|"lt"|"gt"                              ACCEPT(C_IF);
("if-goto "|"goto ")(([.:_])?{letter}({digit}|{letter})*)+  ACCEPT(C_GOTO);
("label ")(([.:_])?{letter}({digit}|{letter})*)+            ACCEPT(C_LABEL);
("function ")({letter})({letter}|{digit}|[.:_])*" "{digit}{digit}* ACCEPT(C_FUNCTION);
("call ")({letter})({letter}|{digit}|[.:_])*" "{digit}{digit}* ACCEPT(C_CALL);
"return"                                    ACCEPT(C_RETURN);

{arithmetic}            ACCEPT(C_ARITHMETIC);


{comments}              LINE_COUNT();
{whitespace}            LINE_COUNT();

.                       ACCEPT(C_UNDEFINED);



%%

/* ====================================================================== */

#include <fcntl.h>
#include <dirent.h>

void init ()
{
    printf("@256\n");
    printf("D=A\n");
    printf("@SP\n");
    printf("M=D\n");

    printf("@Sys.init\n");
    printf("0;JMP\n");

}
int main(int argc, char *argv[])
{
    int fd;
    DIR* dir;
    struct dirent* dent;
    char option;
    char* fname;

    char* dirPath;
    char* dirName = (char*) malloc (1);
    char* str;
    char* ctx = NULL;
    char* tok;

    if (argc < 3) 
    {
    }
    else
    {
        opt = argv[2][0];
    }

    dir = opendir(argv[1]);

    if ( strstr(argv[1], ".vm") != NULL )
    {
        fname = (char*) malloc ( strlen(argv[1]) + 2 );
        strcpy ( fname, argv[1] );

        stringReplace(fname, argv[1], ".vm", ".asm");
    }
    else
    {

        // distinguish directory sign from only name (dir/ or dir)
        // and that make string that is directory full path having '/' char
        if ( argv[1][strlen(argv[1])-1] == '/' ) 
        {
            dirPath = (char*) malloc (strlen(argv[1]));
            strcpy(dirPath, argv[1]);
            *(dirPath + strlen(argv[1]) - 1) = '\0';
        }
        else
        {
            dirPath = (char*) malloc (strlen(argv[1]) + 1);
            strcpy(dirPath, argv[1]);
        }

        str = (char*) malloc (strlen(dirPath) + 1);
        strcpy(str, dirPath);

        tok = strtok_r(str, "/", &ctx);
        while( tok ) 
        {
            int len = strlen(tok); 
            dirName = (char*) realloc (dirName, len + 1);
            strcpy(dirName, tok);
            tok = strtok_r(NULL, "/", &ctx);
        }

        fname = (char*) malloc ( strlen(dirPath) + strlen(dirName) + 2 );

        sprintf(fname, "%s/%s", dirPath, dirName);

        stringAppend(fname, ".asm");

    }

    if (argc < 3) 
    {
        remove(fname);
        fd = open ( fname, O_CREAT | O_WRONLY, 0664 );
        close(1);
        fd = dup(fd);
    }
    
    
    //one .vm file
    if (dir == NULL)
    {
        yyin = fopen(argv[1], "r");
        
        yylex();
        free(fname);
    }
    else //directory that have contained bunch of .vm files
    {
        init();

        //printf("dirPath : %s\n", dirPath);
        //printf("file.asm : %s\n", fname);


        while ( (dent = readdir(dir)) != NULL )
        {

            char* word = ".vm";

            // check .vm files            
            if ( strstr(dent->d_name, word) )
            {
                int len = strlen(dirPath) + strlen(dent->d_name) + 1;
                char* fullPath = (char*) malloc (len);
                char* scopeName = (char*) malloc (strlen(dent->d_name) + 1);
                
                stringReplace(scopeName, dent->d_name, word, "");


                sprintf(fullPath, "%s/%s", dirPath, dent->d_name);

                //prepare file                
                yyin = fopen(fullPath, "r");

                //printf("file name : %s\n", fullPath);
                

                //scanning and generation 
                yylex();

                free(scopeName);

            }
        }

        free(dirPath);
        free(str);
        free(dirName);
    }

    return 0;
}

/* ====================================================================== */
