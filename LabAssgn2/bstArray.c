
#include<stdio.h>
#include<stdlib.h>
#include"bstArray.h"
#include<limits.h>
void initbst(bst* t){
    *t=NULL;
    return;
}
bst createNode(int p){
    bst q=(node*)malloc(sizeof(node));
    q->key=p;
    q->left=NULL;
    q->right=NULL;
    return q;
}
int searchindex(int* arr,int size,int r){
    for(int i=size;i>=0;i--){
        if(arr[i]<r)
            return i;
    }
    return -1;
}
void generatebst(bst *t,int* arr,int start,int end){
    if(start>end){
        return;
    }
    bst p=NULL;
    p=createNode(arr[end]);
    int split=searchindex(arr,end-1,arr[end]);
    if(*t==NULL){
        *t=p;
    }
    bst q=*t;
    generatebst(&q->left,arr,start,split);
    generatebst(&q->right,arr,split+1,end-1);
    return;
}
void inOrderbst(bst t){
    if(t==NULL)
       return;
    inOrderbst(t->left);
    printf("%d ",t->key);
    inOrderbst(t->right);
}
void init_queue(queue* p,int s){
    p->front=-1;
    p->rear=-1;
    p->size=s;
    p->Qu=(int*)malloc(sizeof(int)*s);
}

void enqueue(queue* p,int s){
    if(!isFullq(*p)){
        p->Qu[p->rear++]=s;
        return;
    }

}
int dequeue(queue* p){
    int e=INT_MIN;
    if(!isEmptyq(*p)){
        e=p->Qu[p->front];
        p->front--;
    }
    return e;
}

int isFullq(queue p){
    if(p.rear+1==p.size){
        return 1;
    }
    return 0;
}
int isEmptyq(queue p){
    if(p.rear==p.front)
        return 1;
    return 0;

}
void init_bst(){
    for(int i=0;i<Q;i++){
        tree[i]=INT_MIN;
    }
    return;
}

void insert(int p){
    int i=0;
    if(tree[0]==INT_MIN)
        tree[0]=p;
    while(tree[i]!=INT_MIN){
        if(p>tree[i]){
            i=2*i+2;
            if(i>=Q){
                printf("No SPace to insert");
                return;
            }
        }
        else if(p<tree[i]){
            i=2*i+1;
            if(i>=Q){
                printf("No SPace to insert");
                return;
            }
        }
        else
            return;
    }
    tree[i]=p;
    return;
}
int search(int p){
    int i=0;
    if(tree[0]==INT_MIN)
        return 0;
    while(tree[i]!=INT_MIN){
        if(p>tree[i]){
            i=2*i+2;
        }
        else if(p<tree[i]){
            i=2*i+1;
        }
        else
            return 1;
    }
    return 0;
}
void preOrder(int root){
    if(tree[root]==INT_MIN){
        return;
    }
    printf("%d ",tree[root]);

    preOrder(2*root+1);
    preOrder(2*root+2);
    return;
}
void inOrder(int root){
    if(tree[root]==INT_MIN){
        return;
    }
    inOrder(2*root+1);
    printf("%d ",tree[root]);
    inOrder(2*root+2);
    return;
}
void postOrder(int root){
    if(tree[root]==INT_MIN){
        return;
    }
    postOrder(2*root+1);
    postOrder(2*root+2);
    printf("%d ",tree[root]);

    return;
}
int count(int p){
    int x,y;
    if(tree[p]==INT_MIN)
        return 0;
    if(tree[p]!=INT_MIN){
        x=count(2*p+1);
        y=count(2*p+2);
    }
    return 1+x+y;
}
int isCompletebst(int p,int totalnode){
    int x,y;
    if(tree[p]==INT_MIN)
        return 1;
    if(p>=totalnode){
        return 0;
    }
    if(tree[p]!=INT_MIN){
        x=isCompletebst(2*p+1,totalnode);
        y=isCompletebst(2*p+2,totalnode);
    }
    return x&&y;

}

