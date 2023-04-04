#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/aluno.h"
#include "include/lista.h"
#include "include/io.h"

// declarando listas e um aluno para passarmos os valores
Lista *lista;
Lista *listaAprovados;
Lista *listaReprovados;
Aluno aluno;
int rodando = 1; // se for 1, o programa continua rodando

void EscolherFuncao(int escolha);
void LimparString(char *string);

int main() {
	// alocando memória para a lista
	lista = Lista_Nova();

	// looping do programa
	while(rodando) {
		puts("[PROGRAMA]: O que deseja fazer?");
		puts("[0] Sair");
		puts("[1] Cadastrar aluno");
		puts("[2] Selecionar aluno");
		puts("[3] Selecionar todos os alunos aprovados");
		puts("[4] Selecionar todos os alunos reprovados");
		puts("[5] Exportar lista");
		printf("[6] Limpar tela\n>> ");
		scanf("%d", &rodando);

		if(rodando)
			EscolherFuncao(rodando);
	}

	// apagando o ponteiro da lista
	Lista_Deletar(lista);
	
	return 0;
}

// função para escolher a função com base no valor da variável "rodando"
void EscolherFuncao(int escolha) {
	char nome[40];
	long long int matricula;			
	float av1, av2, av3;

	switch(escolha) {
		case 1:
			// cadastra aluno
			getchar();
			printf("[NOME]: ");
			fgets(nome, 40, stdin);
			LimparString(nome);
			printf("[MATRICULA]: ");
			scanf("%lli", &matricula);
			printf("[AV1]: ");
			scanf("%f", &av1);
			printf("[AV2]: ");
			scanf("%f", &av2);
			printf("[AV3]: ");
			scanf("%f", &av3);

			Aluno_Novo(&aluno, nome, matricula, av1, av2, av3);
			Lista_Cadastrar(lista, aluno, 1);
			break;
		
		case 2:
			// mostra as informações do aluno pela matrícula
			printf("[MATRICULA]: ");
			scanf("%lli", &matricula);
			int index = Lista_Selecionar(lista, matricula, 1);

			if(index != -1)
				Aluno_Print(lista->alunos[index]);
			break;

		case 3:
			// retorna todos os alunos aprovados
			listaAprovados = Lista_SelecionarAprovados(lista);
			Lista_Print(listaAprovados);
			Lista_Deletar(listaAprovados);
			break;

		case 4:
			// retorna todos os alunos reprovados
			listaReprovados = Lista_SelecionarReprovados(lista);
			Lista_Print(listaReprovados);
			Lista_Deletar(listaReprovados);
			break;

		case 5:;
			// exporta a lista de alunos
			char caminho[256];
			getchar();
			printf("[CAMINHO]: ");
			fgets(caminho, 256, stdin);
			LimparString(caminho);
			IO_ExportarLista(lista, caminho);
			break;

		case 6:
			// limpa tela
			system("cls");
			break;
	}
}

// procedimento que retira a quebra de linha ("\n") do final da string
void LimparString(char *string) {
	int lastIndex = strlen(string) - 1;

	if(string[lastIndex] == '\n')
		string[lastIndex] = '\0';
}