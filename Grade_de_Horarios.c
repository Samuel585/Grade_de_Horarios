#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROFESSORES 100
#define MAX_DISCIPLINAS 10
#define MAX_NOME_LEN 50
#define MAX_TURMAS 10

int dias_s;

void dados_inst() {
    // int dias_s, turnos, horarios, turmas; // dias_s local removido, usará a global
    int turnos_local, horarios_local, turmas_local; // Renomeadas para evitar confusão se não forem globais
    // int opcao, i = 0; // Não usado em dados_inst

    printf("Instituição, digite os dias da semana disponíveis para aula: ");
    scanf("%d", &dias_s); 
    getchar(); // Consumir o \n deixado pelo scanf

    
    printf("Digite quantos horários disponíveis vocês oferecem: ");
    scanf("%d", &horarios_local); 
    getchar();

    printf("Digite quantas turmas: ");
    scanf("%d", &turmas_local); 
    getchar();

    printf("\nDias das semana: %d\n", dias_s); 
    printf("Quantos horários: %d\n", horarios_local);
    printf("Quantas turmas: %d\n\n", turmas_local);
}



void dados_prof(){ //Estabelecer função com os dados de todos os professores.
//Dados: Nome, disciplina que leciona qual turno e dias pode lecionar.    
    char prof[MAX_PROFESSORES][MAX_NOME_LEN];
    char materia[MAX_PROFESSORES][MAX_NOME_LEN];
    int opcao, i=0;
    do{
        printf("Digite 1 para cadastrar um professor ou 2 para sair: ");
        scanf("%d", &opcao);
        getchar();
        if(opcao == 1){
        
        printf("Digite o nome do professor: ");
        scanf("%49s", &prof[i]);
        getchar();
        
        printf("\nQue disciplina ele leciona? ");
        scanf("%49s", &materia[i]);
        getchar();
        
        printf("\nDigite 1 pra disponivel ou 0 pra indisponivel: \n");
        for(int k=0; k<dias_s; k++){
            int di;
            
            printf("Dia %d: ", k);
            scanf("%d", &di);
            getchar();
        }
        
        
        
        printf("%dº professor cadastrado com sucesso!\n", i+1);
        i++;
        
        
        }
    }while(opcao != 2);
    
    
}







int main(){
    char prof, materia, turma, turno;
    int disp_prof, horarios, dias;


   
 
    //(lembrar que um professor pode ter mais de uma matéria), qual turno e dias pode lecionar.
	// Protótipo feito;
	dados_inst();
	
    dados_prof();
    
    void grade();



    
    

    //Estabelecer função grade de horários.
    //Exportar CSV

    return 0;
}
