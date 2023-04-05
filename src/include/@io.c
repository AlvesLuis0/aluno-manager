#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

// procedimento que exporta a lista para um arquivo (geralmente CSV)
void IO_ExportarLista(Lista *lista, char *caminho) {
	FILE *arquivo = fopen(caminho, "w");

	if(!arquivo) {
		fprintf(stderr, "[ERRO]: Nao foi possivel exportar a lista para o arquivo %s\n\n", caminho);
		return;
	}

	fputs("ALUNO,MATRICULA,AV1,AV2,AV3", arquivo);

	for(int i = 0; i < lista->tamanho; i++)
		fprintf(arquivo, "\n%s,%lli,%.1f,%.1f,%.1f",
			lista->alunos[i].nome,
			lista->alunos[i].matricula,
			lista->alunos[i].av1,
			lista->alunos[i].av2,
			lista->alunos[i].av3
		);

	fclose(arquivo);
	puts("Lista exportada com sucesso\n");
}

// função que retorna uma lista importada de um arquivo (geralmente CSV)
Lista* IO_ImportarLista(char *caminho) {
	Lista *lista = Lista_Nova();
	FILE *arquivo = fopen(caminho, "r");
	char buffer[256];
	char *cursor;
	char nome[40];
	long long int matricula;
	float av1, av2, av3;
	Aluno aluno;

	if(!arquivo) {
		fprintf(stderr, "[ERRO]: Nao foi possível importar a lista do arquivo %s\n\n", caminho);
	}

	fgets(buffer, 256, arquivo);

	while(fgets(buffer, 256, arquivo)) {
		cursor = strtok(buffer, ",");
		strcpy(nome, cursor);
		cursor = strtok(NULL, ",");
		matricula = atoll(cursor);
		cursor = strtok(NULL, ",");
		av1 = atof(cursor);
		cursor = strtok(NULL, ",");
		av2 = atof(cursor);
		cursor = strtok(NULL, ",");
		av3 = atof(cursor);

		Aluno_Novo(&aluno, nome, matricula, av1, av2, av3);
		Lista_Cadastrar(lista, aluno, 0);
	}

	fclose(arquivo);
	puts("Lista importada com sucesso\n");

	return lista;
}