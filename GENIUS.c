#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

enum boolean {
    true = 1, false = 0
};
typedef  enum boolean  bool;

int menu();
void nome(char usu_nome[20]);
int random();

main() {
	setlocale(LC_ALL, "portuguese");
	unsigned short int vet[256], re[256], i, aux = 0, fase = 1, num = 3, qtd_num = 1, escolha;
	char usu1[20], usu2[20], reload;
	bool jog_1, acertos;
	//função do Menu
	
	escolha = menu();
	system("cls");
	
	//UM JOGADOR
	if (escolha == 1) {
		
		nome(usu1);
		system("cls");
		
		 do{
			jog_1 = true;
			acertos = true;
		 	srand(time(NULL));
		 	
			//alocação do valor
			random(vet, qtd_num, i, num);
			//valor randomizado
			for(i = 0; i< qtd_num; i++){
				system("cls");
				printf("%d ", vet[i]);
				sleep(1.6);
				system("cls");
			}
			
			//pergunta ao usuario
			for(i = 0; i< qtd_num; i++){
				printf("\n\n\tqual o número na posição %d ? ", i + 1);
				scanf("%d", &re[i]);
				system("cls");
			}
			//verificação do valor
			for(i = 0; i < qtd_num; i++){
				if(re[i] != vet[i]){		
					acertos = false;
				}	
			}	
			if (acertos == true){
				printf("VOCÊ ACERTOU\n");
				sleep(0.5);
				qtd_num++;
				
			}
			if(acertos == false){
				printf("VOCÊ ERROU AMIGO(A), MAS NÃO FIQUE TRISTE");
				printf("\nVOCÊ PAROU NO NÍVEL %d, %s", fase, usu1);
				qtd_num = 1;
				sleep(3);
				system("cls");
				jog_1 = false;
			}		
			if(qtd_num % 10 == 0){
				fase++;
				num = num + 3;
			}
			
		}while(jog_1 == true);	 	
		
		system("cls");
		
		printf("\nVocê deseja continuar jogando? \nSIM OU NÃO \n\tresposta: ");
		scanf("%s", &reload);
		
		if((reload == 's')||(reload == 'sim')||(reload == 'SIM')){
			system("cls");
			main();
		}else{
			printf("\n\n\tAté a proxima\n\n");
			_sleep (2000);
			exit;
		}
	}
	//DOIS JOGADORES
	if(escolha == 2){
		
		printf("\t\tDOIS JOGADORES\n");
		sleep(2);
		system("cls");
		
		nome(usu1);
		nome(usu2);
	}
	//INSTRUÇÕES 
	if(escolha == 3){
		printf("-----------------------------------INSTRUÇÕES-----------------------------------\n");
	printf("1.Repita a sequência\n2.Crie sua própria sequência\n3.Repita a seqüência, agora apertando somente um número\n\n");
	printf("\t\t\tNIVEIS DE DIFICULDADE:\n");
	printf("Nivel 1: 3 números\nNivel 2: 6 números\nNivel 3: 9 números\nNivel 4: 12 números\n\n");
	printf("LCMD produções ©\n");
	sleep(8);
	system("cls");
	main();
	}
	//SAIR
	if(escolha == 4){
		system("cls");
		printf("\n\tATÉ A PROXIMA...\n\n");
		system("pause");
	}
}		
//Menu
int menu(){
	
	int escolha = 0;
	
	do{
		printf("\t\t\tGENIUS\n\n\tO que deseja fazer?\n\n 1 - 1 JOGADOR \n\n 2 - 2 JOGADORES\n\n 3 - INSTRUÇÕES\n\n 4 - SAIR DO JOGO\n\n Opção\a: ");
		scanf("%d", &escolha);
		if (escolha!=1||escolha!=4||escolha!=3||escolha!=2) {
			system("cls");
		}
	} while((escolha <1)||(escolha>4));
	
	return escolha;
}
	
void nome(char usu_nome[20]){
	
	char usu1[20], usu2[20];
	
		do{	
			printf("Por favor, digite seu nome: ");
		 	fflush(stdin);
		 	scanf("%[^\n]", usu_nome);		
	 }while(strlen(usu_nome) >= 20);
			 
}	

int random(){
	
	unsigned short int vet[256], qtd_num, i, num = 3;
	
	for(i = qtd_num - 1 ; i< qtd_num; i++){
			vet[i] = rand() % num + 1;		
	}
	
}
