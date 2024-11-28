all:
	gcc main.c ./sources/labirinto.c ./sources/utilitarios.c ./sources/gerador.c -o ./bin/exe
	./bin/exe
