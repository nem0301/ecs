/* ====================================================================== */

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "myString.h"
#include "table.c"



/* ====================================================================== */

extern FILE *yyin;
extern char *yytext;
extern int source_line_no;
extern char* lex;

unsigned char position = CLASS_KIND;
unsigned char type = -1;
char* lexeme;

extern struct table *global_table;
extern struct table *local_table;
extern struct table *current_table;

typedef struct t_type_struct {
    unsigned char type;
}t_type;

typedef struct l_type_struct {
    char* lex;
}l_type;


/* ====================================================================== */

int yyerror(char *message);

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

%type <lval> className
%type <tval> type

%%

class
    : 
    {
        global_table = current_table = createTable("global");

        printf("---------- ---------- ---------- ----------\n");
        printf("%-10s %-10s %-10s %-10s\n", "name", "kind", "type", "type_name");
        printf("---------- ---------- ---------- ----------\n");
    }
    CLASS className 
    {
        insertTable ( global_table, $<lval>3.lex, CLASS_KIND, CLASS_TYPE, "");
    }
    LBRACE classVarDecList subroutineDecList RBRACE
    {
        printTable(global_table);
    }
;


className
    : ID
    {
        $<lval>$.lex = lex;
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
    varNameList SEMICOLON  

    | FIELD type 
    {
        position = FIELD_KIND;
        type = $<tval>2.type;
    }
    varNameList SEMICOLON
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
    | className
    {
        $<tval>$.type = OBJECT_TYPE;
        lexeme = (char*) malloc (strlen(lex));;
        strcpy(lexeme, lex);
    }
;

varNameList
    : varNameList COMMA varName
    {
        insertTable(current_table, $<lval>3.lex, position, type, lexeme);
    }
    | varName
    {
        
        insertTable(current_table, $<lval>1.lex, position, type, lexeme);
    }
;

varName 
    : ID
    {
        $<lval>$.lex = lex;
    }
;



subroutineDecList
    : subroutineDecList subroutineDec
    | empty
;

subroutineDec 
    : subroutineKind type subroutineName 
    {
        insertTable(global_table, $<lval>3.lex, $<tval>1.type, $<tval>2.type, lexeme);
        local_table = createTable($<lval>3.lex);
        current_table = local_table;
    }
    LPAR parameters RPAR subroutineBody
    {
        printTable(local_table);
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

subroutineName 
    : ID
    {
        $<lval>$.lex = lex;
    }
;

parameters 
    : parameterList
    | empty
;

parameterList 
    : parameterList COMMA parameter
    | parameter
;

parameter 
    : type varName
    {
        insertTable(current_table, $<lval>2.lex, ARGUMENT_KIND, $<tval>1.type, lexeme);
    }
;

subroutineBody :
    {
        position = LOCAL_KIND;
    }
    LBRACE varDecs statements RBRACE
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
    : varDecList COMMA varName
    {
        insertTable(current_table, $<lval>3.lex, position, type, lexeme);
    }
    | varName
    {
        insertTable(current_table, $<lval>1.lex, position, type, lexeme);
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
    : LET varName 
    {
    }
    EQ expression SEMICOLON

    | LET varName 
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
;

expression 
    : expression op term
    | term
;

term 
    : NUM
    | STRING
    | keywordConstant
    | varName
    {
    }
    | varName LBRACKET expression RBRACKET
    {
    }
    | subroutineCall
    | LPAR expression RPAR
    | unaryOp term
;

subroutineCall 
    : subroutineName 
    {
    }
    LPAR expressionList RPAR

    | className DOT subroutineName 
    {
    }
    LPAR expressionList RPAR

    | varName DOT subroutineName 
    {
    }
    LPAR expressionList RPAR
;

expressionList
    : expressionList COMMA expression
    | expression
    | empty
;


op 
    : PLUS
    | MINUS
    | MULTIPLY
    | DIVIDE
    | AND
    | OR
    | LT
    | GT
    | EQ
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

int main(int argc, char *argv[])
{
  if(argc != 2) {
    fprintf(stderr, "usage: parser file\n");
    exit(1);
  }

  yyin = fopen(argv[1], "r");

  if(yyin == NULL) {
    fprintf(stderr, "%s: %s\n", argv[1], strerror(errno));
    exit(1);
  }

  

    
  yyparse();

  return 0;
}

/* ====================================================================== */
