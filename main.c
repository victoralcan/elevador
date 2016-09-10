#include <stdio.h>
#include <stdlib.h>
#include "elevador.h"

/*Argv[1] é elevador*/
/*Argv[2] é eventos*/

int main()
{
	Elevador *elevador;
	Passageiro *embarcados;
	tlista *lista_eventos;
	int num_eventos = 0;
	leArquivos(elevador);
	iniciaElevador(elevador);
	embarcados = (Passageiro*) malloc(sizeof(Passageiro) * elevador->capacidade); 
	embarcadosVazio(embarcados,elevador->capacidade); /*RX SENHOR POR FAVOR*/
	lista_eventos = criaLista();
	preencheEventos(lista_eventos,&num_eventos);







	
	free(embarcados);
	return 0;
}
