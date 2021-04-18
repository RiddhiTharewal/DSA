#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct edge{
    int src, dest, weight;
}edge;

typedef struct graph{
    int E,V;
    edge* arr;
}graph;

typedef struct MST{
    int index, parent;
}MST;
graph* create(int v,int e);
int findset(MST* arr, int a);
void Union(MST* arr, int a, int b);
int Sort(const void* x,const void* y);
void Kruskals(graph* g);
void Display(graph g);
void BellmanFord(graph* g,int a);
#endif // GRAPH_H_INCLUDED
