#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include "arquivo.c"
#include "buscas.c"

void imprime(int *vetor, int tamanho);

int main(int argc, char const *argv[]) {
	int *vetor, tamanho, i , n;
	if(argc < 2) {
		printf("Esta faltando o parametro de entrada 'entrada.txt'\n");
		return 0;
	}
	// Pega o vetor e o tamanho do vetor
	vetor = ler((char *) argv[1], &tamanho);
	if(vetor != NULL) {
		while(true) {
			imprime(vetor, tamanho);
			printf("Digite o numero para buscar ");
			scanf("%d", &n);
			if(n < 0) break;
			//i = buscaSequencial(n, tamanho, vetor);
			i = buscaBinaria(n, tamanho, vetor);
			//i = buscaBinariaRecursiva(n, 0, tamanho-1, vetor);
			if(i == -1) {
				printf("RES: Numero nao encontrado!\n");
				continue;
			}

			printf("RES: Numero encontrado no indice %d.\n", i);
		}	
		free(vetor);
	}
	return 0;
}

void drawLine() {
	int i = 0;
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    while(i < w.ws_col) {
		printf("-");
		i++;
    }
	printf("\n");
}

void imprime(int *vetor, int tamanho) {
	int i;
	drawLine();
	for (i = 0; i < tamanho; i++)
		printf("Indice %d: %d\t", i, vetor[i]);
	printf("\n");
	drawLine();
}
