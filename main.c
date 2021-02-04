#include <stdio.h>
#include <stdlib.h>
 
#include "graph.h"
#include "pageRank.h"
 
int main() {
  
	int startPage;
	float dampingFactor;
	int iterations;
	Graph* g = initGraphFromFile();

	printf("Sur quel page démarrer ? (entre 0 et %d)\n",g->nbPages);
	scanf(" %d",&startPage);
	if(startPage < 0 || startPage >= g->nbPages){
		printf("Erreur, mauvais nombre d'itérations, choisissez une page entre 0 et %d\n",g->nbPages);
		return 0;
	}
	
	printf("Quel facteur d'amortissement ? (entre 0 et 1)\n");
	scanf(" %f",&dampingFactor);
	if(dampingFactor < 0 || dampingFactor > 1){
		printf("Erreur, mauvais facteur d'amortissement, choisissez un facteur d'amortissement entre 0 et 1\n");
		return 0;
	}

	printf("Combien d'itérations ? (au dessus de 0)\n");
	scanf(" %d",&iterations);
	if(iterations <= 0){
		printf("Erreur, mauvais nombre d'itérations, choisissez un nombre au dessus de 0\n");
		return 0;
	}

	pageRankWithDampingFactor(g,startPage,dampingFactor,iterations);
	printValue(g);
  
	free(g);
  
  return 0;
}
