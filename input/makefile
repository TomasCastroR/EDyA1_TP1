

generar: mainInput.o input/input.o
	gcc -o generar.out mainInput.o input/input.o

mainInput: mainInput.c
	gcc -c -Wall -Wextra mainInput.c

input: input/input.c
	gcc -c -Wall -Wextra input/input.c

clean:
	rm -rf *.o *.out
	rm input/*.o