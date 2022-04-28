#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(void){
	
	setlocale(LC_ALL, "Portuguese");
	
	int desejo;
	double lucro, ganho, gasto;
	
	do{
		printf("Deseja anotar ganhos, digite 0: \n");
		printf("Deseja anotar gastos, digite 1: \n");
		printf("Deseja parar, digite 2\n");
		scanf("%d", &desejo);
		
		switch(desejo){
			case 0:
				printf("Digite seu ganho: ");
				scanf("%lf", &ganho);
				lucro += ganho;
				break;
			case 1:
				printf("Digite seu gasto: ");
				scanf("%lf", &gasto);
				lucro -= gasto;
				break;
			case 2:
				break;
			default:
				printf("Invalido, digite novamente\n\n");	
	
		}
	}while(desejo != 2);
	
	printf("Seu lucro é %.2lf R$\n", lucro);
	if(lucro>0){
		printf("Você teve ganhos\n\n");
	}else if(lucro<0){
		printf("Você teve prejuiço\n\n");
	}else{
		printf("Você não teve ganho nem prejuiço\n\n");
	}
}