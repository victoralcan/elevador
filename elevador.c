#include <stdio.h>
#include "elevador.h"


void elevadorDescendo(); /*Tratamento do elevador descendo*/
void elevadorSubindo(); /*Tratamento do elevador subindo*/
void elevadorParado(); /*Não tem nenhuma chamada pendente, mas continua incrementando o tempo*/
void aoEntrar(); /*O que fazer ao entrar (ordenar vetor de prioridades e passageiros)*/
void aoSair(); /*Executas certas acoes ao deixar o passageiro no destino*/
void trataTempo(); /*Calcula os tempos de viagem e etc para imprimir*/
void escreveLog();/*Escreve no arquivo texto de saida dos eventos*/
void leArquivos(); /*Lê os arquivos de ambiente e eventos*/
void embarcadosVazio(Passageiro *embarcados, char* argv[])/*Preenche o vetor de embarcados*/
{
	FILE *fp;
	int capacidade,a;
	fp = fopen("Elevador.txt","r");
	Passageiro *vazio;
	if(fp = NULL)
	{
		printf("Não foi possivel abrir arquivo do elevador\n");
		return;
	}
	else
	{
		fp = fopen("Elevador.txt","w");
		fscanf(fp,"%d %d",&a,&capacidade);
		vazio->andar_entrada = -1;
		vazio->andar_destino = -1;
		vazio->numero = -1;
		vazio->tempo_entrada = -1;
		vazio->tempo_saida = -1;
		vazio->tempo_chamada = -1;
		vazio->dentro = false;
		for(a=0;a<capacidade;a++)
		{
			embarcados[a] = vazio;
		}
		fclose(fp);
	}
}
void iniciaElevador(Elevador *elevador, char* argv[]) /*Inicializa o elevador*/
{
	FILE *fp;
	int andares,capacidade;
	fp = fopen("Elevador.txt","r");
	if(fp = NULL)
	{
		printf("Não foi possivel abrir arquivo do elevador\n");
		return;
	}
	else
	{
	fp = fopen("Elevador.txt","w");
	fscanf(fp,"%d %d",&andares,&capacidade);
	elevador->andar_atual = -1;
	elevador->ocupantes = 0;
	elevador->subindo = false;
	elevador->total_andares = andares;
	elevador->capacidade = capacidade;
    }
    fclose(fp);
}
