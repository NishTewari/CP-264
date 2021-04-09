/*--------------------------------------------------
Project: CP264-a10q3
File:    algorithm.h
Description: 
Author:  Nish Tewari  
Version: 2021-04-09
--------------------------------------------------
*/

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "edgelist.h"
#include "graph.h"

// your code document
EDGELIST *mst_prim(GRAPH *g, int start);

// your code document
EDGELIST *spt_dijkstra(GRAPH *g, int start);

// your code document
EDGELIST *sp_dijkstra(GRAPH *g, int start, int end);

#endif