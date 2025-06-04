#include <stdio.h>
#include <stdbool.h>

#define MAX_PROFESSORES 5
#define MAX_disciplinas 5
#define MAX_t 3
#define MAX_d_s 6
#define MAX_horas_d 6
#define MAX_TURMAS 10

void dados_inst(){
    int dias_s[MAX_d_s], turnos[MAX_t], horarios[MAX_horas_d], turmas[MAX_TURMAS];
    int opcao, i = 0;
    printf("Instituição, digite os dias da semana disponíveis para aula: \n"); 
    scanf("%d", &dias_s[i]);
    //vamos trabalhar apenas com um turno agora
    //printf("Quantos turnos vocês oferecem? \n");
    //scanf("%d", &turnos[i]);
    //adcionar: diferentes turnos tem diferentes quantidades de horários
    printf("Digite quantos horários disponíveis vocês oferecem: \n");
    scanf("%d", &horarios[i]);
    
    printf("Digite quantos turmas: \n");
    scanf("%d", &turmas[i]);
    i++;
}



void dados_prof(){ //Estabelecer função com os dados de todos os professores.
//Dados: Nome, disciplina que leciona qual turno e dias pode lecionar.    
    char prof[MAX_PROFESSORES], turno[MAX_t];
    char materia[MAX_disciplinas]; 
    int opcao, i=0;
    do{
        printf("Digite 1 para cadastrar um professor ou 2 para sair: ");
        scanf("%d", &opcao);
        if(opcao == 1){
        
        printf("Digite o nome do professor: ");
        scanf("%s", &prof[i]);
        printf("\nQue disciplina ele leciona? ");
        scanf("%s", &materia[i]);
        //printf("Qual turno ele leciona? (M, V, N): ");
        //scanf("%s", &turno[i]);
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
	printf("Dias das semana: %d", dias_s);
	printf("Quantos turnos: %d", turnos[i]);
	printf("Quantos horários: %d", horarios[i]);
	printf("Quantas turmas: %d");
    dados_prof();  



    
    

    //Estabelecer função grade de horários.
    //Exportar CSV

    return 0;
}
