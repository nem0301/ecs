// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, the
// program clears the screen, i.e. writes "white" in every pixel.

// Put your code here.

    @SCREEN
    D=A
    @addr
    M=D

(LOOP)
    @24576
    D=M
    @BLACK
    D;JNE
    @WHITE
    D;JEQ
    @LOOP
    0;JMP
    


(BLACK)
    @24576
    D=A
    @addr
    D=D-M
    @LOOP
    D;JLE

    @addr
    D=M
    A=D
    D=0
    D=!D
    M=D
    @addr
    M=M+1
    @LOOP
    0;JMP

(WHITE)    
    @SCREEN
    D=A
    @addr
    D=D-M
    @LOOP
    D;JGT

    @addr
    D=M
    A=D
    D=0
    M=D
    D=D-1
    @addr
    M=M-1 
    @LOOP
    0;JMP
