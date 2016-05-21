# ======================================================================


VMtranslator:	VMtranslator.o myString.o scope.o
	gcc -O -o VMtranslator VMtranslator.o myString.o scope.o -lfl

VMtranslator.o:	VMtranslator.c myString.h
	gcc -O -c VMtranslator.c -I.

myString.o: myString.c myString.h
	gcc -O -c myString.c -I.

scope.o: scope.c scope.h
	gcc -O -c scope.c -I.

VMtranslator.c:	scanner.l
	flex scanner.l
	mv lex.yy.c VMtranslator.c

# ======================================================================

clean:
	@rm -rf .*~ *~ VMtranslator VMtranslator.c *.o *.ps *.pdf

# ======================================================================
