//Name-Riddhi Ganesh Tharewal
//mis-111903068
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"cstack.h"
#include <limits.h>

#define OPERAND	100
#define OPERATOR 200
#define END	300
#define ERR 400

typedef struct token{
	int type;
	Num num;
	char op;
}token;
enum state { NUMBER, DOT, OP, FINISH, ERROR, SPC };
token gettoken(char *expr, int *reset) {
	static int i = 0;
	Num a = (Num)malloc(sizeof(number));
	initNumber(a);
	char currchar;
	static enum state currstate = SPC;
	enum state nextstate;
	token t;
	if(*reset == 1) {
		currstate = SPC;
		*reset = 0;
		i = 0;
	}
	while(1) {
		currchar = expr[i];
		switch(currstate) {
			case NUMBER:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						nextstate = NUMBER;
						append(a, currchar);
						i++;
						break;
					case '+': case '-': case '*': case '/': case '(' : case ')' :
						nextstate = OP;
						t.type = OPERAND;
						t.num = a;
						currstate = nextstate;
						i++;
						return t;
						break;
					case '\0':
						nextstate = FINISH;
						t.type = OPERAND;
						t.num = a;
						currstate = nextstate;
						return t;
						break;
					case ' ':
						nextstate = SPC;
						t.type = OPERAND;
						t.num = a;
						currstate = nextstate;
						i++;
						return t;
						break;

					case '.':
						nextstate = DOT;
						i++;
						currstate = nextstate;
						break;

					default:
						nextstate = ERROR;
						t.type = OPERAND;
						t.num = a;
						currstate = nextstate;
						return t;
						break;
				}
				break;

			case DOT:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						append(a, currchar);
						a->dec++;
						nextstate = DOT;
						currstate = nextstate;
						i++;
						break;
					case '+': case '-': case '*': case '/': case '(' : case ')' :
						nextstate = OP;
						t.type = OPERAND;
						t.num = a;
						currstate = nextstate;
						i++;
						return t;
						break;
					case '\0':
						nextstate = FINISH;
						t.type = OPERAND;
						t.num = a;
						currstate = nextstate;
						return t;
						break;
					case ' ':
						nextstate = SPC;
						t.type = OPERAND;
						t.num = a;
						currstate = nextstate;
						i++;
						return t;
						break;

					case '.':
						nextstate = DOT;
						i++;
						currstate = nextstate;
						break;

					default:
						nextstate = ERROR;
						t.type = OPERAND;
						t.num = a;
						currstate = nextstate;
						return t;
						break;
				}
				break;

			case OP:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						t.type = OPERATOR;
						t.op = expr[i - 1];
						nextstate = NUMBER;
						currstate = nextstate;
						return t;
						break;
					case '+': case '-': case '*': case '/': case '(' : case ')':
                        nextstate = OP;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						i++;
						return t;
						break;
					case '\0':
						nextstate = FINISH;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						return t;
						break;
					case ' ':
						nextstate = SPC;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						i++;
						return t;
						break;

					case '.':
						nextstate = DOT;
						t.type = OPERATOR;
						t.op = expr[i -1];
						currstate = nextstate;
						i++;
						return t;
						break;

					default:
						nextstate = ERROR;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						return t;
						break;
				}
				break;
			case FINISH:
				t.type = END;
				return t;
				break;
			case ERROR:
				t.type = ERR;
				return t;
				break;
			case SPC:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						append(a, currchar);
						nextstate = NUMBER;
						i++;
						break;
					case '+': case '-': case '*': case '/': case '(' : case ')':
						nextstate = OP;
						i++;
						break;
					case '\0':
						nextstate = FINISH;
						break;
					case ' ':
						nextstate = SPC;
						i++;
						break;

					case '.':
						nextstate = DOT;
						i++;
						break;

					default:
						nextstate = ERROR;
						break;
				}
				currstate = nextstate;
				break;
		}
	}
}
char ctop(cstack *s) {
	char ch;
	ch = cpop(s);
	cpush(s, ch);
	return ch;
}
int precedance(char o) {
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
Num infix(char *exp) {
	token t;
	char curr_op, prev_op, ch;
	int ob = 0, cb = 0, reset  = 1, curr, prev;
	Num a, b, c;
	a = (Num)malloc(sizeof(number));
	b = (Num)malloc(sizeof(number));
	c = (Num)malloc(sizeof(number));
	initNumber(a);
	initNumber(b);
	initNumber(c);
	istack is;
	cstack cs;
	iinit(&is);
	cinit(&cs);
	prev = ERR;
	while(1) {
		t = gettoken(exp, &reset);
		curr = t.type;
		if(curr == prev && prev == OPERAND) {
			return NULL;
		}
		if(t.type == OPERAND){
			ipush(&is, t.num);

		}
		else if(t.type == OPERATOR){
			curr_op = t.op;
			if(curr_op == '(')
				ob++;
			if(curr_op == ')')
				cb++;
			if(cb > ob)
				return NULL;
			if(!cisempty(&cs)) {
				prev_op = ctop(&cs);

				while(precedance(prev_op) >= precedance(curr_op)) {
					prev_op = cpop(&cs);
					if(!iisempty(&is)) {
						a = ipop(&is);
					}
					else{
						cpush(&cs, prev_op);
						break;
					}
					if(!iisempty(&is)) {
						b = ipop(&is);
					}
					else {
						cpush(&cs, prev_op);
						ipush(&is, a);
						break;
					}
					if((prev_op == '/' ) && a == 0) {
                            printf("Mathematical error\n");
                            return NULL;
                    }
					switch (prev_op) {
						case '+' :
							c = add(a, b);
							ipush(&is, c);
							break;
						case '-' :
							c = sub(b, a);
							ipush(&is, c);
							break;
						case '*' :
							c = mult(b, a);
							ipush(&is, c);
							break;
						case '/' :
							c = division(b, a);
							ipush(&is, c);
							break;
                        case '(' :
							cpush(&cs, prev_op);
							ipush(&is, b);
							ipush(&is, a);
							break;
						default :
							return NULL;
					}
					if (prev_op == '(')
						break;
					if(!cisempty(&cs))
						prev_op = ctop(&cs);
					else
						break;
				}
			}
			cpush(&cs, t.op);
			if(curr_op == ')') {
				ch = cpop(&cs);
				cb--;
				ch = cpop(&cs);
				ob--;
			}
		}
		else if(t.type == END) {
			if(ob == cb) {
				while(!cisempty(&cs)) {
					if(!iisempty(&is)) {
						a = ipop(&is);
					}
					else {
						printf("Less operands\n");
                        return NULL;
					}
					if(!iisempty(&is)) {
						b = ipop(&is);
					}
					else {
						printf("Less operands\n");
                        return NULL;
					}
					ch = cpop(&cs);
					if((ch == '/' ) && a == 0) {
						printf("Mathematical error\n");

						return NULL;
					}
					switch(ch) {
						case '+' :
							c = add(b, a);
							ipush(&is, c);
							break;
						case '-' :
							c = sub(b, a);
							ipush(&is, c);
							break;
						case '*' :
							c = mult(b, a);
							ipush(&is, c);
							break;
						case '/' :
							c = division(b, a);
							ipush(&is, c);
							break;

						default :

							return NULL;
					}
				}
			}

			else {
				printf( "Error in Expression\n");

				return NULL;
			}
			if(!iisempty(&is)){
				c = ipop(&is);
				if(iisempty(&is))
					return c;
				else {
                     printf("Less Operators\n");
                     return NULL;
                }
			}
			else {
				printf("Less Operands\n");
				return NULL;
			}
		}
		else if(t.type == ERR) {
			return NULL;
		}
		prev = curr;
	}
}


void modify(char *line) {
	int i;
	for(i = 0; i < strlen(line); i++) {
		if(line[i] == '(') {
			int j = 1;
			while(1) {
				if(line[i + j] == ' ') {
					j++;
				}
				else {
					break;
				}
			}
			if((line[i + j] == '-') || (line[i + j] == '+')) {
				int temp = strlen(line);
				while(temp >= i + j) {
					line[temp + 1] = line[temp];
					temp--;
				}
				line[i + j] = '0';
			}
		}
	}
}
int readline(char *line, int len) {
	int i;
	char ch;
	i = 0;
	while(i < len - 1) {
		ch = getchar();
		if(ch == '\n') {
			line[i++] = '\0';
			return i - 1;
		}
		else
			line[i++] = ch;
	}
	line[len - 1] = '\0';
	return len - 1;
}
int main(int argc, char *argv[]) {
    printf("Enter the Expression\n");
	Num r;
	char line[2048];
	while(readline(line, 2048)) {
		modify(line);
		r = infix(line);
		if(r != NULL){
            printf("answer=");
			print(*r);
		}
		else
			printf("Error in expression\n");
	}
	return 0;
}
