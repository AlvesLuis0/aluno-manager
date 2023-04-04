#include <stdio.h>

#include "lista.h"

// procedimento que exporta a lista para um arquivo (geralmente CSV)
void IO_ExportarLista(Lista *lista, char *caminho) {
	FILE *arquivo = fopen(caminho, "w");

	if(!arquivo) {
		fprintf(stderr, "[ERRO]: Nao foi possivel exportar a lista para o arquivo %s\n", caminho);
		return;
	}

	fputs("ALUNO,MATRICULA,AV1,AV2,AV3\n", arquivo);

	for(int i = 0; i < lista->tamanho; i++)
		fprintf(arquivo, "%s,%lli,%.1f,%.1f,%.1f\n",
			lista->alunos[i].nome,
			lista->alunos[i].matricula,
			lista->alunos[i].av1,
			lista->alunos[i].av2,
			lista->alunos[i].av3
		);

	fclose(arquivo);
}