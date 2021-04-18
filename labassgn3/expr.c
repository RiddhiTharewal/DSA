
#include<stdio.h>
#include<stdlib.h>
#include"expr.h"
#include<limits.h>
#include<string.h>
node* create(char l){
    bet n;
    n=(node*)malloc(sizeof(node));
    n->data=l;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void init_b(bet* t){
    *t=NULL;
    return;
}
//initialize stack function
void init(stackn* q1,int s){
    q1->top = -1;
    q1->arr = (bet*)malloc(sizeof(bet)*s);
    q1->size = s;
    return;
}
int isFull(stackn q){
    if(q.top == q.size-1){
        return 1;
    }
    return 0;
}
void push(stackn* q,bet s){
    if(!isFull(*q)){
        q->top++;
        q->arr[q->top]=s;
    }
    return;
}
int isEmpty(stackn q){
    if(q.top == -1)
        return 1;
    return 0;
}
bet pop(stackn* q){
    node* n=NULL;
    if(!isEmpty(*q)){
        n = q->arr[q->top];
        q->top--;
    }
    return n;
}
bet peek(stackn q){
    node* n = NULL;
    if(!isEmpty(q))
        n = q.arr[q.top];
    return n;

}
int isOperator(char i){
    if(i == '+'|| i == '-' ||i == '*'|| i == '/'|| i == '('||i == ')'){
        return 1;
    }
    return 0;
}
int isOperand(char i){
    if(i == '1'||i == '2'||i == '3' || i == '4' ||i == '5' ||i == '6'|| i == '7' || i == '8' ||i == '9' || i == '0')
        return 1;
    return 0;
}
//check precedence
int precedence(char o) {
	switch(o) {
		case ')' :
			return 0;
			break;
		case '+' :
		case '-' :
			return 1;
			break;
		case '*' :
		case '/' :
			return 2;
			break;
		case '(' :
			return 3;
			break;
		default :
			return 4;
			break;
	}
	return 5;
}
//get expression
int getexpr(char *expr){
    int i;
    char c='\0';
    for(i=0; (c=getchar()) != '\n'; i++){
        expr[i] = c;
    }
    expr[i] = '\0';
    return i;
}
//checks if valid
int isValidExpr(char* arr){
    stackn op;
    int ob=0,cb=0;
    int i = 0;
    bet q;
    init_b(&q);
    init(&op,10);
    while(arr[i]){
        if(arr[i] == '('){
           q=create(arr[i]);
           ob+=1;
           push(&op,q);
        }
        else if(arr[i]==')'){
            cb+=1;
            if(isEmpty(op))
                return 0;
            if(peek(op)->data!='(')
                return 0;
            else if(peek(op)->data=='(')
                pop(&op);
        }
        else if(isOperator(arr[i])){
           if(arr[i+1] == ')' || (isOperator(arr[i+1])&&arr[i+1]!='('))
                return 0;
        }
        else if(isOperand(arr[i])){
            if(arr[i+1]=='(')
                return 0;
        }

        i++;

    }
    if(ob!=cb)
        return 0;
    return 1;
}
//create binary expression tree
bet makebet(char arr[]){
    stackn op,ch;
    init(&op,10);//operator stack
    init(&ch,10);//charater stack
    bet q=NULL;
    if(!isValidExpr(arr)){//if expression is not valid return null
        return NULL;
    }
    for(int i=0;i<strlen(arr);i++){
        //if space in between simply increment
        if(arr[i]==' '){}
        //if it number push in character stack
        else if(isOperand(arr[i])){
            q=create(arr[i]);
            push(&ch,q);
        }
        //if open bracket appears simply push in operator stack
        else if(arr[i]=='('){
            q = create(arr[i]);
            push(&op,q);
        }
        //if operator check precedence and accordingly push and pop
        else if(precedence(arr[i])>0){
            while(!isEmpty(op) && peek(op)->data!='(' && precedence(peek(op)->data)>=precedence(arr[i])){
                    q = peek(op);
                    pop(&op);
                    q->right = pop(&ch);
                    q->left = pop(&ch);
                    push(&ch,q);
            }
            q=create(arr[i]);
            push(&op,q);
        }
        //if close bracket appears pop till open bracket is appeared and arrange left and right child and push in character stack
        else if(arr[i] == ')'){
            while(!isEmpty(op) && peek(op)->data != '('){
                    q = peek(op);
                    pop(&op);
                    q->right = pop(&ch);
                    q->left = pop(&ch);
                    push(&ch,q);
            }
            pop(&op);
        }
    }
    //if array is traversed and operator stack is not then make binary expression tree
    if(!isEmpty(op)){
        while(!isEmpty(op)){
            q = peek(op);
            pop(&op);
            q->right = pop(&ch);
            q->left = pop(&ch);
            push(&ch,q);
        }
    }
    q = peek(ch);
    return q;
}
//infix
void inOrder(bet t){
    if(t == NULL)
        return;
    inOrder(t->left);
    if(isOperator(t->data))
        printf("%c ",t->data);
    else{
        printf("%d ",t->data-'0');
    }
    inOrder(t->right);
    return;
}
//prefix
void preOrder(bet t){
    if(t == NULL)
        return;
    if(isOperator(t->data))
        printf("%c ",t->data);
    else{
        printf("%d ",t->data-'0');
    }
    preOrder(t->left);
    preOrder(t->right);
    return;
}
//postfix
void postOrder(bet t){
    if(t == NULL)
        return;
    postOrder(t->left);
    postOrder(t->right);
    if(isOperator(t->data))
        printf("%c ",t->data);
    else{
        printf("%d ",t->data-'0');
    }
    return;
}
int evaluate(bet s){
    int p,q,r;
    char opr;
    bet n,m;
    bet t = s;
    if(t == NULL)
        return 0;
    if(t->left && t->right){
        p = evaluate(t->left);
        q = evaluate(t->right);

    }
    if(!t->left && !t->right){
        return t->data - '0';
    }
    opr = t->data;
    switch(opr){
    case '+':
        r = p + q;
        break;
    case '-':
        r = p - q;
        break;
    case '*':
        r = p * q;
        break;
    case '/':
        r = p / q;
        break;
    }
    n = t->left;
    m = t->right;
    printf("\nResult of intermediate node %d%c%d=", n->data-'0', opr, m->data-'0');
    t->data=r+'0';
    free(m);
    free(n);
    t->left = NULL;
    t->right = NULL;
    inOrder(t);
    return r;
}
