#include <stdio.h>
#include <stdlib.h>
#include "pageRank.h"

//Algorithme PageRank simple
void pageRank(Graph* g, int startPage, int it){

	int iterations;
	int i;
	
	g->value[startPage] = 1;
	
	//Pour toutes les itérations
	for(iterations = 0; iterations < it; iterations++){
		
		//Pour tous les liens
		for(i=0;i<g->nbLinks;i++){
		
			//Si la chance d'être à la page source à ce clic différent de 0
			if(g->value[g->raw[i]]!=0){
			
				//On met à jour la chance d'être à la page de destinaton pour le clic suivant
				g->newValue[g->columns[i]] += g->value[g->raw[i]] * g->probaLinks[i];
				
			}	
		}
		
		//Pour toutes les pages
		for(i=0;i<g->nbPages;i++){
		
			//On passe au clic suivant
			g->value[i] = g->newValue[i];
			g->newValue[i] = 0;
		
		}
	}
	
}

//Algorithme PageRank amelioré
void pageRankWithDampingFactor(Graph* g, int startPage, float dampingFactor, int it){
	
	int iterations;
	int i;
	double tmp,scalar;
	
	g->value[startPage] = 1;
	scalar = 1.0;
	tmp = (1-dampingFactor) / g->nbPages;
	
	//Pour toutes les itérations
	for(iterations = 0; iterations < it; iterations++){
		
		//Pour tous les liens
		for(i=0;i<g->nbLinks;i++){
			
			//Si la chance d'être à la page source à ce clic différent de 0
			if(g->value[g->raw[i]]!=0){
			
				//On met à jour la chance d'être à la page de destinaton pour le clic suivant
				g->newValue[g->columns[i]] += g->value[g->raw[i]] * g->probaLinks[i];
				
			}
		}
		
		//Pour toutes les pages
		for(i=0;i<g->nbPages;i++){
		
			//On met de nouveau à jour la chance d'être à la page de destinaton pour le clic suivant
			//Grâce au facteur d'amortissement
			g->newValue[i] = dampingFactor * g->newValue[i] + (tmp * scalar);
			
		}
		
		scalar = 0;
		//Pour toutes les pages
		for(i=0;i<g->nbPages;i++){
		
			//On passe au clic suivant
			g->value[i] = g->newValue[i];
			g->newValue[i] = 0;
			scalar += g->value[i];
			
		}
	}
	
}

//Remplit un fichier avec les résultats
void printValue(Graph* g){
	int i;
	FILE* file = NULL;
	file = fopen("Result.txt", "w+");
	
	if (file==NULL){
		fprintf(stderr, "Erreur : Probleme à l'ouverture du fichier.\n");
		exit(EXIT_FAILURE);
    }
	
	//Pour toutes les pages
	for(i=0;i<g->nbPages;i++){
		
		//On écrit l'identifiant de la page et la chance de se trouver sur cette dernière
		fprintf(file,"%d %.15f\n",i,g->value[i]);
	}
	fclose(file);
	
	printf("Fichier Result.txt mis à jour.\n");

}
