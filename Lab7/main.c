#include<stdio.h>
#include"graph.h"

int main(){
    graph* g = create(5,7);    //Initialize graph with edges as 14 and 9 vertices
    g->arr[0].src = 0;
    g->arr[0].dest = 1;
    g->arr[0].weight = -1;
    g->arr[1].src = 0;
    g->arr[1].dest = 2;
    g->arr[1].weight = 4;
    g->arr[2].src = 1;
    g->arr[2].dest = 2;
    g->arr[2].weight = 3;
    g->arr[3].src = 1;
    g->arr[3].dest = 4;
    g->arr[3].weight =2;
    g->arr[4].src = 3;
    g->arr[4].dest = 2;
    g->arr[4].weight = 5;
    g->arr[5].src = 3;
    g->arr[5].dest = 1;
    g->arr[5].weight = 1;
    g->arr[6].src = 4;
    g->arr[6].dest = 3;
    g->arr[6].weight = 3;
   /* g->arr[7].src = 6;
    g->arr[7].dest = 8;
    g->arr[7].weight = 6;
    g->arr[8].src = 2;
    g->arr[8].dest = 3;
    g->arr[8].weight = 7;
    g->arr[9].src = 2;
    g->arr[9].dest = 5;
    g->arr[9].weight = 4;
    g->arr[10].src = 5;
    g->arr[10].dest = 6;
    g->arr[10].weight = 2;
    g->arr[11].src = 3;
    g->arr[11].dest = 4;
    g->arr[11].weight =9;
    g->arr[12].src = 4;
    g->arr[12].dest = 5;
    g->arr[12].weight = 10;
    g->arr[13].src = 3;
    g->arr[13].dest = 5;
    g->arr[13].weight = 14;*/
    Display(*g);    //WIll display adjacency matrix
    printf("\nKruskal's Output\n");
    Kruskals(g);
    BellmanFord(g,0);
    return 0;
}
