#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int d;
	struct node *next;
}node;
typedef struct stack{
	node *top;
}stack;
void init(stack *s){
	s->top=NULL;
}
void push(stack *s, int val){
	node *nn=(node *)malloc(sizeof(node));
	if(nn){
		nn->d=val;
		nn->next=NULL;
	}
	else{
		return;
	}
	if(s->top){
		nn->next=s->top;
		s->top=nn;
	}
	else{
		s->top=nn;
		return;
	}
}
void pop(stack *s){
	node *p=s->top;
	if(s->top){
		s->top=s->top->next;
		free(p);
	}
}
int peek(stack s){
	if(s.top){
		return s.top->d;
	}
	return -1;
}
void print(stack s){
	printf("[ ");
	while(s.top){
		printf("%d ", s.top->d);
		s.top=s.top->next;
	}
	printf("]\n");
}
int main(){
	stack s;
	init(&s);
	push(&s, 1);
	push(&s, 3);
	push(&s, 5);
	push(&s, 9);
	pop(&s);
	printf("peeked: %d\n", peek(s));
	print(s);
	return 0;
}
