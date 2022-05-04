#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void){

	setlocale(LC_ALL,"Portuguese");

	float investimento, taxaJuros, saldo;
	int mes;
	char continuar;

	do{
		system("clear");

		printf("\n\tQuando deseja investir?: ");
		scanf("%f", &investimento);

		printf("\n\tQual a taxa de juros em porcentagem?: ");
		scanf("%f", &taxaJuros);

		printf("\n\tQuantos meses de investimento?: ");
		scanf("%d", &mes);

		saldo = 0;
		for(int i = 0; i < mes; i++){
			saldo += investimento;
			saldo *= 1+taxaJuros/100;
		}

		printf("\n\tCom o investimento R$%.2f de mês a mês, e tendo uma taxa de juros de %.3f%% ao mês\n", investimento, taxaJuros);
		printf("\tSaldo do investimento após %d meses: %f\n\n", mes, saldo);

		printf("\tDeseja tentar novamente?:(S/N)\n\t");
		scanf("%s", &continuar);
	}while(continuar != 'N');
}
