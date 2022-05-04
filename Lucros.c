#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

int main(void){
	
	setlocale(LC_ALL, "Portuguese");
	
	char desejo[6];
	double lucro, ganho, gasto, valor;
	
	do{
		printf("\tDeseja anotar ganhos: \n");
		printf("\tDeseja anotar gastos: \n");
		printf("\tDeseja parar: \n");
		scanf("%s", desejo);

		if(strcmp(desejo, "ganhos") == 0){
			printf("\tDigite seu ganho: ");
			scanf("%lf", &valor);
			ganho += valor;
		}else if(strcmp(desejo, "gastos") == 0){
			printf("\tDigite seu gasto: ");
			scanf("%lf", &valor);
			gasto += valor;
		}else if(strcmp(desejo, "parar") == 0){
			break;
		}else{
			printf("\tInvalido, digite novamente\n\n");
		}

	}while(true);

	lucro = ganho - gasto;

	printf("\tSeu ganho foi %.2lf R$\n", ganho);
	printf("\tSeu gasto foi %.2lf R$\n", gasto);
	printf("\tSeu lucro foi %.2lf R$\n", lucro);
	
	if(lucro>0){
		printf("\tVocê teve ganhos\n\n");
	}else if(lucro<0){
		printf("\tVocê teve prejuízo\n\n");
	}else{
		printf("\tVocê não teve ganho nem prejuízo\n\n");
	}
}