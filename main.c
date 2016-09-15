#include <stdio.h>
#include <stdlib.h>
#include "elevador.h"


int main()
{
	Elevador elevador;
	Passageiro *embarcados;
	tlista *lista_eventos;
	int num_eventos = 0;
	leArquivos(&elevador);
	iniciaElevador(&elevador);
	embarcados = (Passageiro*) malloc(sizeof(Passageiro) * elevador.capacidade); 
	embarcadosVazio(embarcados,elevador.capacidade); /*RX SENHOR POR FAVOR*/
	lista_eventos = criaLista();
	preencheEventos(lista_eventos,&num_eventos);

	while(num_eventos > 0)
	{
		elevadorSubindo();         /*Primeiro subindo porque ele começa no andar 0*/
		elevadorDescendo();
	}





	
	free(embarcados);
	return 0;
}
