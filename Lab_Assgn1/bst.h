#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef struct node{
    int key;
    struct node *left,*right;
    char *Name;
    struct node* parent;
}node;
typedef node* bst;

void initBST(bst* t);
node* createNode(int data,char* s);
void insertNode(bst* t,int key,char* s);
void removeNode(bst* t,int key);
int search(bst t,int key);
void postOrder(bst t);
void Display_Level(bst t);
void Destroy(bst* t);

#endif // BST_H_INCLUDED
