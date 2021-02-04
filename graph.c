#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define PATH "Test2.txt"

Graph* initGraphFromFile()
{
	int i;
	int srcPage, destPage;
	FILE* file = NULL;
	char raw[100];
	Graph* graph;
	
	graph = malloc(sizeof(Graph));
	
	graph->nbLinks = 0;
	
	//Set nbLinks & nbPages
    file = fopen(PATH, "r+");
	
	if (file==NULL){
		fprintf(stderr, "Erreur : Probleme à l'ouverture du fichier.\n");
		exit(EXIT_FAILURE);
    }
    
    while ( fgets( raw, 100, file) != NULL ){
		sscanf(raw,"%d %d", &srcPage, &destPage);
        graph->nbLinks++;
    }
    graph->nbPages = srcPage+1;
    
    fclose(file); 
	
    //Allocate tabs    
    graph->value=(float*)malloc(graph->nbPages * sizeof(float));
    
    graph->newValue=(float*)malloc(graph->nbPages * sizeof(float));
    
    graph->probaPages=(float*)malloc(graph->nbPages * sizeof(float));
    
    graph->probaLinks=(float*)malloc(graph->nbLinks * sizeof(float));
    
    graph->raw=(int*)malloc(graph->nbLinks * sizeof(int));
    
    graph->columns=(int*)malloc(graph->nbLinks * sizeof(int));
    
    for(i=0;i<graph->nbPages;i++){
		graph->value[i] = 0;
		graph->newValue[i] = 0;
		graph->probaPages[i] = 0;
	}
	
    //Set tabs
    file = fopen(PATH, "r+");
	
	if (file==NULL){
		fprintf(stderr, "Erreur : Probleme à l'ouverture du fichier.\n");
		exit(EXIT_FAILURE);
    }
    
    i = 0;
    while ( fgets( raw, 100, file) != NULL ){
		sscanf(raw,"%d %d", &srcPage, &destPage);
		
		graph->raw[i] = srcPage;
		graph->columns[i] = destPage;
		graph->probaPages[srcPage] += 1;
			
		i++;
    }
    
    for(i=0;i<graph->nbPages;i++){
		graph->probaPages[i] = 1/graph->probaPages[i];
	}
    
    for(i=0;i<graph->nbLinks;i++){
		graph->probaLinks[i]=graph->probaPages[graph->raw[i]];
	}
    
    fclose(file); 
    
	return graph;
}

void freeGraph(Graph* graph){
	   
	free(graph->value);
	free(graph->newValue);
	free(graph->probaPages);
	free(graph->probaLinks);
	free(graph->raw);
	free(graph->columns);

}

void printGraph(Graph* graph){

	int i;
	for(i=0;i<graph->nbLinks;i++){
		printf("%d %d %f\n",graph->raw[i],graph->columns[i],graph->probaLinks[i]);
	}
}
