# ======================================================================

VMtranslator:	VMtranslator.c
	gcc -O -o VMtranslator VMtranslator.c -lfl

VMtranslator.c:	scanner.l
	flex scanner.l
	mv lex.yy.c VMtranslator.c

# ======================================================================

clean:
	@rm -rf .*~ *~ VMtranslator VMtranslator.c *.o *.ps *.pdf

# ======================================================================
