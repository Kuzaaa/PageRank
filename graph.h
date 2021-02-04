#ifndef __GRAPH__H__
#define __GRAPH__H__
	
	typedef struct Graph Graph;
	struct Graph
	{
		int nbPages;				//Nombre de pages
		int nbLinks;				//Nombre de liens
		float* value;				//Valeur à l'itération k
		float* newValue;			//Valeur à l'itération k+1
		float* probaLinks;			//Probalité par lien
		float* probaPages;			//Probabilité par page
		int* raw;					//Ligne de la matrice de transition
		int* columns;				//Colonne de la matrice de transition
	};

	Graph* initGraphFromFile();
	void freeGraph(Graph* g);
	void printGraph(Graph* g);

#endif
