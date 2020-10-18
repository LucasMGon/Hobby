#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	//Ajustar Cores do terminal
	system("setterm -foreground white -background blue || color 71");
	
	unsigned short int opc;
	int ret2;	//Dependendo da IDE, pode mostrar que não esta em uso essa variavel
	int tempo;
	char desligar[100];
	
	do{
		system("clear || cls");
		
		printf("\t*********************************************************\n"
			   "\t*		1 - Programar Desligamento		*\n"
			   "\t*		2 - Sobre				*\n"
			   "\t*		0 - Sair		  		*\n"
			   "\t*********************************************************\n\t");
		scanf("%hu", &opc);
		
		switch(opc){
			case 1:
				
				printf ("\tDigite os minutos:\n\t");	//E/S dos minutos a desligar
				scanf("%d", &tempo);
				tempo *=60;
				
				#ifdef linux
					ret2 = sprintf(desligar, "sudo shutdown -h +%d", tempo);
					ret2 = system(desligar);
				
				#elif defined _WIN32
					ret2 = sprintf(desligar, "shutdown -s -t %d", tempo); //formata a string desligar
					printf("ret2 = %d\n", ret2);	//exibe o valor de retorno da função sprintf
					ret2 = system(desligar);	//usa system() para executar o comando formatado com a função sprintf()				
				#endif
			break;
			
			case 2:
				system("clear || cls");
				printf("\n\n\t\tDesenvolvedor: Lucas M. Gon�alves\n"
					   "\t\tBrasil, 31 de Dezembro de 2017\n\t\t");
				system("pause || sleep 3000");
			break;
		}
		
	}while(opc !=1 && opc != 2 && opc !=3 && opc !=0);
	return 0;
}
