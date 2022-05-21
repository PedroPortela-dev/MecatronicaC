#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

float soma(float a, float b){
	float result = a + b;
	return result;
}

float subtrair(float a, float b){
	float result = a - b;
	return result;
}

float multiplicar(float a, float b){
	float result = a * b;
	return result;
}

float dividir(float a, float b){
	float result = a / b;
	return result;
}

float resto(int a, int b){
	float result = a % b;
	return result;
}

int somatorio(int a){
	if(a == 1){
		return 1;
	}
	return a + somatorio(a-1);
}

int fatorial(int a){
	if(a == 1){
		return 1;
	}
	return a*fatorial(a-1);
}

int fibonacci(int a){
	if(a == 0 || a == 1 || a == 2){
		return 1;
	}
	return fibonacci(a-1) + fibonacci(a-2);
}

int binomial(int a, int b){
	
	return fatorial(a)/fatorial(b)/fatorial(a-b);
}

float logaritmo(float a, float b){
	
	float result = log(a)/log(b);
	return result;
}

float potencia(float a, float b){
	float result = pow(a, b);
	return result;
}

float raizQuadrada(float a){
	float result = sqrt(a);
	return result;
}

int main(void){
	
	setlocale(LC_ALL, "Portuguese");
	
	char continuar;
	
	do{
	
		char operacao;
		
		printf("Soma[+]\n");
		printf("Subtração[-]\n");
		printf("multiplicação[*]\n");
		printf("divisão[/]\n");
		printf("resto[%]\n");
		printf("Somatorio[s]\n");
		printf("fatorial[!]\n");
		printf("fibonacci[f]\n");
		printf("numero binomial[b]\n");
		printf("logaritmo[l]\n");
		printf("potencia[^]\n");
		printf("raizquadrada[q]\n");
		
		scanf("%s", &operacao);
		
		system("cls");
		
		float num1, num2, result;
		
		if(operacao == '+' || operacao == '-' || operacao == '*' || operacao == '/' || operacao == '%'){
			
			printf("Digite os valores: ");
			scanf("%f%f", &num1, &num2);
			
			if(operacao == '+'){
				result = soma(num1, num2);
			}else if(operacao == '-'){
				result = subtrair(num1, num2);
			}else if(operacao == '*'){
				result = multiplicar(num1, num2);
			}else if(operacao == '/'){
				result = dividir(num1, num2);
			}else if(operacao == '%'){
				result = resto((int)num1, (int)num2);
			}
		
		}else if(operacao == 's' || operacao == '!' || operacao == 'f' || operacao == 'q'){
			
			printf("Digite o valor: ");
			scanf("%f", &num1);
			
			if(operacao == 's'){
				result = somatorio((int)num1);
			}else if(operacao == '!'){
				result = fatorial((int)num1);
			}else if(operacao == 'f'){
				result = fibonacci((int)num1);
			}else if(operacao == 'q'){
				result = raizQuadrada(num1);
			}
			
		}else{
			
			printf("Digite os valores: ");
			scanf("%f%f", &num1, &num2);
			
			if(operacao == 'b'){
				result =  binomial((int)num1, (int)num2);
			}else if(operacao == 'l'){
				result = logaritmo(num1, num2);
			}else if(operacao == '^'){
				result = potencia(num1, num2);
			}
		}
		
		system("cls");
		
		printf("Resultado = %f\n", result);
		
		system("pause");
		
		printf("Deseja continuar? [s]Sim/[n]Não\n");
		scanf("%s", &continuar);
		
	}while(continuar == 's');
	
}
