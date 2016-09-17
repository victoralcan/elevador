#include <stdio.h>
#include <stdlib.h>
#include "elevador.h"
#include <sys/time.h>

int main()
{
	FILE *fp;
	Elevador elevador;
	Passageiro *embarcados;
	tlista *entradas;
	tlista *destinos;
	tlista *descendo;
	tlista *prox_descendo;
	tlista *lista_eventos;
	tlista *lista_subindo;
	tlista *lista_descendo;
	int num_eventos = 0;

	fp = fopen("log.txt","r");
	if(fp != NULL)
	{
		remove("log.txt");
	}

	struct timeval inicio, final;
  	int tmili;
	gettimeofday(&inicio, NULL);

	leArquivos(&elevador);
	iniciaElevador(&elevador);
	embarcados = (Passageiro*) malloc(sizeof(Passageiro) * elevador.capacidade); 
	embarcadosVazio(embarcados,elevador.capacidade); /*RX SENHOR POR FAVOR*/
	lista_eventos = criaLista();
	lista_subindo = criaLista();
	lista_descendo = criaLista();
	entradas = criaLista();
	destinos = criaLista();
	/*prox_subindo = criaLista();
	prox_descendo = criaLista();*/
	preencheEventos(lista_eventos,lista_subindo,lista_descendo,entradas,destinos,&num_eventos);
	l_e_v(&elevador,lista_eventos,lista_subindo,lista_descendo,embarcados,&num_eventos);
	/*fcfs(&elevador,lista_eventos,embarcados,&num_eventos);*/



	free(lista_eventos);
	free(entradas);
	free(destinos);
	free(embarcados);


	gettimeofday(&final, NULL);
    tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
    printf("Tempo decorrido durante execução: %d milissegundos\n", tmili);


	return 0;
}
