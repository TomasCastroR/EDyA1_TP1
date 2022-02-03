# Reglas de makefile

project: main.o glist.o generar.o sorting.o persona.o
	gcc -o project main.o glist.o generar.o sorting.o persona.o

main.o: main.c glist.h generar.h
	gcc -c -Wall -Werror -Wextra -std=c99 -g main.c

glist.o: glist.c glist.h
	gcc -c -Wall -Werror -Wextra -std=c99 -g glist.c

generar.o: generar.c generar.h
	gcc -c -Wall -Werror -Wextra -std=c99 -g generar.c

sorting.o: sorting.c sorting.h
	gcc -c -Wall -Werror -Wextra -std=c99 -g sorting.c

persona.o: persona.c persona.h
	gcc -c -Wall -Werror -Wextra -std=c99 -g persona.c
