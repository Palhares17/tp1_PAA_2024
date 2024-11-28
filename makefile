all:
	gcc main.c ./sources/labirinto.c ./sources/utilitarios.c -o ./bin/exe
	./bin/exe
