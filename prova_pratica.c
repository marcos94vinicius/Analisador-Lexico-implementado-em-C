#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//variavel que verifica se deve ou não pular linha
int pula_linha = 0;

//função que retorna para qual estado ir após ler um char
int para_qual_estado(int mat[23][11], char c, int line){

	//+
	if(c == '+')
		return(mat[line][0]);
	//-
	else if(c == '-')
		return(mat[line][1]);
	//0-9
	else if(c >= 48 && c <= 57)
		return(mat[line][2]);
	//h
	else if(c == 'h')
		return(mat[line][3]);
	//s
	else if(c == 's')
		return(mat[line][4]);
	//c
	else if(c == 'c')
		return(mat[line][5]);
	//e
	else if(c == 'e')
		return(mat[line][6]);
	//i
	else if(c == 'i')
		return(mat[line][7]);
	//a
	else if(c == 'a')
		return(mat[line][8]);
	//r
	else if(c == 'r')
		return(mat[line][9]);
	//t
	else if(c == 't')
		return(mat[line][10]);
	//other
	else return (0);
}

//método que imprime o tipo de token
void imprime_token(int fim){

	//REAL
	if(fim == 22)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("REAL ");return;}
	//MAIS
	else if(fim == 17)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("MAIS");return;}
	//MENOS	
	else if(fim == 18)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("MENOS");return;}
	//INTEIRO
	else if(fim == 19)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("INTEIRO ");return;}
	//ELE
	else if(fim == 3)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("ELE");return;}
	//DELE
	else if(fim == 8)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("DELE");return;}
	//ELA
	else if(fim == 6)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("ELA");return;}
	//GATO
	else if(fim == 13)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("GATO");return;}
	//CARRO
	else if(fim == 14)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("CARRO");return;}
	//DELA
	else if(fim == 10)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("DELA");return;}
	//GATOS
	else if(fim == 15)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("GATOS");return;}
	//CARROS
	else if(fim == 16)
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("CARROS");return;}
	//ERRO
	else
		{if(pula_linha != 0){printf("\n");}pula_linha = 1;printf("ERRO");return;}

}

int main(){
                        //   +   -  0-9  h   s   c   e   i   a   r   t
	int matriz[23][11] = {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},//0
						  { 17, 18, 19,  2,  4, 11,  0,  0,  0,  0,  0},//1
						  {  0,  0,  0,  0,  0,  0,  3,  7,  0,  0,  0},//2
						  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0},//3
						  {  0,  0,  0,  5,  0,  0,  0,  0,  0,  0,  0},//4
						  {  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0},//5
						  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},//6
						  {  0,  0,  0,  0,  8,  0,  0,  0,  0,  0,  0},//7
						  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},//8
						  {  0,  0,  0,  0, 10,  0,  0,  0,  0,  0,  0},//9
						  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},//10
						  {  0,  0,  0,  0,  0,  0,  0,  0, 12,  0,  0},//11
						  {  0,  0,  0,  0,  0,  0,  0,  0,  0, 14, 13},//12
						  {  0,  0,  0,  0, 15,  0,  0,  0,  0,  0,  0},//13
						  {  0,  0,  0,  0, 16,  0,  0,  0,  0,  0,  0},//14
						  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},//15
						  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},//16
						  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},//17
						  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},//18
						  {  0,  0, 19,  0,  0,  0, 20,  0,  0,  0,  0},//19
						  { 21, 21, 22,  0,  0,  0,  0,  0,  0,  0,  0},//20
						  {  0,  0, 22,  0,  0,  0,  0,  0,  0,  0,  0},//21
						  {  0,  0, 22,  0,  0,  0,  0,  0,  0,  0,  0},//22
						};

	//vetor de estados finais (posicao vet[i]) = 1 é estado final)
	int vetor[22] = {0,0,1,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0,0,1};

	//declaração de algumas variáveis
	int atual = 1, final = 0, last_terminal = 0, indice = 0, start = 0, i = 0;

	//string que contém a entrada
	char entrada[10000];

	//fazendo a leitura do arquivo de entrada
	while(scanf("%c", &entrada[i]) != -1)
		i++;
	entrada[i] = '\0';

	//percorrendo a string de entrada
	while(1){

		//atualiza a variavel 'atual' 
		atual = para_qual_estado(matriz, entrada[indice], atual);
		//atualiza a variável 'final'
		if(vetor[atual - 1] == 1){

			last_terminal = indice;
			final = atual;
		}
		//verifica se deu algum erro
		if(atual == 0){

			//verifica se não é um erro
			if(final != 0){
			
				imprime_token(final);
				while(start <= last_terminal){

					if(final == 19 || final == 22)
						printf("%c", entrada[start]);
					start++;
				}	
			}
			//verificando se é um erro
			else{

				if(entrada[start] != ' ' && entrada[start] != '\n' && entrada[indice] != '\0')
					imprime_token(final);
				start++;
			}
			atual = 1;
			final = 0;
			indice = start-1;
			
		}
		if(entrada[indice] == '\0')
			break;
		indice++;
	}

}
