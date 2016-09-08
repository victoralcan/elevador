typedef int bool;
#define true 1
#define false 0

typedef struct {
	int andar_entrada;
	int andar_destino;
	int numero; 
	int tempo_entrada; 
	int tempo_saida;
	int tempo_chamada;
	bool dentro;
	/*Talvez outra booleana para identificar se está subindo ou descendo*/
}Passageiro;

typedef struct{
	int andar_atual;
	int total_andares;
	int ocupantes;
	int capacidade;
	bool subindo;
}Elevador;

typedef struct celula {
  int item;
  struct celula *proximo;
  struct celula *ant;
} celula;

typedef struct tlista{
  struct celula *primeiro;
  struct celula *ultimo;
}tlista;

void elevadorDescendo(); /*Tratamento do elevador descendo*/
void elevadorSubindo(); /*Tratamento do elevador subindo*/
void elevadorParado(); /*Não tem nenhuma chamada pendente, mas continua incrementando o tempo*/
void aoEntrar(); /*O que fazer ao entrar (ordenar vetor de prioridades e passageiros)*/
void aoSair(); /*Executas certas acoes ao deixar o passageiro no destino*/
void trataTempo(); /*Calcula os tempos de viagem e etc para imprimir*/
void escreveLog();/*Escreve no arquivo texto de saida dos eventos*/
void iniciaElevador(); /*Inicializa o elevador*/
void leArquivos(); /*Lê os arquivos de ambiente e eventos*/
void embarcadosVazio(); /*Preenche o vetor de embarcados*/
