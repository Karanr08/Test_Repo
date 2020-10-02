LEX=flex
CC=gcc
CFLAG=-lfl 
DEPS=lex.h
BASE=ass3_18CS10025


lexer: $(BASE).c lex.yy.c
	$(CC) -o $@ $(BASE).c lex.yy.c $(CFLAG)

lex.yy.c: $(BASE).l 
	$(LEX) $<

clean: 
	rm lexer lex.yy.c

test: lexer $(BASE)_test.c
	./lexer < $(BASE)_test.c

