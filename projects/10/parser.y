/* ====================================================================== */

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* ====================================================================== */

extern FILE *yyin;
extern char *yytext;
extern int source_line_no;

/* ====================================================================== */

int yyerror(char *message);

%}

/* ====================================================================== */

%start class

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

%%

class 
    : CLASS className LBRACE classVarDecList subroutineDecList RBRACE
;


className
    : ID
;


classVarDecList
    : classVarDecList classVarDec
    | empty
;

classVarDec
    : STATIC type varNameList SEMICOLON
    | FIELD type varNameList SEMICOLON
;

type
    : VOID
    | INT
    | CHAR
    | BOOLEAN
    | className
;

varNameList
    : varNameList COMMA varName
    | varName
;

varName 
    : ID
;



subroutineDecList
    : subroutineDecList subroutineDec
    | empty
;

subroutineDec 
    : subroutineKind type subroutineName LPAR parameters RPAR subroutineBody
;

subroutineKind 
    : CONSTRUCTOR
    | FUNCTION
    | METHOD
;

subroutineName 
    : ID
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
;

subroutineBody 
    : LBRACE varDecs statements RBRACE
;

varDecs 
    : varDecs VAR type varDecList SEMICOLON
    | empty
;

varDecList 
    : varDecList COMMA varDec
    | varDec
;

varDec 
    : varName
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
    : LET varName EQ expression SEMICOLON
    | LET varName LBRACE expression RBRACE EQ expression SEMICOLON
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
    | varName LBRACKET expression RBRACKET
    | subroutineCall
    | LPAR expression RPAR
    | unaryOp term
;

subroutineCall 
    : subroutineName LPAR expressionList RPAR
    | className DOT subroutineName LPAR expressionList RPAR
    | varName subroutineName LPAR expressionList RPAR
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
