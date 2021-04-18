#ifndef BSTARRAY_H_INCLUDED
#define BSTARRAY_H_INCLUDED

#define Q 100

typedef struct node1{
    int front,rear;
    int* Qu;
    int size;
}queue;
typedef struct node{
    struct node* left;
    struct node* right;
    int key;
}node;
typedef node* bst;
void initbst(bst* t);
bst createNode(int p);
int searchindex(int* arr,int size,int r);
void generatebst(bst* t,int* arr,int start,int end);
void inOrderbst(bst t);


void init_queue(queue* p,int s);
void enqueue(queue* p,int s);
int dequeue(queue* p);
int isEmptyq(queue p);
int isFullq(queue p);


int tree[Q];
void init_bst();
void insert(int p);
int search(int p);
void preOrder(int root);
void inOrder(int root);
void postOrder(int root);
int isCompletebst(int p,int totalnode);
int count(int p);





#endif // BSTARRAY_H_INCLUDED
