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
	
	unsigned short int vet[256], re[256], i, j, aux = 0, fase = 1, num = 3;
	bool jog_1;
	//função do Menu
	menu();

	if (escolha == 1){
		
		 do{
			
			jog_1 = true;
		 	srand(time(NULL));
		
			//alocação do valor
			for(i = 0; i< fase; i++){
				vet[i] = rand() % num + 1;
				
			}
			//verificação do valor(teste)
			for(i = 0; i< fase; i++){
				printf("\n\n%d", vet[i]);
			}
			
			//pergunta ao usuario
			for(i = 0; i< fase; i++){
				printf("\n\n\tqual o número ? ");
				scanf("%d", &re[i]);
			}
			//verificação do valor
			for(i = 0; i < num; i++){
				for(j = 0; j < num; j++){
					if(re[i] == vet[j]){
						aux++;		
					}
				}	
			}	
			if (aux > 0){
				printf("VOCÊ ACERTOU!");
			}else{
				jog_1 == false;
				printf("VOCÊ ERROU AMIGO(A), SINTO MUITO");
			}		
		}while(jog_1 == true);
		 	
	}		
}

//Menu
void menu(){
	
	printf("\n\n\tO que deseja fazer?\n\n 1 - 1 JOGADOR \n\n 2 - 2 JOGADORES\n\n 3 - ABSOLUTAMENTE NADA\n\n Opção\a: ");
	scanf("%d", &escolha);
	
}
