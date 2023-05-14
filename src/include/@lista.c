#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

// função que aloca memória para a lista e retorna seu ponteiro
Lista* Lista_Nova() {
	Lista *lista = calloc(1, sizeof(Lista*));
	lista->alunos = calloc(0, 0);
	lista->tamanho = 0;

	return lista;
}

// procedimento que printa cada aluno dentro da lista
void Lista_Print(Lista* lista) {
	if(!lista->tamanho) {
		printf("[MENSAGEM]: Nenhum aluno cadastrado ainda\n\n");
		return;
	}

	for(int i = 0; i < lista->tamanho; i++)
		Aluno_Print(lista->alunos[i]);
}

// procedimento que aloca mais espaço pra lista e adiciona um aluno
void Lista_Cadastrar(Lista *lista, Aluno aluno, int comAvisos) {
	int alunoNaoExiste = Lista_Selecionar(lista, aluno.matricula, 0) == -1;

	if(alunoNaoExiste) {
		int novoTamanhoEmBytes = sizeof(Aluno) * ++lista->tamanho;
		lista->alunos = realloc(lista->alunos, novoTamanhoEmBytes);
		lista->alunos[lista->tamanho - 1] = aluno;

		if(comAvisos)
			printf("[PROGRAMA]: %s cadastrado com sucesso\n\n", aluno.nome);

		return;
	}

	fprintf(stderr, "[ERRO]: Ja existe um aluno com essa matricula %lli\n\n", aluno.matricula);
}

// retorna o index do aluno com a mesma matrícula, ou retorna -1 se ele não estiver na lista
int Lista_Selecionar(Lista *lista, long long int matricula, int comAvisos) {
	for(int i = 0; i < lista->tamanho; i++)
		if(lista->alunos[i].matricula == matricula)
			return i;
	
	if(comAvisos)
		fprintf(stderr, "[ERRO]: Aluno com a matricula %lli nao cadastrado\n\n", matricula);

	return -1;
}

// função que retorna todos com uma média maior ou igual a 6
Lista* Lista_SelecionarAprovados(Lista *lista) {
	Lista *listaAprovados = Lista_Nova();

	for(int i = 0; i < lista->tamanho; i++)
		if(Aluno_Media(lista->alunos[i]) >= 6)
			Lista_Cadastrar(listaAprovados, lista->alunos[i], 0);
	
	return listaAprovados;
}

// função que retorna todos com uma média menor que 6
Lista* Lista_SelecionarReprovados(Lista *lista) {
	Lista *listaReprovados = Lista_Nova();

	for(int i = 0; i < lista->tamanho; i++)
		if(Aluno_Media(lista->alunos[i]) < 6)
			Lista_Cadastrar(listaReprovados, lista->alunos[i], 0);
	
	return listaReprovados;
}

// procedimento que apaga os ponteiros de seus atributos e a si próprio
void Lista_Deletar(Lista *lista) {
	free(lista->alunos);
	free(lista);
}