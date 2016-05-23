/* ====================================================================== */

%{

#include "parser.h"
#include <string.h>

/* ====================================================================== */

#define	ACCEPT(x) \
{ \
  printf("%s\n", yytext);\
  yytext[yyleng] = '\0'; \
  lex = malloc(yyleng + 1); \
  strcpy(lex, yytext); \
  return(x); \
}

#define LINE_COUNT() line_count() 
/* ====================================================================== */

char *lex;			/* current lexeme of ID or NUM */
int source_line_no = 1;

void line_count()
{
	int i = 0;
	char c;

	while ( (c = *(yytext + i)) != '\0' )
	{
		if ( c == '\n' )
		{
			source_line_no++;
		}
		i++;
	}
}

/* ====================================================================== */

%}

digit				[0-9]
letter				[a-zA-Z]

whitespace          [\t\r\n ]
comments            "/*"([^*]|(\*[^/]))*"*/"|(\/\/.*\n) 


%%

"class"                             ACCEPT(CLASS);
"constructor"                       ACCEPT(CONSTRUCTOR);
"function"                          ACCEPT(FUNCTION);
"method"                            ACCEPT(METHOD);
"field"                             ACCEPT(FIELD);
"static"                            ACCEPT(STATIC);
"var"                               ACCEPT(VAR);
"int"                               ACCEPT(INT);
"char"                              ACCEPT(CHAR);
"boolean"                           ACCEPT(BOOLEAN);
"void"                              ACCEPT(VOID);
"true"                              ACCEPT(TRUE);
"false"                             ACCEPT(FALSE);
"null"                              ACCEPT(NULLVAL);
"this"                              ACCEPT(THIS);
"let"                               ACCEPT(LET);
"do"                                ACCEPT(DO);
"if"                                ACCEPT(IF);
"else"                              ACCEPT(ELSE);
"while"                             ACCEPT(WHILE);
"return"                            ACCEPT(RETURN);

"{"                                 ACCEPT(LBRACE);
"}"                                 ACCEPT(RBRACE);
"("									ACCEPT(LPAR);
")"									ACCEPT(RPAR);
"["									ACCEPT(LBRACKET);
"]"									ACCEPT(RBRACKET);
"."									ACCEPT(DOT);
","									ACCEPT(COMMA);
";"									ACCEPT(SEMICOLON);
"+"									ACCEPT(PLUS);
"-"									ACCEPT(MINUS);
"*"									ACCEPT(MULTIPLY);
"/"									ACCEPT(DIVIDE);
"&"									ACCEPT(AND);
"|"									ACCEPT(OR);
"<"									ACCEPT(LT);
">"									ACCEPT(GT);
"="									ACCEPT(EQ);
"~"									ACCEPT(NOT);



{digit}{digit}*                     ACCEPT(NUM);
"\""([^"\""\n])*"\""                ACCEPT(STRING);

("_"|{letter})({digit}|{letter}|"_")*   ACCEPT(ID);

{comments}                          LINE_COUNT();
{whitespace}                        LINE_COUNT();

%%

/* ====================================================================== */
