#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a struct Tarefa
typedef struct {
    char descricao[100];
    char data[11];    // Data no formato DD/MM/AAAA
    int prioridade;   // 1 para alta, 2 para média, 3 para baixa
    int concluida;    // 0 para não concluída, 1 para concluída
} Tarefa;

// Definindo a lista de tarefas e a quantidade total
Tarefa listaDeTarefas[100];
int totalTarefas = 0;

// Funções para manipulação de tarefas
void adicionarTarefa(Tarefa *lista, int *total);
void removerTarefa(Tarefa *lista, int *total, int indice);
void concluirTarefa(Tarefa *lista, int indice);
void listarTarefas(Tarefa *lista, int total);
void salvarTarefasTexto(Tarefa *lista, int total);
void salvarTarefasBinario(Tarefa *lista, int total);
void carregarTarefasTexto(Tarefa *lista, int *total);
void carregarTarefasBinario(Tarefa *lista, int *total);

int main() {
    int opcao;
    do {
        printf("\n--- Sistema de Gestão de Tarefas ---\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Remover Tarefa\n");
        printf("3. Marcar Tarefa como Concluída\n");
        printf("4. Listar Tarefas\n");
        printf("5. Salvar Tarefas\n");
        printf("6. Carregar Tarefas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                adicionarTarefa(listaDeTarefas, &totalTarefas);
                break;
            case 2:
                if (totalTarefas > 0) {
                    int indice;
                    printf("Digite o índice da tarefa para remover: ");
                    scanf("%d", &indice);
                    removerTarefa(listaDeTarefas, &totalTarefas, indice);
                } else {
                    printf("Nenhuma tarefa disponível para remover.\n");
                }
                break;
            case 3:
                if (totalTarefas > 0) {
                    int indice;
                    printf("Digite o índice da tarefa para marcar como concluída: ");
                    scanf("%d", &indice);
                    concluirTarefa(listaDeTarefas, indice);
                } else {
                    printf("Nenhuma tarefa disponível para concluir.\n");
                }
                break;
            case 4:
                listarTarefas(listaDeTarefas, totalTarefas);
                break;
            case 5:
                salvarTarefasTexto(listaDeTarefas, totalTarefas);
                salvarTarefasBinario(listaDeTarefas, totalTarefas);
                break;
            case 6:
                carregarTarefasTexto(listaDeTarefas, &totalTarefas);
                carregarTarefasBinario(listaDeTarefas, &totalTarefas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

// Função para adicionar uma tarefa
void adicionarTarefa(Tarefa *lista, int *total) {
    if (*total < 100) {
        Tarefa novaTarefa;
        printf("Digite a descrição da tarefa: ");
        fgets(novaTarefa.descricao, 100, stdin);
        novaTarefa.descricao[strcspn(novaTarefa.descricao, "\n")] = 0; // Remover o '\n'

        printf("Digite a data (DD/MM/AAAA): ");
        fgets(novaTarefa.data, 11, stdin);
        novaTarefa.data[strcspn(novaTarefa.data, "\n")] = 0; // Remover o '\n'

        printf("Digite a prioridade (1: Alta, 2: Média, 3: Baixa): ");
        scanf("%d", &novaTarefa.prioridade);
        getchar(); // Limpar o buffer do teclado

        novaTarefa.concluida = 0;
        lista[*total] = novaTarefa;
        (*total)++;
        printf("Tarefa adicionada com sucesso!\n");
    } else {
        printf("Limite máximo de tarefas atingido!\n");
    }
}

// Função para remover uma tarefa
void removerTarefa(Tarefa *lista, int *total, int indice) {
    if (indice >= 0 && indice < *total) {
        for (int i = indice; i < *total - 1; i++) {
            lista[i] = lista[i + 1];
        }
        (*total)--;
        printf("Tarefa removida com sucesso!\n");
    } else {
        printf("Índice inválido!\n");
    }
}

// Função para marcar uma tarefa como concluída
void concluirTarefa(Tarefa *lista, int indice) {
    if (indice >= 0 && indice < totalTarefas) {
        lista[indice].concluida = 1;
        printf("Tarefa marcada como concluída!\n");
    } else {
        printf("Índice inválido!\n");
    }
}

// Função para listar as tarefas
void listarTarefas(Tarefa *lista, int total) {
    if (total > 0) {
        printf("\n--- Lista de Tarefas ---\n");
        for (int i = 0; i < total; i++) {
            printf("%d. %s - %s (Prioridade: %d) [%s]\n", 
                   i, lista[i].descricao, lista[i].data, lista[i].prioridade, 
                   lista[i].concluida ? "Concluída" : "Pendente");
        }
    } else {
        printf("Nenhuma tarefa disponível.\n");
    }
}

// Função para salvar tarefas concluídas em um arquivo de texto
void salvarTarefasTexto(Tarefa *lista, int total) {
    FILE *arquivo = fopen("tarefas_concluidas.txt", "w");
    if (arquivo != NULL) {
        for (int i = 0; i < total; i++) {
            if (lista[i].concluida == 1) {
                fprintf(arquivo, "%s - %s (Prioridade: %d)\n", lista[i].descricao, lista[i].data, lista[i].prioridade);
            }
        }
        fclose(arquivo);
        printf("Tarefas concluídas salvas em 'tarefas_concluidas.txt'.\n");
    } else {
        printf("Erro ao salvar tarefas concluídas.\n");
    }
}

// Função para salvar tarefas pendentes em um arquivo binário
void salvarTarefasBinario(Tarefa *lista, int total) {
    FILE *arquivo = fopen("tarefas_pendentes.bin", "wb");
    if (arquivo != NULL) {
        fwrite(lista, sizeof(Tarefa), total, arquivo);
        fclose(arquivo);
        printf("Tarefas pendentes salvas em 'tarefas_pendentes.bin'.\n");
    } else {
        printf("Erro ao salvar tarefas pendentes.\n");
    }
}

// Função para carregar tarefas concluídas de um arquivo de texto
void carregarTarefasTexto(Tarefa *lista, int *total) {
    FILE *arquivo = fopen("tarefas_concluidas.txt", "r");
    if (arquivo != NULL) {
        char linha[150];
        while (fgets(linha, sizeof(linha), arquivo)) {
            Tarefa novaTarefa;
            sscanf(linha, "%[^-] - %[^ ] (Prioridade: %d)", novaTarefa.descricao, novaTarefa.data, &novaTarefa.prioridade);
            novaTarefa.concluida = 1;
            lista[*total] = novaTarefa;
            (*total)++;
        }
        fclose(arquivo);
        printf("Tarefas concluídas carregadas de 'tarefas_concluidas.txt'.\n");
    } else {
        printf("Erro ao carregar tarefas concluídas.\n");
    }
}

// Função para carregar tarefas pendentes de um arquivo binário
void carregarTarefasBinario(Tarefa *lista, int *total) {
    FILE *arquivo = fopen("tarefas_pendentes.bin", "rb");
    if (arquivo != NULL) {
        *total = fread(lista, sizeof(Tarefa), 100, arquivo);
        fclose(arquivo);
        printf("Tarefas pendentes carregadas de 'tarefas_pendentes.bin'.\n");
    } else {
        printf("Erro ao carregar tarefas pendentes.\n");
    }
}
