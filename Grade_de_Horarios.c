#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROFESSORES 100
#define MAX_DISCIPLINAS 10
#define MAX_NOME_LEN 50
#define MAX_TURMAS 10


// Definição de uma estrutura para armazenar os dados dos professores

typedef struct{
    char nome[MAX_NOME_LEN];
    char disciplina[MAX_NOME_LEN];
    bool disponivel[7];
    int aulas_pors;
    
} Professor;

typedef struct{
    int dias_s;
    int horarios_dia;
    int total_turmas;
} Instituicao;




void dados_inst(Instituicao *inst) {
    // int dias_s, turnos, horarios, turmas; // dias_s local removido, usará a global
    //int turnos_local, horarios_local, turmas_local; // Renomeadas para evitar confusão se não forem globais
    // int opcao, i = 0; // Não usado em dados_inst

    printf("Instituicao, digite os dias da semana disponiveis para aula: ");
    scanf("%d", &inst->dias_s); 
    getchar(); 

    
    printf("Digite quantos horários disponiveis vocês oferecem: ");
    scanf("%d", &inst->horarios_dia); 
    getchar();

    printf("Digite quantas turmas: ");
    scanf("%d", &inst->total_turmas); 
    getchar();

    printf("\nDias das semana: %d\n", inst->dias_s); 
    printf("Quantos horários: %d\n", inst->horarios_dia);
    printf("Quantas turmas: %d\n\n", inst->total_turmas);
    
    int somatorio = (inst->dias_s) * (inst->horarios_dia) * (inst->total_turmas);
    printf("somatorio de aulas: %d\n", somatorio);
}


void dados_prof(Professor profs[], int *qtd_professores, int dias_s){ //Estabelecer função com os dados de todos os professores.
//Dados: Nome, disciplina que leciona qual turno e dias pode lecionar.    
    char prof[MAX_PROFESSORES][MAX_NOME_LEN];
    char materia[MAX_PROFESSORES][MAX_NOME_LEN];
    int aulas_semanais;
    int opcao, i=0;
    do{
        printf("Digite 1 para cadastrar um professor ou 2 para sair: ");
        scanf("%d", &opcao);
        getchar();
        if(opcao == 1){
        
        printf("Digite o nome do professor: ");
        scanf("%49s", profs[i].nome);
        getchar();
        
        printf("\nQue disciplina ele leciona? ");
        scanf("%49s", profs[i].disciplina);
        getchar();
        
        printf("\nQuantas aulas por semana? ");
        scanf("%d", &profs[i].aulas_pors);
        getchar();
        
        printf("\nDigite 1 pra disponivel ou 0 pra indisponivel: \n");
        for(int k=0; k<dias_s; k++){
            int di;   
            
            printf("Dia %d: ", k+1);
            scanf("%d", &di);
            getchar();
            profs[i].disponivel[k] = (di == 1);
        }
        
        
        
        printf("Professor %d cadastrado com sucesso!\n", i+1);
        i++;
        
        
        }
    }while(opcao != 2 && i < MAX_PROFESSORES);
    *qtd_professores = i;
    
    
}

void prof_disponivel(int dia_atual, Professor profs[], int qtd_professores){
    for(int a=0; a<qtd_professores; a++){
    if(profs[a].disponivel[dia_atual] == true){
        printf("Dia %d: disponivel", a+1);
    }
}


void grade(Instituicao *inst, Professor profs[], int qtd_professores) {
    
    char grade[inst->dias_s][inst->horarios_dia][inst->total_turmas][50];
    for(int dia=0; dia<inst->dias_s; dia++){
        for(int horar=0; horar<inst->horarios_dia; horar++){
            for(int turm=0; turm<inst->total_turmas; turm++){
                
            }
        }
    }
    

}


int main(){
    char prof, materia, turma, turno;
    int disp_prof, horarios, dias;
    int qtd_professores = 0; // Adicionada declaração e inicialização
    int dias_s = 0;
    Instituicao inst;
    Professor profs[MAX_PROFESSORES];


    dados_inst(&inst);


   
 
    //(lembrar que um professor pode ter mais de uma matéria), qual turno e dias pode lecionar.
    // Protótipo feito;
    
    
    dados_prof(profs, &qtd_professores, inst.dias_s);
    

    grade(&inst);
    prof_disponivel(&inst);


    
    

    //Estabelecer função grade de horários.
    //Exportar CSV

    return 0;
}
