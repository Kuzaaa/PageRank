Pour utiliser ce programme :
	
	1 - Dans le dosser PageRank, insérer votre graphe.
		
		Ce dernier doit être au format suivant: 
			* Aucun commentaires avant, au milieu ou après les données
			* 2 chiffres par ligne
			* Le premier chiffre représente la source et le deuxième la destination
			* Chaque ligne représente ainsi un lien allant de source vers destination
			* L'ordre n'importe pas
		
		Vous trouverez déjà 3 graphes au bon format:
			*ExempleCours.txt représentant le graphe vu en cours (diapo 34) ~ 5 pages et 10 arcs
			*email-eu-core.txt ~ 1005 pages et 25 571 arcs
			*soc-Epinions1.txt ~ 75 879 pages et 508 837 arcs
	
	2 - Renseignez le graphe choisi
	
		Dans le fichier graph.c, vous trouverez ligne 4 une variable PATH à remplacer.
		Insérer entre les guillements le nom du fichier texte représentant le graphe sur lequel vous voulez
		faire exécuter le programme.
		
	3 - Compiler le programme
	
		make all
		
	4 - Lancer le programme
	
		./prog
		
	5 - Execution du programme
	
		Le programme vous demandera la page de départ, le facteur d'amortissement ainsi que le nombre d'itérations voulu,
		puis s'éxecutera sur le graphe voulu.
		
	6 - Résultats

		Un fichier Result.txt sera créé (ou mis à jour s'il existe déjà) renseignant 2 valeurs par ligne:
			* L'identifiant du sommet
			* La chance d'être sur cette page après n itérations, n étant le chiffre que vous avez choisi plus tôt.


//Commentaires:

Le graphe est stockée de manière à optimiser les calculs sur une matrice creuse. En effet, nous le stockons à l'aide de 3 tableaux, représentant la source, la destination ainsi
que la probabilité de passer de l'un à l'autre. Ces tableaux ont pour taille le nombre de valeur (donc de ligne de notre fichier texte contenant le graphe) présent dans la matrice.
Il existe d'autres tableaux représentant la probabilité d'etre sur une certaine page au clic actuel, et au clic précédent.


