#include <stdio.h>
#include <stdlib.h>
#include "pageRank.h"

void pageRank(Graph* g, int startPage, int it){

	int iterations;
	int i;

	if(it <= 0){
		printf("Error, wrong iteration number, choose a number above 0\n");
		return;
	}

	if(startPage < 0 || startPage >= g->nbPages){
		printf("Error, wrong first page, choose a page between 0 and %d\n",g->nbPages);
		return;
	}
	
	g->value[startPage] = 1;
	
	for(iterations = 0; iterations < it; iterations++){
		
		for(i=0;i<g->nbLinks;i++){
		
			if(g->value[g->raw[i]]!=0){
			
				g->newValue[g->columns[i]] += g->value[g->raw[i]] * g->probaLinks[i];
				
			}
			
		}
		
		for(i=0;i<g->nbPages;i++){
		
			g->value[i] = g->newValue[i];
			g->newValue[i] = 0;
		
		}
		
	}
	
}

void pageRankWithDampingFactor(Graph* g, int startPage, float dampingFactor, int it){
	
	int iterations;
	int i;
	float tmp,scalar;
	
	if(it <= 0){
		printf("Error, wrong iteration number, choose a number above 0\n");
		return;
	}

	if(startPage < 0 || startPage >= g->nbPages){
		printf("Error, wrong first page, choose a page between 0 and %d\n",g->nbPages);
		return;
	}
	
	if(dampingFactor <= 0 || dampingFactor >= 1){
		printf("Error, wrong damping factor, choose a damping factor between 0 and 1\n");
		return;
	}
	
	g->value[startPage] = 1;
	scalar = 1.0;
	tmp = (1-dampingFactor) / g->nbPages;
	
	for(iterations = 0; iterations < it; iterations++){
		
		for(i=0;i<g->nbLinks;i++){
			
			if(g->value[g->raw[i]]!=0){
			
				g->newValue[g->columns[i]] += g->value[g->raw[i]] * g->probaLinks[i];
				
				
			}
			
		}
		
		for(i=0;i<g->nbPages;i++){
		
			g->newValue[i] = dampingFactor * g->newValue[i] + (tmp * scalar);
			
		}
		
		scalar = 0;
		for(i=0;i<g->nbPages;i++){
		
			g->value[i] = g->newValue[i];
			g->newValue[i] = 0;
			scalar += g->value[i];
			
		}
		
	}
	
}

void printValue(Graph* g){
	int i;
	FILE* file = NULL;
	file = fopen("Result.txt", "w+");
	
	if (file==NULL){
		fprintf(stderr, "Erreur : Probleme à l'ouverture du fichier.\n");
		exit(EXIT_FAILURE);
    }
	
	for(i=0;i<g->nbPages;i++){
		fprintf(file,"%d %.14f\n",i,g->value[i]);
	}
	fclose(file);

}
