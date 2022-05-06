#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int carta1, cartasSelecionadas[52], repetir, k;

struct jogador{
	int cartas[15];
	int quantidadeCartas;
	int finalizou;
	int pontos;
};

void novaCarta(){

	int i;

	//A carta já foi sorteada?
	repetir = 0;
	do{
		carta1 = rand() % 52;
		
		for(i = 0; i<52; i++){
			if(cartasSelecionadas[i] == carta1){
				repetir = 1;
				break;
			}
		}
	}while(repetir);
	cartasSelecionadas[k] = carta1;
			
	k++;
}

int main(void) {
	
	setlocale(LC_ALL, "Portuguese");
	
	//Prmeiramente vou criar um baralho pq é o que normalmente utilizo neste jogo
	
	int baralho[52];
	
	int j = 0, i = 0;
	
	for (k = 0; k<4; k++)
	{
		for(i = 13; i>0; i--, j++)
		{
			if(i>10){
				baralho[j]=10;
			}else{
				baralho[j]=i;
			}
		}	
	}
	
	// Agora bora jogar
	
	int totalJogadores;
	
	printf("Digite a quantidade de jogadores: ");
	scanf("%d", &totalJogadores);

	struct jogador todosJogador[totalJogadores];
	srand(time(NULL));
	
	for(i = 0; i<52; i++){
		cartasSelecionadas[i] = -1;
	}
	
	for(k = 0, i = 0; i < totalJogadores; i++)
	{
		for(j = 0; j < 2; j++)
		{
			novaCarta();
			todosJogador[i].cartas[j] = baralho[carta1];
		}

		todosJogador[i].quantidadeCartas = 2;
		todosJogador[i].finalizou = 0;
	}

	int opcao, pontos;
	
	do{
		//Interface do jogador	
		i = 0;
		while(i<totalJogadores){
			
			todosJogador[i].pontos = 0;
			for(j = 0; j<todosJogador[i].quantidadeCartas; j++){
				todosJogador[i].pontos += todosJogador[i].cartas[j];
			}
			
			if(todosJogador[i].pontos > 21){
				
				printf("Você perdeu >_<\n");
				todosJogador[i].finalizou = 1;
				system("pause");
				i++;
				continue;
			}
			
			if(todosJogador[i].finalizou){
				
				continue;
			}

			system("cls");

			printf("________Rodada do %dº jogador________\n\n", (i+1));
			printf("ver suas cartas:(1)\n");
			printf("pegar mais uma:(2)\n");
			printf("passar a vez:(3)\n");
			printf("finalizar:(4)\n");
			scanf("%d", &opcao);

			switch (opcao)
			{
				case 1:

					system("cls");
					printf("Cartas Jogador %d:\n\n", (i+1));
					for(j = 0; j < todosJogador[i].quantidadeCartas; j++){
						printf("%d\n", todosJogador[i].cartas[j]);
					}
					system("pause");
					break;
				case 2:

					novaCarta();
					todosJogador[i].cartas[todosJogador[i].quantidadeCartas] = baralho[carta1];
					todosJogador[i].quantidadeCartas++;
					break;

				case 3:

					i++;
					break;

				case 4:

					todosJogador[i].finalizou = 1;
					i++;
					break;
				default:

					printf("Invalido, digite novamente\n");
					system("pause");
					break;
			}
		}

		repetir = 0;
		for(i = 0; i < totalJogadores; i++)
		{
			if(!todosJogador[i].finalizou){
				repetir = 1;
			}
		}
	}while(repetir);

	int ranking[2][totalJogadores], troca, aux;

	for (i = 0; i < totalJogadores; i++)
	{
		ranking[0][i] = i+1;
		ranking[1][i] = todosJogador[i].pontos;
	}
	
	//passar para trás o que tiver menor pontuação
	do
	{
		troca = 0;
		for (i = 0; i < totalJogadores-1; i++)
		{
			if((ranking[1][i] < ranking[1][i+1] || ranking[1][i]>21) && ranking[1][i+1]<=21){
				troca = 1;
				aux = ranking[0][i];
				ranking[0][i] = ranking[0][i+1];
				ranking[0][i+1] = aux;
				aux = ranking[1][i];
				ranking[1][i] = ranking[1][i+1];
				ranking[1][i+1] = aux;
			}
		}
	} while (troca);

	system("cls");
	//escrever a colocação
	j = 1;
	for(i = 0; i< totalJogadores; i++){
		printf("\nA %dª posição vai para o %dº jogador com %d pontos.\n", j, ranking[0][i], ranking[1][i]);
		if(ranking[1][i] != ranking[1][i+1] && ranking[1][i] <= 21){
			j++;
		}
		
	}
	
}
