#include <stdio.h>
#include <stdlib.h>
#include "elevador.h"


void elevadorDescendo(Elevador *elevador,tlista *lista_eventos,Passageiro embarcados[],int* num_eventos)/*Tratamento do elevador descendo*/
{

} 

void elevadorSubindo(Elevador *elevador,tlista *lista_eventos,Passageiro embarcados[],int* num_eventos) /*Tratamento do elevador subindo*/
{

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
  elevador->andar_atual = -1;
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

void preencheEventos(tlista *lista_eventos, int *num_eventos) /*Lê o arquivo de eventos, preenche vetor, ordena e preenche lista*/
{
	FILE *fp;
	Passageiro *eventos;
	Item item;
	int aux,a1,a2,a3,num=1;;
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

		for(aux = 0;aux < a1;aux++)   /*Preencher o vetor com os dados do arquivo*/
		{
			fscanf(fp,"%d %d %d\n",&eventos[aux].andar_entrada,&eventos[aux].andar_destino,&eventos[aux].tempo_chamada);
		}

		fclose(fp);
		
		qsort(eventos,a1,sizeof(Passageiro),compara);/*Ordenar o vetor de acordo com o tempo*/

		for(aux=0;aux < *num_eventos;aux++) /*Preencher a lista*/
		{
			item.passageiro = eventos[aux];
			item.passageiro.numero = num;
			if(item.passageiro.andar_entrada<item.passageiro.andar_destino)
			{
				item.passageiro.subindo = true;
			}
			else
			{
				item.passageiro.subindo=false;
			}
			num++;
			if(aux == 0)
			{
				inserePrimeiro(item,lista_eventos);
			}
			else
			{
				insereInicio(item, lista_eventos);
			}

		}
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
