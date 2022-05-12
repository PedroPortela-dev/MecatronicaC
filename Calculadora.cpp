#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void pedir(char txt[], float* valor){
	
	printf("Digite o %s: ", txt);
	scanf("%f", valor);
}

void pedir(char txt[], char* valor){
	
	printf("Digite a %s: ", txt);
	scanf("%s", valor);
}

float soma(float valor1, float valor2){
	
	return valor1 + valor2;
}

float subtrair(float valor1, float valor2){
	
	return valor1-valor2;
}

float multiplicar(float valor1, float valor2){
	
	return valor1*valor2;
}

float dividir(float valor1, float valor2){
	
	return valor1/valor2;
}

float resto(float valor1, float valor2){
	
	return (int)valor1%(int)valor2;
}

float somatorio(float valor1){
	
	if(valor1 == 1){
		return 1;
	}
	
	return valor1+somatorio(valor1-1);
}

float fatorial(float valor1){
	
	if(valor1 == 1){
		return 1;
	}
	
	return valor1*fatorial(valor1-1);
}

float fibonacci(float valor1){
	
	if(valor1 == 1 || valor1 == 2){
		return 1;
	}
	
	return fibonacci(valor1-1)+fibonacci(valor1-2);
}

float binomial(float valor1, float valor2){
	
	return fatorial(valor1)/fatorial(valor2)/fatorial(valor1-valor2);	
}

int main(void){
	
	setlocale(LC_ALL, "Portuguese");
	
	char operacao;
	float num1, num2, result;
	char repetir;
	
	do{
	
		printf("Soma(+):\n");
		printf("Subtração(-):\n");
		printf("Multiplicação(*):\n");
		printf("Divisão:(/):\n");
		printf("Resto da Divisão(%%):\n");
		printf("Somatorio(S):\n");
		printf("fatorial(!):\n");
		printf("fibonacci(f)");
		printf("numero binomial(C):\n");
		pedir("operação", &operacao);
		
		system("cls");
		
		pedir("primeiro valor", &num1);
		
		if(operacao != 'S' && operacao != '!' && operacao != 'f'){
			pedir("segundo valor", &num2);
		}
		
		if(operacao == '+'){
			result = soma(num1, num2);
		} else if(operacao == '-'){
			result =  subtrair(num1, num2);
		} else if(operacao == '*'){
			result = multiplicar(num1, num2);
		} else if(operacao == '/'){
			result = dividir(num1, num2);
		} else if(operacao == '%'){
			result = resto(num1, num2);
		} else if(operacao == 'S'){
			result = somatorio(num1);
		} else if(operacao == '!'){
			result = fatorial(num1);
		} else if(operacao == 'f'){
			result = fibonacci(num1);
		} else if(operacao == 'C'){
			result = binomial(num1, num2);
		}
		
		result = soma(num1, num2);
		
		printf("O resultado é: %.3f\n", result);
		
		pedir("Continuar?(s/n)", &repetir);
		
	}while(repetir != 'n');
}
