#include <stdio.h>
#include "elevador.h"


void elevadorDescendo()/*Tratamento do elevador descendo*/
{

} 
void elevadorSubindo() /*Tratamento do elevador subindo*/
{

}
void elevadorParado() /*Não tem nenhuma chamada pendente, mas continua incrementando o tempo*/
{

}
void aoEntrar()/*O que fazer ao entrar (ordenar vetor de prioridades e passageiros)*/
{

}
void aoSair() /*Executas certas acoes ao deixar o passageiro no destino*/
{

}
void trataTempo() /*Calcula os tempos de viagem e etc para imprimir*/
{

}
void escreveLog()/*Escreve no arquivo texto de saida dos eventos*/
{

}
void leArquivos(int *andares, int *capacidade) /*Lê os arquivos do elevador e eventos*/
{
	FILE *fp;
	fp = fopen("elevador.txt","r");
	if(fp == NULL)
	{
		printf("Não foi possivel abrir arquivo do elevador\n");
		return;
	}
	else
	{
	fscanf(fp,"%d %d",andares,capacidade);
	fclose(fp);
	}
}
void embarcadosVazio(Passageiro embarcados[], int capacidade)/*Preenche o vetor de embarcados*/
{
	Passageiro *vazio;
	vazio->andar_entrada = -1;
	vazio->andar_destino = -1;
	vazio->numero = -1;	
	vazio->tempo_entrada = -1;
	vazio->tempo_saida = -1;
	vazio->tempo_chamada = -1;
	vazio->dentro = false;
	for(int a=0;a<capacidade;a++)
	{
		embarcados[a] = *vazio;
	}
}

void iniciaElevador(Elevador *elevador, int capacidade, int andares) /*Inicializa o elevador*/
{
	elevador->andar_atual = -1;
	elevador->ocupantes = 0;
	elevador->subindo = false;
	elevador->total_andares = andares;
	elevador->capacidade = capacidade;
}
