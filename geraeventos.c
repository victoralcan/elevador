#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int aux,globalTimer=0,entrada,saida,andares = 16;
	srand(time(NULL));
	FILE *fp;
	fp = fopen("Eventos.txt","w");
	for(int i = 0;i < 40;i++)
	{
		aux = rand();
		entrada = aux % (andares - 1);
		aux = rand();
		saida = aux % (andares - 1);
		if (entrada == saida){
			aux = rand();
			saida = aux % (andares - 1);
		}
		printf("%d %d %d\n",entrada,saida,globalTimer);
		fprintf(fp, "%d %d %d\n",entrada,saida,globalTimer);
		globalTimer += 4;
	}
	return 0;
}
