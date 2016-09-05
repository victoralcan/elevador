#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int aux,globalTimer=0,entrada,saida,andares = 16;
	srand(time(NULL));
	
	for(int i = 0;i < 20;i++)
	{
		aux = rand();
		entrada = aux % (andares - 1);
		aux = rand();
		saida = aux % (andares - 1);
		globalTimer += 4;
		printf("%d %d\n",entrada,saida);
	}
	return 0;
}