#ifndef LISTA_H
#define LISTA_H

#include "aluno.h"

typedef struct {
	Aluno *alunos;
	unsigned int tamanho;
} Lista;

Lista* Lista_Nova();
void Lista_Print(Lista*);
void Lista_Cadastrar(Lista*, Aluno, int comAvisos);
int Lista_Selecionar(Lista*, long long int matricula, int comAvisos);
Lista* Lista_SelecionarAprovados(Lista*);
Lista* Lista_SelecionarReprovados(Lista*);
void Lista_Deletar(Lista*);

#endif