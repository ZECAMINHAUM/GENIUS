#include<stdio.h>
#include<locale.h>
#include<time.h>
#include <stdlib.h>
#include <unistd.h>

//EMULAÇÃO DE FUNÇÃO BOLEANA
enum boolean {
    true = 1, false = 0
};
typedef  enum boolean  bool;

unsigned short int escolha;

void menu();
 

main(){
	
	setlocale(LC_ALL, "portuguese");
	
	unsigned short int vet[256], re[256], i, aux = 0, fase = 1, num = 3, qtd_num = 1;
	char reload;
	bool jog_1, acertos;
	//função do Menu
	
	menu();
	system("cls");
	
	if (escolha == 1){
		
		 do{
			
			jog_1 = true;
			acertos = true;
		 	srand(time(NULL));
		
			//alocação do valor
			for(i = qtd_num - 1 ; i< qtd_num; i++){
				vet[i] = rand() % num + 1;
				
			}
			//valor randomizado
			for(i = 0; i< qtd_num; i++){
				system("cls");
				printf("%d ", vet[i]);
				sleep(2);
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
				printf("VOCÊ ACERTOU");
				qtd_num++;
				
			}
			if(acertos == false){
				printf("VOCÊ ERROU AMIGO(A), MAS NÃO FIQUE TRISTE");
				printf("\nVOCÊ CHEGOU AO NÍVEL %d", fase);
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
			menu();
		}else{
			printf("\n\n\tAté a proxima\n\n");
			sleep (2);
			exit;
		}
	}		
}

//Menu
void menu(){
	printf("\n\n\tO que deseja fazer?\n\n 1 - 1 JOGADOR \n\n 2 - 2 JOGADORES\n\n 3 - ABSOLUTAMENTE NADA\n\n Opção\a: ");
	scanf("%d", &escolha);	
}
