/*--------------------------------------------------
Project: CP264-a10q3
File:    algorithm.c
Description: 
Author:  Nish Tewari  
Version: 2021-04-09
---------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h> 
#include "heap.h"
#include "algorithm.h"

EDGELIST *mst_prim(GRAPH *g, int start) {
    // your implementation
    if (g == NULL)
		return NULL;
	int i, heapindex, n = g->order, tree[n], parent[n];
	HNODE hn;
	HEAP *h = new_heap(4);
	for (i = 0; i < n; i++)
		tree[i] = 0;
	for (i = 0; i < n; i++)
		parent[i] = -1;
	tree[start] = 1;
	ADJNODE *temp = g->nodes[start]->neighbor;
	while (temp != NULL) {
		hn.key = temp->weight;
		hn.data = temp->nid;
		insert(h, hn);
		parent[temp->nid] = start;
		temp = temp->next;
	}
	EDGELIST *mst = new_edgelist();
	while (h->size > 0) {
		hn = extract_min(h);
		i = hn.data;
		tree[i] = 1;
		add_edge_end(mst, parent[i], i, hn.key);
		temp = g->nodes[i]->neighbor;
		while (temp != NULL) {
			heapindex = find_index(h, temp->nid);
			if (heapindex >= 0) {
				if (tree[temp->nid] == 0
						&& temp->weight < h->hnap[heapindex].key) {
					decrease_key(h, heapindex, temp->weight);
					parent[temp->nid] = i;
				}
			} else {
				if (tree[temp->nid] == 0) {
					hn.key = temp->weight;
					hn.data = temp->nid;
					insert(h, hn);
					parent[temp->nid] = i;
				}
			}
			temp = temp->next;
		}
	}
	return mst;
}

EDGELIST *spt_dijkstra(GRAPH *g, int start) {
	if (!g) {
		return NULL;
	}
	EDGELIST *spt = new_edgelist();
	int i, heapindex, u, n = g->order;
	int T[n], parent[n], label[n];
	HNODE hn;
	for (i = 0; i < n; i++) {
		T[i] = 0;
		label[i] = INFINITY;
	}
	HEAP *h = new_heap(4);
	ADJNODE *temp = g->nodes[start]->neighbor;
	label[start] = 0;
	T[start] = 1;
	while (temp) {
		hn.key = temp->weight + label[start];
		hn.data = temp->nid;
		insert(h, hn);
		parent[temp->nid] = start;
		temp = temp->next;
	}
	while (h->size > 0) {
		hn = extract_min(h);
		u = hn.data;
		T[u] = 1;
		add_edge_end(spt, parent[u], u, hn.key);
		temp = g->nodes[u]->neighbor;
		while (temp) {
			heapindex = find_index(h, temp->nid);
			if (heapindex >= 0) {
				if (T[temp->nid] == 0
						&& temp->weight + label[u] < h->hnap->key) {
					decrease_key(h, heapindex, temp->weight + label[u]);
					parent[temp->nid] = u;
				}
			} else {
				if (T[temp->nid] == 0) {
					hn.key = temp->weight;
					hn.data = temp->nid;
					insert(h, hn);
					parent[temp->nid] = u;
				}
			}
			temp = temp->next;
		}
	}
	return spt;
}

EDGELIST *sp_dijkstra(GRAPH *g, int start, int end) {
	if (!g) {
		return NULL;
	}
	int i, heapindex, u, n = g->order, parent[n], visited[n], label[n];
	for (i = 0; i < n; i++) {
		visited[i] = 0;
		label[i] = INFINITY;
	}
	HEAP *h = new_heap(4);
	ADJNODE *temp = g->nodes[start]->neighbor;
	visited[start] = 1;
	label[start] = 0;
	HNODE hn;
	while (temp) {
		hn.key = temp->weight;
		hn.data = temp->nid;
		insert(h, hn);
		parent[temp->nid] = start;
		visited[temp->nid] = 0;
		label[temp->nid] = label[start] + temp->weight;
		temp = temp->next;
	}
	EDGELIST *spt = new_edgelist();
	while (h->size > 0) {
		HNODE gn = extract_min(h);
		u = gn.data;
		visited[u] = 1;
		add_edge_end(spt, parent[u], u, label[u] - label[parent[u]]);
		if (u == end)
			break;
		temp = g->nodes[u]->neighbor;
		HNODE hn2;
		while (temp) {
			heapindex = find_index(h, temp->nid);
			if (heapindex >= 0) {
				if (visited[temp->nid] == 0
						&& temp->weight + label[u] < h->hnap->key) {
					decrease_key(h, heapindex, temp->weight + label[u]);
					parent[temp->nid] = u;
					label[temp->nid] = temp->weight + label[u];
				}
			} else {
				if (visited[temp->nid] == 0) {
					hn2.key = temp->weight + label[u];
					hn2.data = temp->nid;
					insert(h, hn2);
					parent[temp->nid] = u;
					label[temp->nid] = temp->weight + label[u];
				}
			}
			temp = temp->next;
		}
	}
	EDGELIST *sp = new_edgelist();
	sp->size = 0;
	while (u != start) {
		add_edge_start(sp, parent[u], u, label[u] - label[parent[u]]);
		u = parent[u];
	}
	return sp;
}