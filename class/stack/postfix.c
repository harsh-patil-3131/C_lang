#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack{
	char *A;
	int top;
	int size;
}stack;

void init(stack *s, int size){
	s->size=size;
	s->A=(char *)malloc(sizeof(char)*size);
	s->top=-1;
}
void push(stack *s, char ch){
	if(s->top==s->size-1){
		return;
	}
	s->top++;
	s->A[s->top]=ch;
}
char pop(stack *s){
	if(s->top!=-1){
		s->top--;
		return s->A[s->top+1];
	}
	return '@';
}
int val(char ch){
	if(ch=='+' || ch=='-'){
		return 1;
	}
	if(ch=='*' || ch=='/'){
		return 2;
	}
	if(ch=='^'){
		return 3;
	}
}
int precedence(stack *s, char ch){
	if(s->top==-1){
		return 0;
	}
	if(s->A[s->top]=='('){
		return 0;
	}
	else{
		if(val(s->A[s->top])>=val(ch)){
			return 1;
		}
		else{
			return 0;
		}
	}
}
int isoperator(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
		return 1;
	}
	return 0;
}
char peek(stack *s){
	return s->A[s->top];
}
int main(){
	stack s;
	init(&s, 50);
	char q[50], ch;
	printf("Give infix expression: ");
	scanf("%s", q);
	char *p=(char *)malloc(sizeof(char)*strlen(q));
	int i=0, j=0;
	while(q[i]!='\0'){
		ch=q[i];
		if(ch=='('){
			push(&s, ch);
		}
		else if(ch==')'){
			while(peek(&s)!='('){
				p[j++]=pop(&s);
			}
			pop(&s);
		}
		else if(isoperator(ch)){
			if(precedence(&s, ch)){
				while((s.top!=-1) && (peek(&s)!='(')){
					p[j++]=pop(&s);
				}
				push(&s, ch);
			}
			else{
				push(&s, ch);
			}
		}
		else{
			p[j++]=ch;
		}
		i++;
	}
	while(s.top!=-1){
		p[j++]=pop(&s);
	}
	printf("p:%s\n", p);
	return 0;
}
