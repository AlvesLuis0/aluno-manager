# Aluno Manager
Programa em C que faz um cadastro de alunos.

## Quais funções te fornece?
- [x] Cadastra um aluno;
- [x] Tira a média do aluno;
- [x] Mostra as informações do aluno;
- [x] Retorna um aluno a partir de sua matrícula;
- [x] Retorna todos os alunos aprovados;
- [x] Retorna todos os alunos reprovados;
- [x] Exporta lista de alunos para arquivo _CSV_;
- [x] Importa lista de alunos de arquivo _CSV_;

## TODO:
- [ ] Criar o typedef struct Aluno com os atributos:
	* `char nome[40];`
	* `int matricula;`
	* `float av1;`
	* `float av2;`
	* `float av3;`

- [ ] Função que atribui os valores de um aluno com os parâmetros passados:
	* `Aluno *aluno, // isso é o ponteiro do aluno`
	* `char nome[40],`
	* `int matricula,`
	* `float av1,`
	* `float av2,`
	* `float av3`

- [ ] Função que retorna a média de um Aluno, passando apenas o `Aluno aluno` como parâmetro;

- [ ] Função que printa _nome, matrícula, av1, av2, av3, média e situação ("APROVADO" ou "REPROVADO")_ do aluno, passando apenas o parâmetro `Aluno aluno`;