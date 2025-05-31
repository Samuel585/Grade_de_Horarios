#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROFESSORES 5
#define MAX_TURMAS 5
#define MAX_HORARIOS 6

// Vetores de strings para nomes
char professores[MAX_PROFESSORES][20];
char turmas[MAX_TURMAS][20];

// Disponibilidade dos professores: 1 = disponível, 0 = indisponível
int disponibilidade[MAX_PROFESSORES][MAX_HORARIOS];

// Matriz da grade: -1 = vaga, senão índice do professor alocado
int grade[MAX_HORARIOS];

int n_professores, n_turmas, n_horarios;

// Função para imprimir a grade atual
void imprimir_grade() {
    printf("\nGrade de horários:\n");
    for (int i = 0; i < n_horarios; i++) {
        if (grade[i] == -1) {
            printf("Horario %d: Livre\n", i);
        } else {
            printf("Horario %d: Professor %s\n", i, professores[grade[i]]);
        }
    }
}

// Função para verificar se pode alocar professor em horário
bool pode_alocar(int horario, int professor) {
    if (grade[horario] != -1) {
        // Horário já ocupado
        return false;
    }
    if (disponibilidade[professor][horario] == 0) {
        // Professor indisponível nesse horário
        return false;
    }
    return true;
}

// Função para tentar alocar turmas usando while e switch
bool alocar_turmas() {
    int turma_atual = 0;
    int prof = 0;
    int horario = 0;

    while (turma_atual < n_turmas) {
        bool alocado = false;
        prof = 0;

        // Tentar cada professor para a turma atual
        while (prof < n_professores) {
            horario = 0;

            // Tentar cada horário disponível para o professor
            while (horario < n_horarios) {
                if (pode_alocar(horario, prof)) {
                    grade[horario] = prof;
                    alocado = true;
                    break;
                } else {
                    // Usando switch para demonstrar estrutura
                    switch (grade[horario]) {
                        case -1:
                            // vaga, mas professor indisponível
                            break;
                        default:
                            // horário ocupado
                            break;
                    }
                }
                horario++;
            }

            if (alocado) {
                break;
            }
            prof++;
        }

        if (alocado) {
            printf("%s alocada com Professor %s no horário %d.\n", turmas[turma_atual], professores[grade[horario]], horario);
            turma_atual++;
        } else {
            // Se não conseguiu alocar, volta atrás (simples)
            if (turma_atual == 0) {
                // Não há solução possível
                return false;
            }
            turma_atual--;
            // Desaloca o último horário
            for (int i = 0; i < n_horarios; i++) {
                if (grade[i] != -1) {
                    grade[i] = -1;
                    break;
                }
            }
        }
    }

    return true;
}

int main() {
    // Ler número de professores, turmas e horários
    printf("Digite o número de professores (max %d): ", MAX_PROFESSORES);
    scanf("%d", &n_professores);
    if (n_professores > MAX_PROFESSORES) n_professores = MAX_PROFESSORES;

    printf("Digite o número de turmas (max %d): ", MAX_TURMAS);
    scanf("%d", &n_turmas);
    if (n_turmas > MAX_TURMAS) n_turmas = MAX_TURMAS;

    printf("Digite o número de horários no dia (max %d): ", MAX_HORARIOS);
    scanf("%d", &n_horarios);
    if (n_horarios > MAX_HORARIOS) n_horarios = MAX_HORARIOS;

    // Ler nomes dos professores
    for (int i = 0; i < n_professores; i++) {
        printf("Nome do professor %d: ", i + 1);
        scanf(" %19[^\n]", professores[i]);
    }

    // Ler nomes das turmas
    for (int i = 0; i < n_turmas; i++) {
        printf("Nome da turma %d: ", i + 1);
        scanf(" %19[^\n]", turmas[i]);
    }

    // Ler disponibilidade dos professores para cada horário
    for (int i = 0; i < n_professores; i++) {
        printf("Disponibilidade do professor %s (1-disponível, 0-indisponível) para %d horários:\n", professores[i], n_horarios);
        for (int j = 0; j < n_horarios; j++) {
            printf("  Horário %d: ", j);
            scanf("%d", &disponibilidade[i][j]);
            while (disponibilidade[i][j] != 0 && disponibilidade[i][j] != 1) {
                printf("Entrada inválida! Digite 0 ou 1: ");
                scanf("%d", &disponibilidade[i][j]);
            }
        }
    }

    // Inicializa a grade vazia
    for (int i = 0; i < n_horarios; i++) {
        grade[i] = -1;
    }

    printf("\nProcessando alocação...\n");

    if (alocar_turmas()) {
        imprimir_grade();
    } else {
        printf("Não foi possível gerar uma grade válida com as restrições atuais.\n");
    }

    return 0;
}
