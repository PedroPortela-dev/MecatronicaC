#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(void){
	
	setlocale(LC_ALL, "Portuguese");
	
	float altura, peso, imc;
	char continuar;

	do{
		printf("\tDigite sua altura: ");
		scanf("%f", &altura);
		
		printf("\tDigite seu peso: ");
		scanf("%f", &peso);
		
		imc = peso/pow(altura, 2);
		
		printf("\tO seu IMC é %.3f\n", imc);
		
		if(imc < 20){
			printf("\tVá comer feijão\n");
		}else if(imc <25){
			printf("\tBoa malandro\n");
		}else if(imc<30){
			printf("\tQual foi playboy pare de comer batata frita\n");
		}else if(imc<35){
			printf("\tCuidado para n virar balão\n");
		}else{
			printf("\tMeus Pesames, a cova tá perto, mas n cabe\n");
		}
		
		printf("\tTentar Novamente? [S]Sim ou [N]Não\n\t");
		scanf("%s", &continuar);
	}while(continuar == 'S');
}
