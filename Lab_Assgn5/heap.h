#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct node{
    int *arr;
    int size;
    int rear;
}Heap;

void init(Heap *p,int a);
void insert(Heap* p,int a);
void swap(Heap* p,int i,int j);
void heapify(Heap* p,int a,int i);
void Display(Heap p);
void sort(Heap p);
void convert_to_min(Heap* p);
void Minheapify(Heap* p,int n);
void delete(Heap* p);
#endif // HEAP_H_INCLUDED
