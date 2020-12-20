
int buscaSequencial(int valor, int tamanho, int *vetor) {
	int i;
	for(i = 0; i < tamanho; i++) {
		if(vetor[i] == valor)
			return i;
	}
	return -1;
}

int buscaBinaria(int valor, int tamanho, int *vetor) {
	int inicio, fim, meio;
	inicio = 0;
	fim = tamanho - 1;
	while(inicio != fim + 1) {
		meio = inicio + (fim - inicio)/2;
		if(vetor[meio] == valor) return meio;
		if(vetor[meio] < valor) {
			inicio = meio + 1;
			continue;
		}
		fim = meio - 1;
	}
	return -1;
}

int buscaBinariaRecursiva(int valor, int inicio, int fim, int *vetor) {
	if(inicio == fim - 1)
		return fim;
	int meio = (inicio + fim)/2;
	if(vetor[meio] < valor)
		return buscaBinariaRecursiva(valor, meio, fim, vetor);
	return buscaBinariaRecursiva(valor, inicio, meio, vetor);
}