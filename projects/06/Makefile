# ======================================================================

Assembler:	Assembler.c
	gcc -O -o Assembler Assembler.c -lfl

Assembler.c:	scanner.l
	flex scanner.l
	mv lex.yy.c Assembler.c

# ======================================================================

clean:
	@rm -rf .*~ *~ Assembler Assembler.c *.o *.ps *.pdf

# ======================================================================
