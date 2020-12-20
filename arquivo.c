
int* ler(char *nomeF, int *tamanho) {
	FILE *arquivo;
	int *vetor;
	int i = 0;
	arquivo = fopen(nomeF, "r");
	if(arquivo == NULL) {
		printf("Erro ao abrir o arquivo\n");
		vetor = NULL;
	}
	else {
		fscanf(arquivo, "%d", tamanho);
		// Aloca um ponteiro com o tamanho do vetor vezes o tamanho do inteiro
		vetor = malloc((*tamanho)*(sizeof(int)));
		if(vetor != NULL) {
			// Verifica se é o final do arquivo 
			while(!feof(arquivo)) {
				fscanf(arquivo, "%d", &vetor[i]);
				i++;
			}
		}
		else {
			printf("Erro ao alocar na memoria");
			*tamanho = -1;
			vetor = NULL;
		}
		fclose(arquivo);
	}
	return vetor;
}