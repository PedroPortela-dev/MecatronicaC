#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(void){
	
	setlocale(LC_ALL, "Portuguese");
	
	int totalNum, i;
	
	printf("Digite a quantidade de numeros: ");
	scanf("%d", &totalNum);
	
	double num[totalNum];
	
	for(i = 0; i < totalNum; i++)
	{
		printf("num[%d] = ", i+1);
		scanf("%lf", &num[i]);
	}
	
	int repetir, aux;
	do{
		repetir = 0;
		for(i = 0; i < totalNum-1; i++)
		{
			if(num[i] > num[i+1]){
				repetir = 1;
				aux = num[i];
				num[i] = num[i+1];
				num[i+1] = aux;
			}
		}
	}while(repetir);
	
	for(i = 0; i < totalNum; i++)
	{
		printf("[%lf] ", num[i]);
	}
}
