#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void){
	
	setlocale(LC_ALL, "Portuguese");
	
	char vogais[5][2] = {"aA","eE","iI","oO","uU"};
	//fiz assim, pq quando usei vogal[5]; deu bug no i que dava dando 35
	int vogal[] = {0,0,0,0,0}, i, j, k;
	
	char texto[30];
	
	printf("Digite um texto: \n");
	scanf("%[^\n]", texto);
	
	for(i = 0; texto[i] != '\0'; i++)
	{
		for(j = 0; j<5; j++)
		{
			for(k = 0; k<2; k++)
			{
				if(vogais[j][k] == texto[i]){
					vogal[j]++;
				}
			}
		}	
	}
	
	for(i = 0; i<5;i++){
		printf("%c = %d\n", vogais[i][1], vogal[i]);
	}
	
}
