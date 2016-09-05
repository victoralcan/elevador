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
} Passageiro;

typedef struct{
	int andar_atual;
	int passageiros;
	int ocupantes;
	bool subindo;
}elevador;

void elevadorDescendo(); /*Tratamento do elevador descendo*/
void elevadorSubindo(); /*Tratamento do elevador subindo*/
void elevadorParado(); /*Não tem nenhuma chamada pendente, mas continua incrementando o tempo*/
void aoEntrar(); /*O que fazer ao entrar (ordenar vetor de prioridades e passageiros)*/
void trataTempo(); /*Calcula os tempos de viagem e etc para imprimir*/
void escreveLog();/*Escreve no arquivo texto de saida dos eventos*/

