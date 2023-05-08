# Gerenciador de Alunos
Este é um programa em C que permite o gerenciamento de alunos. Com este programa, você pode cadastrar
alunos, mostrar os dados dos alunos cadastrados, listar todos os aprovados e reprovados, exportar a lista
de alunos e importá-la novamente.

## Como compilar e executar o programa
Para compilar o programa, você precisará de um compilador C instalado em seu sistema. Este programa foi
testado com o compilador GCC. Para compilar, abra um terminal e navegue até o diretório onde o código-fonte
do programa está localizado. Em seguida, execute o seguinte comando:
```Powershell
gcc src/main.c src/include/@aluno.c src/include/@lista.c src/include/@io.c -o manager.exe -std=c11
```
Para executar o programa, digite o seguinte comando no terminal:
```Powershell
./manager.exe
```

## Como usar o programa
Quando o programa for executado, você verá um menu com as seguintes opções:
```Markdown
0. Sair
1. Cadastrar aluno
2. Selecionar aluno
3. Selecionar todos os alunos aprovados 
4. Selecionar todos os alunos reprovados
5. Exportar lista
6. Importar lista
7. Limpar tela
```
Para escolher uma opção, digite o número correspondente e pressione Enter.

### Sair
Ao selecionar a opção de sair, o programa será encerrado.

### Cadastrar aluno
Ao selecionar a opção de `cadastrar aluno`, você será solicitado a fornecer as informações do aluno, como
nome, matrícula e suas notas.

### Selecionar aluno
Ao selecionar a opção de `selecionar aluno`, você verá uma série de dados do aluno cadastrado, incluindo
nome, matrícula, notas, média e sua situação (_aprovado ou reprovado_).

### Selecionar todos os alunos aprovados 
Ao selecionar a opção de `selecionar todos os alunos aprovados`, você verá uma lista com os nomes,
matrículas, notas, médias e situações de todos os alunos que foram aprovados. Para ser considerado
aprovado, o aluno deve ter uma média geral maior ou igual a 6.

### Selecionar todos os alunos reprovados 
Ao selecionar a opção de `selecionar todos os alunos reprovados`, você verá uma lista com os nomes,
matrículas, notas, médias e situações de todos os alunos que foram reprovados. Para ser considerado
reprovado, o aluno deve ter uma média geral menor do que 6.

### Exportar lista
Ao selecionar a opção de `exportar lista`, você será solicitado a fornecer o nome do arquivo onde a lista
de alunos será salva. O arquivo será salvo no formato **CSV**, e poderá ser aberto em programas de planilha,
como o Microsoft Excel.

### Importar lista
Ao selecionar a opção de `importar lista`, você será solicitado a fornecer o nome do arquivo onde a lista
de alunos está salva. O arquivo deve estar no formato **CSV**, e deve conter os dados dos alunos no
seguinte formato:
```
nome,matricula,av1,av2,av3
```
Cada linha representa um aluno, e os dados são separados por vírgulas.

### Limpar tela
Ao selecionar a opção de `limpar tela`, você literalmente apagará tudo já escrito no seu _prompt_, pois
este programa escreverá muitas coisas no mesmo, e pode acabar poluindo seu _terminal_ ou apenas dificultando
a apresentação limpa dos dados.

## Conclusão
Este é um programa simples, mas muito útil para gerenciar alunos. Com ele, você pode cadastrar alunos com
seus dados e notas, listar os alunos aprovados e reprovados e exportar/importar a lista de alunos em
formato **CSV**. Espero que este programa seja útil para você!
