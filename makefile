main: main.o menu.o
	@echo "Gerando arquivo executavel"
	gcc *.c -o main

main.o: main.c
	@echo "Compilando e gerando o objeto main"
	gcc -c *.c

menu.o: menu.c
	@echo "Compilando e gerando o objeto menu"
	gcc -c menu.c

clean:
	rm -f *.o main

run:
	./main
