# ======================================================================


VMtranslator:	VMtranslator.o myString.o static.o
	gcc -O -o VMtranslator VMtranslator.o myString.o static.o -lfl

VMtranslator.o:	VMtranslator.c myString.h
	gcc -O -c VMtranslator.c -I.

myString.o: myString.c myString.h
	gcc -O -c myString.c -I.

static.o: static.c static.h
	gcc -O -c static.c -I.

VMtranslator.c:	scanner.l
	flex scanner.l
	mv lex.yy.c VMtranslator.c

# ======================================================================

clean:
	@rm -rf .*~ *~ VMtranslator VMtranslator.c *.o *.ps *.pdf

# ======================================================================
