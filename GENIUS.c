#include<stdio.h>
#include<locale.h>
#include<time.h>

unsigned short int escolha;

menu();
 

main(){
	
	setlocale(LC_ALL, "portuguese");
	
	unsigned short int vet[256], re[256], i, j, aux = 0, fase = 1, num;
	
	//função do Menu
	menu();

	if (escolha == 1){
	
		fase = 1;	
		
		 srand()= time(3000);
		
		//alocação do valor
		for(i = 0; i< fase; i++){
			vet[i] = rand();
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
		for(i = 0; i < 256; i++){
			if(re[i] == vet[i]){
			aux++;		
			}	
		}	
		if (aux > 0){
			printf("DEU BOM");
		}		
	}		
}

//Menu
menu(){
	
	printf("\n\n\tO que deseja fazer?\n\n 1 - 1 JOGADOR \n\n 2 - 2 JOGADORES\n\n 3 - ABSOLUTAMENTE NADA\n\n Opção\a: ");
	scanf("%d", &escolha);
	
}


	
