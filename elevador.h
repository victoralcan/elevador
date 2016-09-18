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

typedef struct Item{
	Passageiro passageiro;
}Item;

typedef struct celula {
  struct Item item;
  struct celula *proximo;
} celula;

typedef struct tlista{
  struct celula *primeiro;
  struct celula *ultimo;
}tlista;



void buscano(); /**/
void deixano(); /***/
void elevadorDescendo(Elevador *elevador,tlista *lista_eventos,tlista *descendo,Passageiro embarcados[]); /*Tratamento do elevador descendo*/
void elevadorDescendo(Elevador *elevador,tlista *lista_eventos,tlista *lista_descendo,Passageiro embarcados[]);/*Tratamento do elevador descendo*/
void elevadorParado(Elevador *elevador,tlista *lista_eventos,Passageiro embarcados[]); /*Não tem nenhuma chamada pendente, mas continua incrementando o tempo*/
void aoEntrar(Passageiro passageiro); /*Imprimir no arquivo log informações de entrada*/
void aoSair(Passageiro passageiro); /*Imprimir no arquivo log informações de saida*/
void trataTempo(Elevador *elevador); /*Imprime informações do elevador no arquivo log*/
void iniciaElevador(Elevador *elevador); /*Inicializa o elevador*/
void leArquivos(Elevador *elevador); /*Lê os arquivos de ambiente e eventos*/
void embarcadosVazio(Passageiro embarcados[],int capacidade); /*Preenche o vetor de embarcados*/
tlista* criaLista();/*Cria uma lista*/
void preencheEventos(tlista *lista_eventos,tlista *lista_subindo,tlista *lista_descendo,tlista *entrada, tlista *destino, int* num_eventos); /*Lê o arquivo de eventos, preenche vetor, ordena e preenche lista*/
int compara(const void* x,const void* y); /*Função para o qsort*/
int comparaEntrada(const void* x,const void* y); /*Função para o qsort*/
void inserePrimeiro(Item item,tlista *lista); /*Insere no inicio da lista*/
void insereInicio(Item item,tlista *lista); 
void removeItem(int p, tlista *lista);
void l_e_v(Elevador *elevador, tlista *lista_eventos,tlista *lista_subindo,tlista *lista_descendo, Passageiro embarcados[], int *num_eventos);
void fcfs(Elevador *elevador, tlista *lista_eventos, Passageiro embarcados[], int *num_eventos);
void elevadorDescendoFcfs(Elevador *elevador, tlista *lista_eventos, Passageiro embarcados[], Passageiro *aux);
void elevadorSubindoFcfs(Elevador *elevador, tlista *lista_eventos, Passageiro embarcados[], Passageiro *aux);
void deixandoFcfs(Elevador *elevador,Passageiro embarcados[]);
void remover(int pos, tlista *l);
void removeAll(tlista *lista); /*desaloca lista da memória*/
