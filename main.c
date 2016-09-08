#include <stdio.h>
#include "elevador.h"

/*Argv[1] é elevador*/
/*Argv[2] é eventos*/

int main(int agrc, char *argv[])
{
	int capacidade;
	Elevador elevador;
	Passageiro *embarcados;
	inicializaElevador(elevador, argv[1]);
	embarcados = (Passageiro*) malloc(sizeof(Passageiro) * elevador.capacidade); 
	embarcadosVazio(embarcados,argv[1]); /*Preenche o vetor*/
	












	free(embarcados);
	return 0;
}
