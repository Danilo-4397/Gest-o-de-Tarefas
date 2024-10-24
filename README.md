# Gestâo-de-Tarefas

# Sistema de Gestão de Tarefas

## Descrição
O **Sistema de Gestão de Tarefas** é um programa desenvolvido em C que permite o gerenciamento de tarefas pessoais. As funcionalidades incluem adicionar, remover, concluir e listar tarefas. As informações são armazenadas em arquivos binários e de texto, garantindo que os dados possam ser recuperados posteriormente.

Este projeto foi desenvolvido como parte de um exercício acadêmico, com o objetivo de aplicar conceitos de manipulação de arquivos, structs, arrays, ponteiros e o uso correto de versionamento com GitLab.

## Funcionalidades
- **Adicionar Tarefa**: Permite criar uma nova tarefa com descrição, data e prioridade.
- **Remover Tarefa**: Remove uma tarefa específica da lista.
- **Concluir Tarefa**: Marca uma tarefa como concluída.
- **Listar Tarefas**: Exibe todas as tarefas cadastradas, indicando as concluídas e pendentes.
- **Salvar Tarefas**:
  - Salvar tarefas pendentes em um arquivo binário (`tarefas_pendentes.bin`).
  - Salvar tarefas concluídas em um arquivo de texto (`tarefas_concluidas.txt`).
- **Carregar Tarefas**: Carrega tarefas armazenadas dos arquivos binários e de texto para o sistema.

## Requisitos
Para compilar e executar o programa, você precisará de:
- Um compilador C (ex.: GCC)
- Git para versionamento e controle do repositório
- Acesso ao GitLab para o controle do projeto

## Compilação e Execução
### Compilação
Para compilar o programa, abra o terminal na pasta do projeto e use o seguinte comando:

```bash
gcc main.c -o gestao_de_tarefas
```

### Execução
Para executar o programa, utilize o comando abaixo:

```bash
./gestao_de_tarefas
```

### Ambiente de Desenvolvimento
Este projeto foi desenvolvido e testado no ambiente:
- **Sistema Operacional**: Linux/Windows
- **Compilador**: GCC

## Uso do Programa
O programa apresenta um menu interativo com as seguintes opções:

```
--- Sistema de Gestão de Tarefas ---
1. Adicionar Tarefa
2. Remover Tarefa
3. Marcar Tarefa como Concluída
4. Listar Tarefas
5. Salvar Tarefas
6. Carregar Tarefas
0. Sair
Escolha uma opção:
```

### Instruções para Uso
1. **Adicionar Tarefa**:
   - Escolha a opção `1`.
   - Insira a descrição, data e prioridade da tarefa.
   
2. **Remover Tarefa**:
   - Escolha a opção `2`.
   - Insira o índice da tarefa a ser removida.

3. **Marcar Tarefa como Concluída**:
   - Escolha a opção `3`.
   - Insira o índice da tarefa a ser marcada como concluída.

4. **Listar Tarefas**:
   - Escolha a opção `4` para visualizar todas as tarefas.

5. **Salvar Tarefas**:
   - Escolha a opção `5` para salvar as tarefas atuais em arquivos.

6. **Carregar Tarefas**:
   - Escolha a opção `6` para carregar tarefas dos arquivos existentes.

## Estrutura dos Arquivos
### Arquivo Binário: `tarefas_pendentes.bin`
Este arquivo armazena as tarefas pendentes. Os dados são armazenados de forma binária para maior eficiência. Use as funções `salvarTarefasBinario` e `carregarTarefasBinario` para manipulação.
