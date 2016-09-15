typedef int bool;
#define true 1
#define false 0

typedef struct Passageiro{
	int andar_entrada;
	int andar_destino;
	int numero; 
	int tempo_entrada; 
	int tempo_saida;
	int tempo_chamada;
	bool dentro;
	bool subindo;
}Passageiro;

typedef struct Elevador{
	int andar_atual;
	int ocupantes;
	int capacidade;
	int andares;
	int tempo;
	bool subindo;
}Elevador;

typedef struct celula {
  struct Item *item;
  struct Item *proximo;
} celula;

typedef struct tlista{
  struct celula *primeiro;
  struct celula *ultimo;
}tlista;

typedef struct Item{
	Passageiro passageiro;
}Item;


void elevadorDescendo(); /*Tratamento do elevador descendo*/
void elevadorSubindo(); /*Tratamento do elevador subindo*/
void elevadorParado(); /*Não tem nenhuma chamada pendente, mas continua incrementando o tempo*/
void aoEntrar(); /*O que fazer ao entrar (ordenar vetor de prioridades e passageiros)*/
void aoSair(); /*Executas certas acoes ao deixar o passageiro no destino*/
void trataTempo(); /*Calcula os tempos de viagem e etc para imprimir*/
void escreveLog();/*Escreve no arquivo texto de saida dos eventos*/
void iniciaElevador(Elevador *elevador); /*Inicializa o elevador*/
void leArquivos(Elevador *elevador); /*Lê os arquivos de ambiente e eventos*/
void embarcadosVazio(Passageiro embarcados[],int capacidade); /*Preenche o vetor de embarcados*/
tlista* criaLista();/*Cria uma lista*/
void preencheEventos(tlista *lista_eventos, int* num_eventos); /*Lê o arquivo de eventos, preenche vetor, ordena e preenche lista*/
int compara(const void* x,const void* y); /*Função para o qsort*/
void insereCompara(Item item,int p,tlista *lista); /*Compara para saber onde inserir o item na lista (inicio, meio ou fim)*/
void inserePrimeiro(Item item,tlista *lista); /*Insere no inicio da lista*/
void insereMeio(Item item,int p,tlista *lista); /*Insere no meio da lista*/
void insereFim(Item item,int p,tlista *lista); /*Insere no final da lista*/
