#include <stdio.h>
#include <string.h>

#include "aluno.h"

// procedimento que inicializa um aluno com os atributos passados como parâmetros
void Aluno_Novo(Aluno *aluno, char nome[40], long long int matricula, float av1, float av2, float av3) {
	strcpy(aluno->nome, nome);
	aluno->matricula = matricula;
	aluno->av1 = av1 < 4 ? 0 : av1;
	aluno->av2 = av2 < 4 ? 0 : av2;
	aluno->av3 = av3;
}

// procedimento para apresentar todos os valores do aluno
void Aluno_Print(Aluno aluno) {
	float media = Aluno_Media(aluno);

	puts("+-----------+---------- ALUNO -------------------------+");
	printf("| NOME      | %-40s |\n", aluno.nome);
	puts("+-----------+------------------------------------------+");
	printf("| MATRICULA | %-40lli |\n", aluno.matricula);
	puts("+-----------+------------------------------------------+");
	printf("| AV1       | %-40.1f |\n", aluno.av1);
	puts("+-----------+------------------------------------------+");
	printf("| AV2       | %-40.1f |\n", aluno.av2);
	puts("+-----------+------------------------------------------+");
	printf("| AV3       | %-40.1f |\n", aluno.av3);
	puts("+-----------+------------------------------------------+");
	printf("| MEDIA     | %-40.1f |\n", media);
	puts("+-----------+------------------------------------------+");
	printf("| SITUACAO  | %-40s |\n", media >= 6 ? "APROVADO" : "REPROVADO");
	puts("+-----------+------------------------------------------+\n");
}

// função que retorna a média do aluno
float Aluno_Media(Aluno aluno) {
	if(aluno.av1 < aluno.av3 || aluno.av2 < aluno.av3) {
		// qual é a menor nota?
		int deveTrocarAV = (aluno.av1 > aluno.av2) + 1;

		if(deveTrocarAV == 1)
			aluno.av1 = aluno.av3;
		
		else
			aluno.av2 = aluno.av3;
	}

	return (aluno.av1 + aluno.av2) / 2;
}