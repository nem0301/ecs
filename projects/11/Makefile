# ======================================================================

DIR = parser
FILES = Makefile parser.y scanner.l

# ======================================================================

parser:	parser.o scanner.o myString.o table.o
	gcc -O -o parser parser.o scanner.o myString.o -lfl

parser.o:	parser.c
	gcc -O -c parser.c -I.

parser.c:	parser.y table.c
	bison -d parser.y
	mv parser.tab.c parser.c
	mv parser.tab.h parser.h

myString.o:	myString.c
	gcc -c myString.c

scanner.o:	scanner.c
	gcc -O -c scanner.c

scanner.c:	scanner.l
	flex scanner.l
	mv lex.yy.c scanner.c

# ======================================================================

install:	parser
	install parser /usr/local/bin

# ======================================================================

pdf:	$(FILES)
	a2ps --medium=A4 --line-numbers=1 $(FILES) -o $(DIR).ps
	ps2pdf -sPAPERSIZE=a4 $(DIR).ps $(DIR).pdf
	@rm -f $(DIR) $(DIR).ps

# ======================================================================

clean:
	@rm -rf .*~ *~ parser parser.c parser.h scanner.c *.o *.ps *.pdf

# ======================================================================
