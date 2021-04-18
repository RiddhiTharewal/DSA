/*
Name : Riddhi Tharewal
Mis : 111903068
*/
#include<stdio.h>
#include"graph.h"
#include<stdlib.h>
#include<limits.h>
graph* create(int v,int e){
    graph* g = (graph*)malloc(sizeof(graph));
    g->E = e;   //no of edges
    g->V = v;   //no of vertex
    g->arr = (edge*)malloc(sizeof(edge)*e); //Array of edges that which has member src, dest and weight of edges
    return g;
}


int findset(MST* arr, int a){
    if(arr[a].parent != a)
        arr[a].parent = findset(arr,arr[a].parent);
    return arr[a].parent;
}

void Union(MST* arr,int a,int b){
     int x, y;
     x = findset(arr, a);
     y = findset(arr, b);
     if(arr[x].index < arr[y].index)
        arr[x].parent = y;
     else if(arr[x].index > arr[y].index)
        arr[y].parent = x;
     else{
        arr[y].parent = x;
        arr[x].index++;
    }
}
int Sort(const void* x, const void* y){ //required while sorting the edges
    edge* a = (edge*)x;
    edge* b = (edge*)y;
    return a->weight - b->weight;
}
void Display(graph g){
    int Arr[g.V][g.V];
    for(int i = 0;i<g.V;i++){
        for(int j = 0;j<g.V; j++){
            Arr[i][j] = 0;
        }
    }
    for(int i = 0;i<g.E;i++){
            if(g.arr[i].weight != 0){
                Arr[g.arr[i].src][g.arr[i].dest] = g.arr[i].weight;
                Arr[g.arr[i].dest][g.arr[i].src] = g.arr[i].weight;
            }
    }
    printf("\nThis is Graph Adjacency Matrix Where 0 is simply use to assign max weight : \n");
    for(int i =0 ;i<g.V;i++){

        for(int j =0;j<g.V; j++){
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
}
void Kruskals(graph* g){
    int e = 0, i = 0,a, b, min = 0;
    MST* s = (MST*)malloc(g->V*sizeof(MST));
    edge r[g->V],p;
    qsort(g->arr,g->E,sizeof(g->arr[0]),Sort);  //Sorts the Edges with respect to weight of edges
    int j = 0;
    while(j<g->V){
        s[j].index = 0;
        s[j].parent = j;
        j++;
    }
    while(i < g->E && e<g->V-1){//as MST will have V-1 vertex
        p = g->arr[i++];
        a = findset(s, p.src);
        b = findset(s, p.dest);
        if(a != b){
            r[e] = p;
            e++;
            Union(s, a, b);
        }
    }
    j = 0;
    while(j < e){
        min+=r[j].weight;
        printf("\n%d -> %d has min weight %d",r[j].src,r[j].dest, r[j].weight);
        j++;
    }
    printf("\n%d is minimum cost ",min);
}
void BellmanFord(graph* g,int a){
    int dist[g->V];
    for(int i = 0; i < g->V; i++){
        dist[i] = INT_MAX;
    }
    dist[a] = 0;
    for(int i = 0;i<g->V-1;i++){
        for(int j = 0;j<g->E;j++){
            if(dist[g->arr[j].src]!=INT_MAX && dist[g->arr[j].src] + g->arr[j].weight < dist[g->arr[j].dest]){
                dist[g->arr[j].dest] = g->arr[j].weight + dist[g->arr[j].src];
            }
        }
    }
    for(int i = 0;i<g->V;i++){
        printf("\n%d->%d ",i,dist[i]);
    }
    }
