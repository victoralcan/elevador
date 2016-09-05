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
	bool subindo;
}elevador;
	
