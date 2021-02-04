#include <stdio.h>
#include <stdlib.h>
 
#include "graph.h"
#include "pageRank.h"
 
int main() {

  Graph* g = initGraphFromFile();
 
  pageRank(g,0,10000);
  //pageRankWithDampingFactor(g,2,0.8,100);
  
  //printGraph(g);
  
  printValue(g);
  
  free(g);
  
  return 0;
}
