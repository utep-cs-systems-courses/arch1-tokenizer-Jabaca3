HEADES = tokenizer.h history.h

all: UI_Main

UI_Main: UI_Main.o tokenizer.o history.o
	gcc UI_Main.o tokenizer.o history.o -o UI_Main

UI_Main.o: UI_Main.c $(HEADER)
	gcc -c UI_Main.c -o UI_Main.o

tokeinzer.o: tokenizer.c
	gcc -c tokenizer.c -o tokenizer.o

history.o: history.c
	gcc -c history.c -o history.o
clean:
	-rm *.o
	-rm *~
	-rm *.c#
	-rm UI_Main
