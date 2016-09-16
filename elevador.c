#include <stdio.h>
#include <stdlib.h>
#include "elevador.h"

void buscano()
{

}

void deixano()
{

}

void deixandoFcfs(Elevador *elevador,Passageiro embarcados[])
{
	if(embarcados[0].subindo == true)
	{
		while(elevador->andar_atual < embarcados[0].andar_destino)
		{
			elevador->andar_atual = elevador->andar_atual + 1;
			elevador->tempo = elevador->tempo + 1;
			trataTempo(elevador);
		}
	}
	else
	{
		while(elevador->andar_atual > embarcados[0].andar_destino)
		{
			elevador->andar_atual = elevador->andar_atual - 1;
			elevador->tempo = elevador->tempo + 1;
			trataTempo(elevador);
		}

	}
	elevador->tempo = elevador->tempo + 1;
	embarcados[0].tempo_saida = elevador->tempo;
	aoSair(embarcados[0]);
	embarcados[0] = embarcados[1];
	elevador->ocupantes = 0;
}

void elevadorDescendoFcfs(Elevador *elevador, tlista *lista_eventos, Passageiro embarcados[], Passageiro *aux)
{
	while(elevador->andar_atual > aux->andar_entrada)
	{
		elevador->andar_atual = elevador->andar_atual - 1;
		elevador->tempo = elevador->tempo + 1;
		trataTempo(elevador);
	}
	aux->tempo_entrada = elevador->tempo;
	aux->dentro = true;
	if(aux->andar_entrada > aux->andar_destino)
	{
		aux->subindo =  false;
	}
	else
	{
		aux->subindo = true;
	}
	aoEntrar(*aux);
	embarcados[0] = (*aux);
	elevador->ocupantes = 1;
	deixandoFcfs(elevador,embarcados);
}

void elevadorSubindoFcfs(Elevador *elevador, tlista *lista_eventos, Passageiro embarcados[], Passageiro *aux)
{
	while(elevador->andar_atual < aux->andar_entrada)
	{
		elevador->andar_atual = elevador->andar_atual + 1;
		elevador->tempo = elevador->tempo + 1;
		trataTempo(elevador);
	}
	aux->tempo_entrada = elevador->tempo;
	aux->dentro = true;
	if(aux->andar_entrada > aux->andar_destino)
	{
		aux->subindo =  false;
	}
	else
	{
		aux->subindo = true;
	}
	aoEntrar(*aux);
	embarcados[0] = (*aux);
	elevador->ocupantes = 1;
	deixandoFcfs(elevador,embarcados);
}

void elevadorDescendo(Elevador *elevador,tlista *lista_eventos,tlista *descendo,Passageiro embarcados[],int* num_eventos)/*Tratamento do elevador descendo*/
{

} 

void elevadorSubindo(Elevador *elevador,tlista *lista_eventos,tlista *subindo,tlista *prox_subindo,Passageiro embarcados[],int* num_eventos) /*Tratamento do elevador subindo*/
{
	/*while(elevador->andar_atual != prox_subindo->ultimo->item.passageiro.andar_destino)
	{
		elevadorParado();

	}*/
}

void elevadorParado(Elevador *elevador,tlista *lista_eventos,Passageiro embarcados[]) /*Não tem nenhuma chamada pendente, mas continua incrementando o tempo*/
{
	/*while(elevador->ocupantes == 0 && elevador->tempo < passageiro.) {
		elevador->tempo++;
	}*/
}

void leArquivos(Elevador *elevador) /*Lê os arquivos do elevador e eventos*/
{
  	int a,c;
	FILE *fp;
	fp = fopen("elevador.txt","r");
	if(fp == NULL)
	{
		printf("Não foi possivel abrir arquivo do elevador\n");
		return;
	}
	else
	{
		fscanf(fp,"%d %d",&a,&c);
		fclose(fp);
		elevador->andares = a;
	    elevador->capacidade = c;
	}
}

void embarcadosVazio(Passageiro embarcados[], int capacidade)
{
	Passageiro vazio;
	vazio.andar_entrada = -1;
	vazio.andar_destino = -1;
	vazio.numero = 0;	
	vazio.tempo_entrada = -1;
	vazio.tempo_saida = -1;
	vazio.tempo_chamada = -1;
	vazio.dentro = false;
	for(int a=0;a<capacidade;a++)
	{
		embarcados[a] = vazio;
	}
}

void iniciaElevador(Elevador *elevador) /*Inicializa o elevador*/
{
	 elevador->tempo = 0;
	 elevador->andar_atual = 0;
	 elevador->ocupantes = 0;
	 elevador->subindo = false;
}

tlista* criaLista()
{
	tlista *nova = (tlista*) malloc(sizeof(tlista));
	nova->ultimo = NULL;
	nova->primeiro = NULL;
	return nova;
}

void preencheEventos(tlista *lista_eventos, tlista *entrada, tlista *destino, int *num_eventos) /*Lê o arquivo de eventos, preenche vetor, ordena e preenche lista*/
{
	FILE *fp;
	Passageiro *eventos;
	Item item;
	int aux,a1,a2,a3,num = 1;
	fp = fopen("eventos.txt","r");
	if(fp == NULL)/*COLOQUEI OS DOIS IGUAIS CERTOS AGR SEU FDP*/
	{
		printf("Não foi possivel abrir o arquivo de eventos\n");
	}
	else
	{
		while(!feof(fp)) /*Enquanto nao chegar no fim do arquivo*/
		{
			fscanf(fp,"%d %d %d\n",&aux,&a1,&a2);
			*num_eventos=*num_eventos+1;
		}
		
		a1 =  (*num_eventos);
		eventos = (Passageiro*)malloc(sizeof(Passageiro) * a1);
		rewind(fp);

		for(aux = a1-1;aux >= 0;aux--)   /*Preencher o vetor com os dados do arquivo*/
		{
			fscanf(fp,"%d %d %d\n",&eventos[aux].andar_entrada,&eventos[aux].andar_destino,&eventos[aux].tempo_chamada);
			eventos[aux].numero = num;
			num++;
		}

		fclose(fp);
		
		qsort(eventos,a1,sizeof(Passageiro),&compara);/*Ordenar o vetor de acordo com o tempo*/

		/*a1 = 0;
		a2 = 0;*/

		for(aux=0;aux < *num_eventos;aux++) /*Preencher a lista (O COMPARA TA ORDENANDO TUDO PELO TEMPO. PARA PREENCHER DE OUTRO JEITO, FAZ OUTRA COMPARA E OUTRO QSORT PRA ORDENAR O VETOR*/
		{
			item.passageiro = eventos[aux];
			if(item.passageiro.andar_entrada<item.passageiro.andar_destino)
			{
				item.passageiro.subindo = true;
			}
			else
			{
				item.passageiro.subindo = false;
			
			}
			if(aux == 0)
			{
				inserePrimeiro(item,lista_eventos);
			}
			else
			{
				insereInicio(item, lista_eventos);
			}
		}
		/*AGORA VOCE VAI ORDENAR DE ACORDO COM AS ENTRADAS*/
		/*DA O QSORT NO VETOR COM A COMPARAENTRADA(EU NAO FIZ, FAÇA)*/
		/*LOOP QUE PREENCHE A LISTA "entradas" COM OS ELEMENTOS DO VETOR (SO VER O JEITO Q EU FIZ, É A MESMA COISA*/
		/*AGORA VOCE VAI ORDENAR DE ACORDO COM OS DESTINOS*/
		/*DA O QSORT NO VETOR COM A COMPARADESTINO(JA FIZ RX)*/
		/*LOOP QUE PREENCHE A LISTA "destino" COM O VETOR*/
		
		free(eventos);	
	}
}

int compara(const void* x,const void* y) /*Funcao parametro para a qsort*/
{
	const Passageiro *x1 = (const Passageiro*) x;
	const Passageiro *y1 = (const Passageiro*) y;

	if (x1->tempo_chamada < y1->tempo_chamada)
	{ 
		return 1;
	}
	if (x1->tempo_chamada > y1->tempo_chamada)
	{
	 	return  -1;
	}
	
	return 0;
}

int comparaDestino(const void* x,const void* y) /*Funcao parametro para a qsort*/
{
	const Passageiro *x1 = (const Passageiro*) x;
	const Passageiro *y1 = (const Passageiro*) y;

	if (x1->andar_destino < y1->andar_destino)
	{ 
		return 1;
	}
	if (x1->andar_destino > y1->andar_destino)
	{
	 	return  -1;
	}
	
	return 0;
}

void inserePrimeiro(Item item,tlista *lista)
{
  celula *nova = (celula*) malloc(sizeof(celula));
  nova->item = item;
  nova->proximo = NULL; /*não existe proximo pois o elemento é o primeiro*/

  lista->primeiro = nova; 
  lista->ultimo = nova;
}

void insereInicio(Item item,tlista *lista)
{
  celula *nova = (celula*) malloc(sizeof(celula)); /*(celula*) usado para acessar mem alocada*/
  nova->item = item;   /*item da nova struct recebe valor dado*/

  nova->proximo = lista->primeiro; /*passa o pont primeiro para o pont proximo*/

  lista->primeiro = nova; /*passa o pont nova para o pont proximo*/
}

void remover(int pos, tlista *l)
{
	if(l->primeiro == NULL)
  {
		return ;
	}	
	if(pos < 0)
  {
		return ;
	}
	celula *removido = l->primeiro;
	celula *ant_removido = NULL;
	int i = 0;	
	for (i = 0; i < pos && removido != NULL; i++) 
  {
		ant_removido = removido;
		removido = removido->proximo;
	}
	if(removido != NULL)
  {
		if(removido == l->primeiro)
    {
			l->primeiro = removido->proximo;		
		}
    else
    {
			ant_removido->proximo = removido->proximo;		
		}
		if(removido == l->ultimo){
			l->ultimo = ant_removido;
		}
		free(removido);
	}
	return ;
}


void fcfs(Elevador *elevador, tlista *lista_eventos, Passageiro embarcados[], int *num_eventos)
{
	do
	{
		trataTempo(elevador);
		Passageiro aux = lista_eventos->primeiro->item.passageiro;	
		while(elevador->tempo < aux.tempo_chamada)
		{
			elevador->tempo = elevador->tempo + 1;
			trataTempo(elevador);
		}
		if(elevador->andar_atual > aux.andar_entrada)
		{
			elevadorDescendoFcfs(elevador,lista_eventos,embarcados,&aux);
		}
		else if (elevador->andar_atual < aux.andar_entrada)
		{
			elevadorSubindoFcfs(elevador,lista_eventos,embarcados,&aux);
		}
		else
		{
			embarcados[0] = aux;
			elevador->tempo = elevador->tempo + 1;
			trataTempo(elevador);
			deixandoFcfs(elevador,embarcados);
		}
		remover(0,lista_eventos);
		*num_eventos = *num_eventos - 1;
	}while(*num_eventos > 0);
	printf("acabou!!!!!!!!\n");
}
