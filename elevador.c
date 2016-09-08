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
void embarcadosVazio(); /*Preenche o vetor de embarcados*/
void iniciaElevador(); /*Inicializa o elevador*/