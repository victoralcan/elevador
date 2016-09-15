#include <stdio.h>
#include <stdlib.h>
#include "elevador.h"

void aoEntrar(Passageiro passageiro)/*Imprimir no arquivo log informações de entrada*/
{
	FILE *fp;
	fp = fopen("log.txt","a");
	fprintf(fp, "Passageiro %d entra %d Zepslons após a chamada\n", passageiro.numero, (passageiro.tempo_entrada - passageiro.tempo_chamada));
	fclose(fp);
}

void aoSair(Passageiro passageiro) /*Imprimir no arquivo log informações de saida*/
{
	FILE *fp;
	fp = fopen("log.txt","a");
	fprintf(fp, "Passageiro %d sai %d Zepslons após ter entrado\n", passageiro.numero, (passageiro.tempo_saida - passageiro.tempo_entrada));
	fclose(fp);
}

void trataTempo(Elevador *elevador) /*Imprime informações do elevador no arquivo log*/
{
	FILE *fp;
	fp = fopen("log.txt","a");
	fprintf(fp, "Zepslon: %d     Andar atual: %d    Passageiros embarcados: %d\n", elevador->tempo, elevador->andar_atual,elevador->ocupantes);
	fclose(fp);
}