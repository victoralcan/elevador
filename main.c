#include <stdio.h>
#include <stdlib.h>
#include "elevador.h"

/*Argv[1] é elevador*/
/*Argv[2] é eventos*/

int main()
{
	Elevador *elevador;
	Passageiro *embarcados;
	leArquivos(elevador);
	iniciaElevador(elevador);

	embarcados = (Passageiro*) malloc(sizeof(Passageiro) * elevador->capacidade); 
	/*embarcadosVazio(embarcados,elevador);*/
	printf("andar atual %d\n", elevador->andar_atual);
	printf("ocupantes %d\n", elevador->ocupantes);
	printf("subindo? %d\n", elevador->subindo);
	printf("andares %d\n", elevador->andares);
	printf("capacidade %d\n", elevador->capacidade);
	/*for(int i=0;i<capacidade;i++)
	{
		printf("andar entrada pass %d %d\n",i+1, embarcados[i].andar_entrada);
		printf("andar destino pass %d %d\n",i+1, embarcados[i].andar_destino);
		printf("numero pass %d %d\n",i+1, embarcados[i].numero);
		printf("tempo entrada pass %d %d\n",i+1, embarcados[i].tempo_entrada);
		printf("tempo saida pass %d %d\n",i+1, embarcados[i].tempo_saida);
		printf("dentro pass %d? %d\n",i+1, embarcados[i].dentro);
	}
	*/
	free(embarcados);
	return 0;
}
