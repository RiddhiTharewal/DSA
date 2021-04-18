/*Name:Riddhi Tharewal
mis: 111903068*/
#include<stdio.h>
#include<stdlib.h>
#include"expr.h"

int main(){
    char expr[100];//array of expression
    printf("\nEnter the Expression");
    getexpr(expr);//function taking input expression and return size
    bet n;
    init_b(&n);//initialize of binary expression tree
    n = makebet(expr);//create binary expression tree
    while(n == NULL){
        printf("\nEntered Expression is not valid");
        printf("\nEnter valid Expression");
        getexpr(expr);
        n=makebet(expr);
    }
    printf("\n Infix Expression : ");
    inOrder(n);//Inorder Traversal
    printf("\n PreFix Expression : ");
    preOrder(n);
    printf("\n Postfix Expression : ");
    postOrder(n);
    int p = evaluate(n);//Evalaute the tree
    printf("\nAnswer : %d",p);

    return 0;
}
