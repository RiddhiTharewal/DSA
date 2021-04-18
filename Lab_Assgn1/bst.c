#include<stdlib.h>
#include"bst.h"
#include<stdio.h>
#include"queuen.h"
void initBST(bst *t){
    *t=NULL;
    return;
}
node* createNode(int data,char* s){
    bst p=(node*)malloc(sizeof(node));
    if(p){
        p->key=data;
        p->left=NULL;
        p->right=NULL;
        p->Name=s;
        p->parent=NULL;
    }
    return p;
}
void insertNode(bst *t,int data,char* s){
    bst p=createNode(data,s);
    bst q=*t;
    if(*t==NULL){
        p->parent=*t;
        *t=p;
        return;
    }
    if(data==q->key){
        free(p);
        return;
    }
    if(q->key > data){
        insertNode(&q->left,data,s);
        q->left->parent=q;
    }
    else if(q->key<data){
        insertNode(&q->right,data,s);
        q->right->parent=q;
    }
    return;
}

int search(bst t,int data){
    if(!t){
        return 0;
    }
    bst q;
    q=t;
    if(data==q->key){
        return 1;
    }
    else if(data < q->key){
         return search(q->left,data);
    }
    else{
        return search(q->right,data);
    }
    return 0;
}
void removeNode(bst* t,int data){
    if(*t==NULL){
        return;
    }
    bst q=*t,p;
    if(q->key>data){
        removeNode(&q->left,data);
    }
    else if(q->key<data){
        removeNode(&q->right,data);
    }
    else{
        if(!q->left){
            p=q->right;
            free(q);
            return;
        }
        else if(!q->right){
            p=q->left;
            free(q);
            return;
        }
        else{
            p=q->right;
            while(p){
                p=p->left;
            }
            q->key=p->key;
            removeNode(&q->right,p->key);
        }
    }
   return;
}
void postOrder(bst t){
    if(t==NULL){
        return;
    }
    postOrder(t->left);
    postOrder(t->right);
    printf("mis:%d\t",t->key);
    printf("Name:%s\t",t->Name);
    if(t->parent)
        printf("parent%d\n",t->parent->key);
    printf("\n");
    return;
}
void Display_Level(bst t){
    queuen q;
    node p;
    bst l;
    init1(&q,10);
    if(t==NULL){
        return;
    }
    printf("mis:%d\tName%s\n",t->key,t->Name);
    enqueue(&q,*t);
    while(!isEmptyq(q)){
        p=dequeue(&q);
        l=&p;
        if(l->left){
            printf("mis:%d\tName:%s\n",l->left->key,l->left->Name);
            enqueue(&q,*l->left);
        }
        if(l->right){
            printf("mis:%d\tName:%s\n",l->right->key,l->right->Name);
            enqueue(&q,*l->right);
        }
    }
    return;
}
void Destroy(bst* t){
    if(*t==NULL){
        return;
    }
    bst q=*t;
    Destroy(&q->left);
    Destroy(&q->right);
    free(q);
    q=NULL;

    return;
}
