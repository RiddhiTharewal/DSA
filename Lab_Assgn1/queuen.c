#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"queuen.h"
#include"bst.h"
void create(bst p,int data){
    p->key=data;
    p->left=NULL;
    p->right=NULL;
    return;
}
void init1(queuen* p,int size1){
    p->data=(node*)malloc(sizeof(node)*size1);
    p->size=size1;
    p->rear=-1;
    p->front=-1;
}
int isEmptyq(queuen p){
    if(p.rear==p.front)
        return 1;
    return 0;
}
int isFullq(queuen p){
    if(p.rear==p.size+1)
        return 1;
    return 0;

}
void enqueue(queuen* p,node s){
    if(!isFullq(*p)){
        p->rear++;
        (p->data[p->rear])=s;
    }
    return;
}
node dequeue(queuen* p){
    node r;
    r.key=INT_MIN;
    r.left=NULL;
    r.right=NULL;
    if(!isEmptyq(*p)){
        p->front++;
        r=(p->data[p->front]);
    }
    return r;
}

