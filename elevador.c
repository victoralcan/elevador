#include <stdio.h>
#include <stdlib.h>
#include "elevador.h"

void buscano()
{

}

void deixano()
{

}

void removeAll(tlista *lista){
  celula *aux = lista->primeiro;
  celula *atual = lista->primeiro;

  while(atual != NULL){
    atual = atual->proximo;
    free(aux);
    aux = atual;
  } /*desaloca a lista passada por parâmetro*/

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
void elevadorDescendo(Elevador *elevador,tlista *lista_eventos,tlista *lista_descendo,Passageiro embarcados[])/*Tratamento do elevador descendo*/
{
  celula *atual = lista_descendo->primeiro;

  do
  {
    if (elevador->tempo >= atual->item.passageiro.tempo_chamada)
    {
      if (elevador->andar_atual < atual->item.passageiro.andar_entrada)
      {
        printf("NAO VAI DÁ NAO\n");
        printf("FOI %d %d\n",atual->item.passageiro.andar_entrada,atual->item.passageiro.andar_destino);
        atual = atual->proximo;
        printf("PROX %d %d\n",atual->item.passageiro.andar_entrada,atual->item.passageiro.andar_destino);
      }
      else
      {
        printf("QUE NÃO VAI DAR O QUE!!!\n");
      }
    }
    elevador->tempo++;
    elevador->andar_atual--;
  }while(elevador->andar_atual != 0);
  printf("ACABOU DESCIDA MANO\n");
  getchar();

} 

void elevadorSubindo(Elevador *elevador,tlista *lista_eventos,tlista *lista_subindo,Passageiro embarcados[]) 
{
  celula *atual = lista_subindo->primeiro;


	do
	{
    if (elevador->tempo >= atual->item.passageiro.tempo_chamada)
    {
      if(elevador->andar_atual > atual->item.passageiro.andar_entrada)
      {
        printf("NAO VAI DÁ NAO\n");
        printf("FOI %d %d\n",atual->item.passageiro.andar_entrada,atual->item.passageiro.andar_destino);
        atual = atual->proximo;
        printf("PROX %d %d\n",atual->item.passageiro.andar_entrada,atual->item.passageiro.andar_destino);

      }
      else
      {
        printf("QUE NÃO VAI DAR O QUE!!!\n");
      }
      
    }
    printf("%d %d\n",elevador->andar_atual,elevador->tempo);
    elevador->tempo++;
    elevador->andar_atual++;
	}while(elevador->andar_atual != elevador->andares);
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

void preencheEventos(tlista *lista_eventos,tlista *lista_subindo,tlista *lista_descendo,tlista *entrada, tlista *destino, int* num_eventos) /*Lê o arquivo de eventos, preenche vetor, ordena e preenche lista*/
{
	FILE *fp;
	Passageiro *eventos, *eventos_sobem, *eventos_descem;
	Item item;
	int aux,a1,a2,a3,num = 1;
  int conta_sobe = 0;
  int conta_desce = 0;

	fp = fopen("eventos.txt","r");
	if(fp == NULL)
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
    eventos_sobem = (Passageiro*)malloc(sizeof(Passageiro) * a1);/*alocando mais que necessario*/
    eventos_descem = (Passageiro*)malloc(sizeof(Passageiro) * a1);/*alocando mais que necessario*/

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
			if(item.passageiro.andar_entrada < item.passageiro.andar_destino)
			{
				item.passageiro.subindo = true;

        eventos_sobem[conta_sobe] = eventos[aux];
        eventos_sobem[conta_sobe].subindo = true;
        conta_sobe++;
			}
			else
			{
				item.passageiro.subindo = false;

        eventos_descem[conta_desce] = eventos[aux];
        eventos_descem[conta_desce].subindo = false;
        conta_desce++;
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

    qsort(eventos_sobem,conta_sobe,sizeof(Passageiro),&comparaEntrada);/*Ordenar de acordo com o tempo e entrada*/
    qsort(eventos_descem,conta_desce,sizeof(Passageiro),&comparaEntrada); /*Ordenar de acordo com o tempo e saida*/
    

    for(aux = conta_desce-1;aux >= 0;aux--)
    {
      item.passageiro = eventos_descem[aux];
      if(aux == conta_desce-1)
      {
        inserePrimeiro(item,lista_descendo);
      }
      else
      {
        insereInicio(item, lista_descendo);
      }
    }

    for(aux = conta_sobe-1;aux >= 0;aux--)
    {
      item.passageiro = eventos_sobem[aux];
      if(aux == conta_sobe-1)
      {
        inserePrimeiro(item,lista_subindo);
      }
      else
      {
        insereInicio(item, lista_subindo);
      }
    }

	 free(eventos);	
   free(eventos_sobem);
   free(eventos_descem);
	}

    lista_descendo->ultimo->proximo = NULL;

    lista_subindo->ultimo->proximo = NULL;

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

  if (x1->tempo_chamada < y1->tempo_chamada)
  { 
    return 1;
  }
  if (x1->tempo_chamada > y1->tempo_chamada)
  {
    return -1;
  }
  
  return 0;
}

int comparaEntrada(const void* x,const void* y) /*Funcao parametro para a qsort*/
{
  const Passageiro *x1 = (const Passageiro*) x;
  const Passageiro *y1 = (const Passageiro*) y;

  if (x1->tempo_chamada < y1->tempo_chamada)
  { 
    return -1;
  }
  if (x1->tempo_chamada > y1->tempo_chamada)
  {
    return 1;
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

void l_e_v(Elevador *elevador, tlista *lista_eventos,tlista *lista_subindo,tlista *lista_descendo, Passageiro embarcados[], int *num_eventos){
  Passageiro aux = lista_eventos->primeiro->item.passageiro;
  Item item;

  do
  {
    if(elevador->andar_atual == 0)
    {
     elevadorSubindo(elevador,lista_eventos,lista_subindo,embarcados); 
     printf("%d %d\n",elevador->andar_atual,elevador->andares );
    }
    else if(elevador->andar_atual == elevador->andares)
    {
      elevadorDescendo(elevador,lista_eventos,lista_descendo,embarcados);
    }

    *num_eventos = *num_eventos - 1;
  }while(*num_eventos > 0);


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
}
