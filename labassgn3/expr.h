#ifndef EXPR_H_INCLUDED
#define EXPR_H_INCLUDED

//structure of binary expression tree
typedef struct node{
    char data;
    struct node* left;
    struct node* right;
}node;
typedef node* bet;
//structure of stack
typedef struct stack{
    int top;
    int size;
    bet *arr;
}stackn;
//operation to be performed on stack
node* create(char p);
void init_b(bet* t);
void init(stackn* q,int s);
void push(stackn* q,node* p);
int isEmpty(stackn q);
int isFull(stackn q);
node* pop(stackn* q);
node* peek(stackn q);
//operation on binary expression tree
//char* modify(char* expr);
bet makebet(char* arr);
void inOrder(bet t);
void preOrder(bet t);
void postOrder(bet t);
int evaluate(bet t);
int getexpr(char *expr);
int isValidExpr(char *expr);
#endif // EXPR_H_INCLUDED
