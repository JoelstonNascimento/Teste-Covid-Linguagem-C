#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


char nome[200];
char cpf[30];
char sexo[5];
int idade;
int main();

void perguntas(){
	
	char r1,r2,r3,r4,r5,r6,r7,r8,r9,r10;
	int soma;  
	
	FILE *arquivo;
	arquivo=fopen("CadastrosCovid.txt", "a");
	if(arquivo==NULL){
		printf("Erro no arquivo");
		}
		
	system("cls");
	printf("Responda as perguntas abaixo com S ou N.\n");
	printf("---------------------------------------\n");
	
	printf("Tem Febre? ",setlocale(LC_ALL, "Portuguese"));
	scanf("%c", &r1);
	fflush(stdin);
	fprintf(arquivo,"Tem Febre?%c\n",r1);
	if (r1=='S'||r1=='s'){
		soma=soma+5;}
		
	printf("Tem dor de cabeça? ",setlocale(LC_ALL, "Portuguese"));
	scanf("%c", &r2);
	fflush(stdin);
	fprintf(arquivo,"Tem dor de cabeça?%c\n",r2);
	if (r2=='S'||r2=='s'){
		soma=soma+1;}
		
	printf("Tem secreção nasal ou espirros? ",setlocale(LC_ALL, "Portuguese"));
	scanf("%c", &r3);
	fflush(stdin);
	fprintf(arquivo,"Tem secreção nasal ou espirros?%c\n",r3);
	if (r3=='S'||r3=='s'){
		soma=soma+1;}
		
	printf("Tem dor/irritação na garganta? ",setlocale(LC_ALL, "Portuguese"));
	scanf("%c", &r4);
	fflush(stdin);
	fprintf(arquivo,"Tem dor/irritação na garganta?%c\n",r4);
	if (r4=='S'||r4=='s'){
		soma=soma+1;}
		
	printf("Tem tosse seca? ",setlocale(LC_ALL, "Portuguese"));
	scanf("%c", &r5);
	fflush(stdin);
	fprintf(arquivo,"Tem tosse seca?%c\n",r5);
	if (r5=='S'||r5=='s'){
		soma=soma+3;}
		
	printf("Tem dificuldade respiratória? ",setlocale(LC_ALL, "Portuguese"));
	scanf("%c", &r6);
	fflush(stdin);
	fprintf(arquivo,"Tem dificuldade respiratória?%c\n",r6);
	if (r6=='S'||r6=='s'){
		soma=soma+10;}
		
	printf("Tem dores no corpo? ",setlocale(LC_ALL, "Portuguese"));
	scanf("%c", &r7);
	fflush(stdin);
	fprintf(arquivo,"Tem dores no corpo?%c\n",r7);
	if (r7=='S'||r7=='s'){
		soma=soma+1;}
		
	printf("Tem diarréia? ",setlocale(LC_ALL, "Portuguese"));
	scanf("%c", &r8);
	fflush(stdin);
	fprintf(arquivo,"Tem diarréia?%c\n",r8);
	if (r8=='S'||r8=='s'){
		soma=soma+1;}
		
	printf("Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19? ",setlocale(LC_ALL, "Portuguese"));
	scanf("%c", &r9);
	fflush(stdin);
	fprintf(arquivo,"Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19?%c\n",r9);
	if (r9=='S'||r9=='s'){
		soma=soma+10;}
		
	printf("Esteve em locais com grande aglomeração? ",setlocale(LC_ALL, "Portuguese"));
	scanf("%c", &r10);
	fflush(stdin);
	fprintf(arquivo,"Esteve em locais com grande aglomeração?%c\n",r10);
	if (r10=='S'||r10=='s'){
    	soma=soma+3;}
    	
    system("cls");
    
    system("cls");
    
    
    if(soma>=0 && soma<10){
    	printf("%d Pontos é considerado risco baixo e o paciente deverá ser encaminhado para ala de baixo risco.\n\n",soma,setlocale(LC_ALL, "Portuguese"));
    	fprintf(arquivo,"\n%d Pontos é considerado risco baixo e o paciente deverá ser encaminhado para ala de baixo risco.\n\n---------------------\n\n",soma);
	}
	
	if(soma>=10 && soma<20){
		printf( "%d Pontos é considerado risco médio e o paciente deverá ser encaminhado para ala de médio risco.\n\n",soma,setlocale(LC_ALL, "Portuguese"));
		fprintf(arquivo,"\n%d Pontos é considerado risco médio e o paciente deverá ser encaminhado para ala de médio risco.\n\n---------------------\n\n",soma);
	}

    if(soma>=20){
    	printf("%d Pontos é considerado risco alto e o paciente deverá ser encaminhado para ala de alto risco.\n\n",soma,setlocale(LC_ALL, "Portuguese"));
    	fprintf(arquivo,"\n%d Pontos é considerado risco alto e o paciente deverá ser encaminhado para ala de alto risco.\n\n---------------------\n\n",soma);
	}
	
	
	printf("Pressione enter para voltar ao menu principal...\n\n");
	getchar();
	system("cls");
	fclose(arquivo);
	main();
		
}

void cadastro(){
	setlocale(LC_ALL, "Portuguese");
	FILE *arquivo;
	arquivo=fopen("CadastrosCovid.txt", "a");
	if(arquivo==NULL){
		printf("Erro no arquivo",setlocale(LC_ALL, "Portuguese"));
		}
	printf("\nInforme o nome do paciente: ",setlocale(LC_ALL, "Portuguese"));
	scanf("%s", nome);
	fflush(stdin);
	
	printf("\nInforme o CPF do paciente: ",setlocale(LC_ALL, "Portuguese"));
	scanf("%s", cpf);
	fflush(stdin);
	
	printf("\nInforme o sexo do paciente(M/F): ",setlocale(LC_ALL, "Portuguese"));
	scanf("%s", sexo);
	fflush(stdin);
	
	printf("\nInforme a idade do paciente: ",setlocale(LC_ALL, "Portuguese"));
	scanf("%d", &idade);
	fflush(stdin);
	
	fprintf(arquivo,"Nome:%s\nCPF:%s\nSexo:%s\nidade:%d\n\n",nome,cpf,sexo,idade);
	fclose(arquivo);
	printf("\nDados gravados com sucesso!\nPressione enter para continuar...\n",setlocale(LC_ALL, "Portuguese"));
	getchar();
	
	perguntas();
}


int main(){
	
	int escolha;
	
	printf("****************Menu****************\n");
	printf("Selecione uma das opções abaixo.\n1 - Fazer cadastro do paciente.\n0 - sair.\n",setlocale(LC_ALL, "Portuguese"));
	scanf("%d", &escolha);
	fflush(stdin);
	
	switch(escolha){
		case 1:
			cadastro();
			break;
		case 0:
			printf("Você saiu do programa...",setlocale(LC_ALL, "Portuguese"));
			break;
		default:
			break;
		
	}		
	
}





