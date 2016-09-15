#include <stdio.h>
#include <stdlib.h>
#include "elevador.h"


int main()
{
	Elevador elevador;
	Passageiro *embarcados;
	tlista *subindo;
	tlista *prox_subindo;
	tlista *descendo;
	tlista *prox_descendo;
	tlista *lista_eventos;
	int num_eventos = 0;


	leArquivos(&elevador);
	iniciaElevador(&elevador);
	embarcados = (Passageiro*) malloc(sizeof(Passageiro) * elevador.capacidade); 
	embarcadosVazio(embarcados,elevador.capacidade); /*RX SENHOR POR FAVOR*/
	lista_eventos = criaLista();
	subindo = criaLista();
	prox_subindo = criaLista();
	descendo = criaLista();
	prox_descendo = criaLista();
	preencheEventos(lista_eventos,subindo,descendo,&num_eventos);
	printf("%d \n", lista_eventos->primeiro->item.passageiro.tempo_chamada);
	printf("%d \n", lista_eventos->ultimo->item.passageiro.tempo_chamada);
	/*while(num_eventos > 0)
	{
		elevadorSubindo(&elevador,lista_eventos,embarcados,&num_eventos);         /*Primeiro subindo porque ele começa no andar 0*/
		/*elevadorDescendo(&elevador,lista_eventos,embarcados,&num_eventos);
	}*/





	
	free(embarcados);
	return 0;
}
