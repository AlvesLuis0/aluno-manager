#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
	char nome[40];
	long long int matricula;
	float av1, av2, av3;
} Aluno;

void Aluno_Novo(Aluno*, char nome[40], long long int matricula, float av1, float av2, float av3);
void Aluno_Print(Aluno);
float Aluno_Media(Aluno);

#endif