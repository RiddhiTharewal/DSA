
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"heap.h"
void init(Heap* p, int a){
    p->size = a;
    p->rear = -1;
    p->arr = (int*)malloc(sizeof(int)*a);
    return;
}

void swap(Heap* p, int i, int j){
    int t = p->arr[i];
    p->arr[i] = p->arr[j];
    p->arr[j] = t;
    return;
}
void insert(Heap* p,int a){
    if(p->rear == p->size-1){
        return;
    }
    p->rear++;
    int i = p->rear;
    p->arr[i] = a;
    while(i > 0){
        if(p->arr[(i-1)/2]<a){
            swap(p,(i-1)/2,i);
            i = (i-1)/2;
        }
        else
            return;
    }
    return;
}
void delete(Heap* p){
    int a = p->arr[p->rear-1];
    p->rear--;
    heapify(p,p->rear,0);
}
void heapify(Heap* p,int i,int n){
    int max = i;
    int l,r;
    l = 2*i+1;
    r = 2*i+2;
    if(l < n && p->arr[l] > p->arr[max])
        max = l;
    if(r < n && p->arr[r] > p->arr[max])
        max = r;
    if(max!=i){
        swap(p,i,max);
        heapify(p,max,n);
    }
}
void sort(Heap p){
    if(p.rear == -1)
        return;
    for(int i = p.rear;i>0;i--){
        swap(&p,0,i);
        heapify(&p,0,i);
    }
   /* for(int i = p.rear/2-1; i>=0;i--){
        heapify(&p,i,p.rear);
    }
    for(int i = p.rear; i>=0; i--){
        swap(&p,0,i);
        heapify(&p,0,i);
    }*/
    return;
}
/*void convert_to_min(Heap* p){
    for(int i = (p->rear-2)/2;i >=0;--i)
        Minheapify(p,i);
}
void Minheapify(Heap* p,int i){
    int l,r;
    int m = i;
    l = 2*i+1;
    r = 2*i+2;
    if((l < p->rear) && (p->arr[l] < p->arr[i]))
        m = l;
    if((r < p->rear) && (p->arr[r] < p->arr[i]))
        m = r;
    if(m!=i){
        swap(p,i,m);
        Minheapify(p,m);
    }
}*/
void display(Heap p){
    for(int i = 0;i<=p.rear;i++){
        printf("%d ",p.arr[i]);
    }
}
