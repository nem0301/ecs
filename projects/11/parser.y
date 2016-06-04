/* ====================================================================== */

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include "myString.h"
#include "table.c"


/* ====================================================================== */

#define UNDEFINED_VAR 0
#define UNDEFINED_FUNC 1
#define REDEFINED_VAR 10
#define REDEFINED_FUNC 11
#define WORNG_TYPE_VAR 20
#define WORNG_TYPE_FUNC 21


/* ====================================================================== */

extern FILE *yyin;
extern char *yytext;
extern int source_line_no;
extern char *lex;

unsigned char position = CLASS_KIND;
unsigned char type = -1;
char *lexeme;

unsigned int field_count = 0;
unsigned int static_count = 0;
unsigned int local_count = 0;
unsigned int arg_count = 0;
char *classname = NULL;

extern struct table *global_table;
extern struct table *local_table;
extern struct table *current_table;

typedef struct t_type_struct {
    unsigned char type;
}t_type;

typedef struct l_type_struct {
    char *lex;
}l_type;


/* ====================================================================== */

int yyerror(char *message);
int semanticError(char *fmt, unsigned char err_type);

void printVar(char *name)
{
    struct symbol *symbole = lookupTable(name);

    if ( symbole != NULL )
    {
        printf("%-20s %-20s %-20s %-20s %-20d\n", name, 
                                            kind_list[symbole->kind],
                                            type_list[symbole->type],
                                            symbole->type_name,
                                            symbole->num
                                            );
    }
    else
    {
        printf("%s is not in any table\n", name);
    }
}

%}

/* ====================================================================== */


%start class

%union {
    l_type lval;
    t_type tval;
}


%token CLASS CONSTRUCTOR FUNCTION METHOD FIELD STATIC
%token VAR INT CHAR BOOLEAN VOID
%token TRUE FALSE
%token NULLVAL
%token THIS LET DO IF ELSE WHILE RETURN
%token LBRACE RBRACE LPAR RPAR LBRACKET RBRACKET
%token DOT COMMA SEMICOLON
%token PLUS MINUS MULTIPLY DIVIDE
%token AND OR LT GT EQ NOT
%token NUM STRING ID

%type <lval> identifier numConstant stringConstant
%type <tval> type subroutineKind

%%

class
    : 
    {
        field_count = 0;
        static_count = 0;
        local_count = 0;

        global_table = current_table = createTable("global");
        /*
        printf("---------- ---------- ---------- ----------\n");
        printf("%-10s %-10s %-10s %-10s\n", "name", "kind", "type", "type_name");
        printf("---------- ---------- ---------- ----------\n");
        */
    }
    CLASS identifier 
    {
        classname = (char*) malloc (strlen($<lval>3.lex) + 1);
        strcpy(classname, $<lval>3.lex);
        insertTable ( global_table, classname, CLASS_KIND, CLASS_TYPE, 0, "");
    }
    LBRACE classVarDecList subroutineDecList RBRACE
    {
        //printTable(global_table);
    }
;

classVarDecList
    : classVarDecList classVarDec
    | empty
;

classVarDec
    : STATIC type 
    {
        position = STATIC_KIND;
        type = $<tval>2.type;
    }
    identifierList SEMICOLON  

    | FIELD type 
    {
        position = FIELD_KIND;
        type = $<tval>2.type;
    }
    identifierList SEMICOLON
;

identifier 
    : ID
    {
        $<lval>$.lex = lex;
    }
;

type
    : VOID
    {
        $<tval>$.type = VOID_TYPE;

    }
    | INT
    {
        $<tval>$.type = INT_TYPE;
    }
    | CHAR
    {
        $<tval>$.type = CHAR_TYPE;
    }
    | BOOLEAN
    {
        $<tval>$.type = BOOLEAN_TYPE;
    }
    | identifier
    {
        $<tval>$.type = OBJECT_TYPE;
        lexeme = (char*) malloc (strlen(lex));;
        strcpy(lexeme, lex);
    }
;

identifierList
    : identifierList COMMA identifier
    {
        insertTable(current_table, $<lval>3.lex, position, type, field_count, lexeme);
        field_count++;
    }
    | identifier
    {
        
        insertTable(current_table, $<lval>1.lex, position, type, field_count, lexeme);
        field_count = 1;
    }
;

subroutineDecList
    : subroutineDecList subroutineDec
    | empty
;

subroutineDec 
    : subroutineKind type identifier 
    {
        insertTable(global_table, $<lval>3.lex, $<tval>1.type, $<tval>2.type, 0, lexeme);
        local_table = createTable($<lval>3.lex);
        current_table = local_table;
        arg_count = 0;
        local_count = 0;


    }
    LPAR parameters RPAR
    {
        isInHashTable(global_table, $<lval>3.lex)->num = arg_count;
        

    }
    subroutineBody
    {
        //printTable(local_table);
        current_table = global_table;
    }
;

subroutineKind 
    : CONSTRUCTOR
    {
        $<tval>$.type = CONSTRUCTOR_KIND;
    }
    | FUNCTION
    {
        $<tval>$.type = FUNCTION_KIND;
    }
    | METHOD
    {
        $<tval>$.type = METHOD_KIND;
    }
;

identifier 
    : ID
    {
        $<lval>$.lex = lex;
    }
;

parameters 
    : parameterList
    | empty
    {
        arg_count = 0;
    }
;

parameterList 
    : parameterList COMMA parameter
    | parameter
;

parameter 
    : type identifier
    {
        insertTable(current_table, $<lval>2.lex, ARGUMENT_KIND, $<tval>1.type, arg_count, lexeme);
        arg_count++;
    }
;

subroutineBody :
    {
        position = LOCAL_KIND;
    }
    LBRACE varDecs 
    {
        printf("function %s.%s %d\n", classname, current_table->name, local_count);
    }
    statements RBRACE
;

varDecs 
    : varDecs VAR type 
    {
        type = $<tval>3.type;
    }
    varDecList SEMICOLON
    | empty
;

varDecList 
    : varDecList COMMA identifier
    {
        insertTable(current_table, $<lval>3.lex, position, type, local_count, lexeme);
        local_count++;
    }
    | identifier
    {
        insertTable(current_table, $<lval>1.lex, position, type, local_count, lexeme);
        local_count = 1;
    }
;





statements
    : statements statement
    | empty
;

statement 
    : letStatement
    | ifStatement
    | whileStatement
    | doStatement
    | returnStatement
;

letStatement 
    : LET identifier 
    {
    }
    EQ expression SEMICOLON

    | LET identifier 
    {
    }
    LBRACKET expression RBRACKET EQ expression SEMICOLON
;

ifStatement 
    : IF LPAR expression RPAR LBRACE statements RBRACE
    | IF LPAR expression RPAR LBRACE statements RBRACE ELSE LBRACE statements RBRACE
;

whileStatement 
    : WHILE LPAR expression RPAR LBRACE statements RBRACE
;

doStatement 
    : DO subroutineCall SEMICOLON
;

returnStatement
    : RETURN expression SEMICOLON
    | RETURN SEMICOLON
    {
        printf("pop temp 0\n");
        printf("push constant 0\n");
        printf("return\n");
    }
;

expression 
    : expression op term
    {
        printf("%s\n", $<lval>2.lex);
    }
    | term
;

term 
    : numConstant
    {
        printf("push constant %s\n", $<lval>1.lex);
    }
    | stringConstant
    | keywordConstant
    | identifier
    | identifier LBRACKET expression RBRACKET
    | subroutineCall
    | LPAR expression RPAR
    | unaryOp term
;


numConstant 
    : NUM
    {
        $<lval>$.lex = lex;
    }
;
stringConstant
    : STRING
    {
        $<lval>$.lex = lex;
    }
;

    

subroutineCall 
    : identifier 
    {
        arg_count = 0;
    }
    LPAR expressionList RPAR
    {
        printf("call %s %d\n", $<lval>1.lex, arg_count);
    }

    | identifier DOT identifier 
    {
        arg_count  = 0;
    }
    LPAR expressionList RPAR
    {
        printf("call %s.%s %d\n", $<lval>1.lex, $<lval>3.lex, arg_count);
    }
;

expressionList
    : expressionList COMMA expression
    {
        arg_count++;
    }
    | expression
    {
        arg_count = 1;
    }
    | empty
    {
        arg_count = 0;
    }
;


op 
    : PLUS
    {
        $<lval>$.lex = "add"; 
    }
    | MINUS
    {
        $<lval>$.lex = "sub"; 
    }
    | MULTIPLY
    {
        $<lval>$.lex = "call Math.multiply 2"; 
    }
    | DIVIDE
    {
        $<lval>$.lex = "call Math.divide 2"; 
    }
    | AND
    {
        $<lval>$.lex = "and"; 
    }
    | OR
    {
        $<lval>$.lex = "or"; 
    }
    | LT
    {
        $<lval>$.lex = "lt"; 
    }
    | GT
    {
        $<lval>$.lex = "gt"; 
    }
    | EQ
    {
        $<lval>$.lex = "eq"; 
    }
;

unaryOp 
    : MINUS
    | NOT
;

keywordConstant 
    : TRUE
    | FALSE
    | NULLVAL
    | THIS
;

empty 
    :
;








/* ====================================================================== */


%%


/* ====================================================================== */

int yyerror(char *message)
{
    fprintf(stderr, "line %d: %s at \"%s\"\n", source_line_no, message, yytext);
}

/* ====================================================================== */

void run(char *fname)
{
    int fd;
    char *vmName;

    vmName = (char*) malloc (strlen(fname) - 1);
    strcpy ( vmName, fname );

    stringReplace(vmName, fname, ".jack", ".vm");


    remove(vmName);
    fd = open (vmName, O_CREAT | O_WRONLY, 0664);
    dup2(fd, 1);
    fprintf(stderr, "%d %s\n", fd, vmName);

    yyin = fopen(fname, "r"); 
    yyparse();
    free(vmName);
    close(fd);
    fflush(stdout);
}

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *dent;
    char *fname;

    char *dirPath;

    dir = opendir(argv[1]);
    

    /*
    if (argc < 3)
    {
    }
    */
   
    if (dir == NULL)
    {
        run(argv[1]);
    }
    else 
    {
        // distinguish directory sign from only name (dir/ or dir)
        // and that make string to do not have '/' char
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
        while ( (dent = readdir(dir)) != NULL )
        {
            if( strstr(dent->d_name, ".jack") != NULL &&
                strstr(dent->d_name, ".swp") == NULL)
            {
                int len = strlen(dirPath) + strlen(dent->d_name) + 1;
                char* fullPath = (char*) malloc (len);

                sprintf(fullPath, "%s/%s", dirPath, dent->d_name);
                run(fullPath);
            }
        }

    }

    return 0;
}

/* ====================================================================== */
