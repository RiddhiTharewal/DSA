#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct node{
    int height;
    int data;
    struct node* left;
    struct node* right;
}node;
typedef node* Avl;

void init_avl(Avl* t);

Avl insert_Avl(Avl t,int a);
Avl left_rotate(Avl t);
Avl right_rotate(Avl t);
int height(Avl t);
int maxint(int a,int b);
void inOrder(Avl t);
Avl remove_node(Avl t,int a);
Avl Destroy(Avl t);
//Avl RR(Avl t)

#endif // AVL_H_INCLUDED
