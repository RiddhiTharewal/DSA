#ifndef QUEUEN_H_INCLUDED
#define QUEUEN_H_INCLUDED

#include"bst.h"

//typedef node* bst;
typedef struct queuen{
    bst data;
    int size;
    int rear,front;
}queuen;

void create(bst p,int data);
void init1(queuen* p,int size1);
void enqueue(queuen* p,node n);
node dequeue(queuen* p);
int isEmptyq(queuen p);
int isFullq(queuen p);



#endif // QUEUEN_H_INCLUDED
