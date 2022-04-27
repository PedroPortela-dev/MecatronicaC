#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void){
	
	setlocale(LC_ALL, "Portuguese");
	
	int numero;
	float numero_real;
	char letra;
	
	printf("\tDigite um numero: ");
	scanf("%d", &numero);
	
	printf("\tDigite um numero real: ");
	scanf("%f", &numero_real);
	
	printf("\tDigite um caractere: ");
	scanf("%s", &letra);
	
	printf("O numero é: %d\n", numero);
	printf("O numero real é: %.3f\n", numero_real);
	printf("O caractere é: %c\n", letra);
}