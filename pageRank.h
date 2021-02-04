#ifndef __PAGERANK__H__
#define __PAGERANK__H__

#include "graph.h"

		void pageRank(Graph* g, int startPage, int it);
		void pageRankWithDampingFactor(Graph* g, int startPage, float dampingFactor, int it);
		void printValue(Graph* g);

#endif

