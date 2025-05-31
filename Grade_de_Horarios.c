#include <stdio.h>
#define MAX_PROFESSORES 5
#define disciplinas 5
#define turnos 3

void dados_prof(){
    char prof[MAX_PROFESSORES], turno[turnos];
    char materia[disciplinas]; 
    int opcao, i=0;
    do{
        printf("Digite 1 para cadastrar um professor ou 2 para sair: ");
        scanf("%d", &opcao);
        if(opcao == 1){
        
        printf("Digite o nome do professor: ");
        scanf("%s", &prof[i]);
        printf("\nQue disciplina ele leciona? ");
        scanf("%s", &materia[i]);
        printf("Qual turno ele leciona? (M, V, N): ");
        scanf("%s", &turno[i]);
        printf("%dº cadastrado com sucesso!\n", i+1);
        i++;
        }
    }while(opcao != 2);
    
    
}

int main(){
    char prof, materia, turma, turno;
    int disp_prof, horarios, dias;

    //Estabelecer função com os dados de todos os professores.
    //Dados: Nome, disciplina que leciona (lembrar que um professor pode ter mais de uma matéria), qual turno e dias pode lecionar.
    dados_prof();
    



    
    //Estabelecer função com dados dos horários
    //Quais dias das semana e turnos a escola possui.

    //Estabelecer função grade de horários.
    //Exportar CSV
    return 0;
}