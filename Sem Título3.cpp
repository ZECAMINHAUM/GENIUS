#include<stdio.h>
#include<locale.h>
#include<time.h>
#include <stdlib.h>
#include <unistd.h>

enum boolean {
    true = 1, false = 0
};
typedef  enum boolean  bool;

unsigned short int escolha;

void menu();
 

main(){
	
	setlocale(LC_ALL, "portuguese");
	
	unsigned short int vet[256], re[256], i, j, aux = 0, fase = 1, num = 3;
	bool jog_1;
	//fun��o do Menu
	menu();

	if (escolha == 1){
		
		 do{
			
			jog_1 = true;
		 	srand(time(NULL));
		
			//aloca��o do valor
			for(i = 0; i< fase; i++){
				vet[i] = rand() % num + 1;
				
			}
			//verifica��o do valor(teste)
			for(i = 0; i< fase; i++){
				printf("\n\n%d", vet[i]);
			}
			
			system("cls");
			//pergunta ao usuario
			for(i = 0; i< fase; i++){
				printf("\n\n\tqual o n�mero ? ");
				scanf("%d", &re[i]);
			}
			//verifica��o do valor
			for(i = 0; i < num; i++){
				for(j = 0; j < num; j++){
					if(re[i] == vet[j]){
						aux++;		
					}
				}	
			}	
			if (aux > 0){
				printf("VOC� ACERTOU!");
			}else{
				jog_1 == false;
				printf("VOC� ERROU AMIGO(A), SINTO MUITO");
			}		
		}while(jog1 == true);
		 	
	}		
}

//Menu
void menu(){
	
	printf("\n\n\tO que deseja fazer?\n\n 1 - 1 JOGADOR \n\n 2 - 2 JOGADORES\n\n 3 - ABSOLUTAMENTE NADA\n\n Op��o\a: ");
	scanf("%d", &escolha);
	
}
