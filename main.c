#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define true 1
#define false 0

int menu();
void nome(char usu_nome[20]);

main() {
	setlocale(LC_ALL, "portuguese");
	unsigned short int vet[256], rejog1[256], rejog2[256], i, aux = 0, fase = 1, num = 3, qtd_num = 1, escolha;
	char usu1[20], usu2[20], reload;
	int jog_1, jog_2;
	//MENU
	escolha = menu();
	system("cls");
	//UM JOGADOR
	if (escolha == 1) {
		nome(usu1);
		system("cls");
		 do{
			jog_1 = true;
		 	srand(time(NULL));
			//alocação do valor
			for(i = qtd_num - 1 ; i< qtd_num; i++){
				vet[i] = rand() % num + 1;	
			}	
			for(i = 0; i< qtd_num; i++){
				system("cls");
				printf("%d ", vet[i]);
				sleep(1.6);
				system("cls");
			}
			//pergunta ao usuario
			for(i = 0; i< qtd_num; i++){
				printf("\n\tQual o número na posição %d? ", i + 1);
				scanf("%d", &rejog1[i]);
				fflush(stdin);
				system("cls");
				if(rejog1[i] != vet[i]){
					printf("VOCÊ ERROU AMIGO(A), MAS NÃO FIQUE TRISTE");
					printf("\nVOCÊ PAROU NO NÍVEL %d, %s", fase, strupr(usu1));
					qtd_num = 1;
					sleep(3);
					system("cls");
					jog_1 = false;	
				}	
			}
			printf("VOCÊ ACERTOU\n");
			sleep(1);
			qtd_num++;		
					
			if(qtd_num % 10 == 0){
				fase++;
				num = num + 3;
			}	
		}while(jog_1 == true);	 	
		
		system("cls");
		printf("\nVocê deseja continuar jogando? \nSIM OU NÃO \n\tresposta: ");
		scanf("%s", &reload);
		
		if((reload == 's')||(reload == 'sim')||(reload == 'SIM')||(reload == 'S')){
			system("cls");
			main();
		}else{
			printf("\n\n\tAté a proxima\n\n");
			sleep (2);
			exit;
		}
	}
	//DOIS JOGADORES
	if(escolha == 2){
		printf("\t\tDOIS JOGADORES\n\a");
		sleep(2);
		system("cls");
		printf("\n\n\tPRIMEIRO JOGADOR\n");
		nome(usu1);
		system("cls");
		printf("\n\n\tSEGUNDO JOGADOR\n");
		nome(usu2);
		system("cls");
			jog_1 = true;
			jog_2 = true;
		 	srand(time(NULL));
		 	do{
				//alocação do valor 1 
				for(i = qtd_num-1; i< qtd_num; i++){
					vet[i] = rand() % num + 1;
				}
				for(i = 0; i< qtd_num; i++){
					system("cls");
					printf("%d ", vet[i]);
					sleep(1.6);
					system("cls");
				}
				//pergunta ao jogador 1	
				printf("VEZ DE %s",strupr(usu1));
				sleep(0.5);
				for(i = 0; i < qtd_num; i++){
					printf("\n\tQual o número na posição %d? ", i + 1);
					scanf("%d", &rejog1[i]);
					fflush(stdin);
					system("cls");
					if(rejog1[i] != vet[i]){
						printf("\n\t%s PERDEU, %s GANHOU", strupr(usu1),strupr(usu2));
						printf("\n\tVOCÊ PAROU NO NÍVEL %d, %s",fase,strupr(usu1));
						qtd_num = 1;
						sleep(3);
						system("cls");
						jog_1 = false;							
					}		
				}
				if (jog_1 == true){
					qtd_num++;
					//alocação do valor 2
					for(i=qtd_num-1; i<qtd_num; i++) {
						vet[i]=rand() % num + 1;
					}
					for(i = 0; i< qtd_num; i++){
						system("cls");
						printf("%d ", vet[i]);
						sleep(1.6);
						system("cls");
					}
					//pergunta para jogador 2
					printf("VEZ DE %s",strupr(usu2));
					sleep(0.5);
					for(i = 0; i < qtd_num; i++){
						printf("\n\tQual o número na posição %d? ", i + 1);
						scanf("%d", &rejog2[i]);
						system("cls");
						if(rejog2[i] != vet[i]){		
							printf("\n\t%s PERDEU, %s GANHOU", strupr(usu2),strupr(usu1));
							printf("\n\tVOCÊ PAROU NO NÍVEL %d, %s", fase, strupr(usu2));
							qtd_num = 1;
							sleep(3);
							system("cls");
							jog_2 = false;          
						}
					}
					qtd_num++;
					if(qtd_num % 10 == 0){
						fase++;
						num = num + 3;
					}
				}
			}while((jog_1 == true)&&(jog_2 == true));
			system("cls");
			printf("\n\t\tVocês desejam continuar jogando? \n\tSIM OU NÃO \n\tresposta: ");
			scanf("%s", &reload);
		
			if((reload == 's')||(reload == 'sim')||(reload == 'SIM')||(reload == 'S')){
				system("cls");
				main();
			}
			else{
				printf("\n\n\tAté a proxima\n\n");
				sleep (2);
				exit;
			}	
	}
	//INSTRUÇÕES 
	if(escolha == 3){
		printf("-----------------------------------INSTRUÇÕES-----------------------------------\n");
		printf("1.Repita a sequência\n2.Crie sua própria sequência\n3.Repita a seqüência, agora apertando somente um número\n\n");
		printf("------------------------------NIVEIS DE DIFICULDADE------------------------------\n");
		printf("Nivel 1: 3 números\nNivel 2: 6 números\nNivel 3: 9 números\nNivel 4: 12 números\n\n");
		printf("LCMD produções ©\n");
		printf("--------------------------------------------------------------------------------\n");
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
		printf("\t\t\tGENIUS\n\n\tO QUE DESEJA FAZER ?\n\n 1 - 1 JOGADOR \n\n 2 - 2 JOGADORES\n\n 3 - INSTRUÇÕES\n\n 4 - SAIR DO JOGO\n\n Opção\a: ");
		scanf("%d", &escolha);
		if (escolha!=1||escolha!=4||escolha!=3||escolha!=2) {
			system("cls");
		}
	}while((escolha <1)||(escolha>4));	
	return escolha;
}	
void nome(char usu_nome[20]){
	
	do{		
		printf("POR FAVOR, DIGITE O NOME DO JOGADOR: ");
	 	fflush(stdin);
		scanf("%[^\n]", usu_nome);
	}while(strlen(usu_nome) >= 20);	 			 
}	
