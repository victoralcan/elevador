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
void leArquivos(Elevador *elevador) /*Lê os arquivos do elevador e eventos*/
{
  int a,c;
	FILE *fp;
  char arq []= "elevador.txt";
	fp = fopen(arq,"r+");
	if(fp == NULL)
	{
		printf("Não foi possivel abrir arquivo do elevador\n");
		return;
	}
	else
	{
	fscanf(fp,"%d %d",&a,&c);
  elevador->andares = a;
  elevador->capacidade = c;
	fclose(fp);
	}
}
/*
void embarcadosVazio(Passageiro embarcados[])
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
*/
void iniciaElevador(Elevador *elevador) /*Inicializa o elevador*/
{
  elevador->andar_atual = -1;
  elevador->ocupantes = 0;
  elevador->subindo = false;
}
