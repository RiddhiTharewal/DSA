#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include"Avl.h"
void init_avl(Avl* t){
    *t=NULL;
    return;
}
int maxint(int a,int b){
    if(a > b)
        return a;
    return b;
}
int height(Avl t){
    if(t==NULL)
        return 0;
    return t->height;
}
int BalanceF(Avl t){
    if(t == NULL){
        return 0;
    }
    return height(t->left) - height(t->right);
}
Avl insert_Avl(Avl q,int a){
    Avl p=(node*)malloc(sizeof(node));
    if(p){
        p->data = (int*)malloc(sizeof(int));
        p->data = a;
        p->left = NULL;
        p->right = NULL;
        p->height = 1;
    }
   if(q == NULL){
        return p;
    }
    if(a > q->data)
        q->right = insert_Avl(q->right, a);
    else if(a < q->data)
        q->left = insert_Avl(q->left, a);
    else
        return q;
    q->height = maxint(height(q->left),height(q->right)) + 1;
    int bal=BalanceF(q);
    if(bal < -1 && a > q->right->data){
        return left_rotate(q);
    }
    if(bal > 1 && a < q->left->data){
        return right_rotate(q);
    }
    if(bal > 1 && a > q->left->data){
        q->left = left_rotate(q->left);
        return right_rotate(q);
    }
    if(bal < -1 && a < q->right->data){
        q->right = right_rotate(q->right);
        return left_rotate(q);
    }

    return q;
}
Avl left_rotate(Avl p){
    Avl q, r;
    q = p->right;
    r = q->left;
    q->left = p;
    p->right = r;
    p->height = maxint(height(p->left),height(p->right)) + 1;
    q->height = maxint(height(q->left),height(q->right)) + 1;
    return q;
}

Avl right_rotate(Avl p){
    Avl q, r;
    q = p->left;
    r = q->right;
    q ->right = p;
    p->left = r;
    p->height = maxint(height(p->left),height(p->right)) + 1;
    q->height = maxint(height(q->left),height(q->right)) + 1;
    return q;
}
Avl leftright(Avl p){
    p->left = right_rotate(p->left);
    p=left_rotate(p);
    return p;
}
Avl rightleft(Avl p){
    p->right = left_rotate(p->right);
    p = right_rotate(p);
    return p;
}

void inOrder(Avl t){
    if(t == NULL)
        return;
    inOrder(t->left);

    switch(t->data){
        case 0:printf("[January : ");
                break;
        case 1:printf("[February: ");
                break;
        case 2:printf("[March: ");
                break;
        case 3:printf("[April: ");
                break;
        case 4:printf("[May: ");
                break;
        case 5:printf("[June: ");
                break;
        case 6:printf("[July : ");
                break;
        case 7:printf("[August : ");
                break;
        case 8:printf("[September: ");
                break;
        case 9:printf("[October : ");
                break;
        case 10:printf("[November : ");
                break;
        case 11:printf("[December: ");
                break;
        default:
            break;
    }
    printf("%d ]",BalanceF(t));
    inOrder(t->right);

}
Avl remove_node(Avl q,int data){
    Avl t;
    if(q==NULL)
        return q;

    if(data<q->data)
        q->left=remove_node(q->left,data);
    else if(data>q->data)
        q->right = remove_node(q->right,data);
    else{
        if(q->left ==  NULL){
            t = q->right;
            free(q);
            return t;
        }
        else if(!q->right){
            t = q->left;
            free(q);
            return t;
        }
        t=q->right;
        while(t && t->left){
            t=t->left;
        }
        q->data=t->data;
        q->right = remove_node(q->right,t->data);
    }
    q->height = maxint(height(q->left),height(q->right)) + 1;
    int bal=BalanceF(q);
    if(bal < -1 && data > q->right->data){
        return left_rotate(q);
    }
    if(bal > 1 && data < q->left->data){
        return right_rotate(q);
    }
    if(bal > 1 && data > q->left->data){
        q->left = left_rotate(q->left);
        return right_rotate(q);
    }
    if(bal < -1 && data < q->right->data){
        q->right = right_rotate(q->right);
        return left_rotate(q);
    }
    return q;
}
Avl Destroy(Avl t){
    if(t == NULL){
        return t;
    }
    Destroy(t->left);
    Destroy(t->right);
    free(t);
    return NULL;
}
