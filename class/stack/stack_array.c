#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
	int top;
	int size;
	int *A;
}stack;
void init(stack *s, int size){
	s->top=-1;
	s->size=size;
	s->A=(int *)malloc(size * sizeof(int));
}
int isempty(stack *s){
	if(s->top==-1){
		return 1;
	}
	return 0;
}
int isfull(stack *s){
	if(s->top==s->size-1){
		return 1;
	}
	return 0;
}
void push(stack *s, int val){
	if(isfull(s)){
		return;
	}
	else{
		s->top++;
		s->A[s->top]=val;
	}
}
int pop(stack *s){
	if(isempty(s)){
		return -1;
	}
	else{
		s->top--;
		return s->A[s->top+1];
	}
}
void traverse(stack s){
	int i=s.top;
	while(i>-1){
		printf("%d ", s.A[i]);
		i--;
	}
	printf("\n");
}
int peek(stack s){
	if(!isempty(&s)){
		return s.A[s.top];
	}
	else{
		return -1;
	}
}
int main(){
	stack s;
	int size, ch, val;
	printf("Give size of stack: ");
	scanf("%d", &size);
	init(&s, size);
	printf("\n\n1 val:push val into stack\n2:pop element from stack\n3:peek top element of stack\n4:traverse the stack\n");
	printf("5:exit\n");
	scanf("%d", &ch);
	
	while(ch!=5){
		switch(ch){
			case 1:
				scanf("%d", &val);
				push(&s, val);
				break;
			case 2:
				printf("popped element->%d\n", pop(&s));
				break;
			case 3:
				printf("peeked element->%d\n", peek(s));
				break;
			case 4:
				traverse(s);
				break;
			default:
				printf("Wrong choice!!\n");
				break;
		}
		printf("***\n");
		scanf("%d", &ch);
	}
	
	return 0;
}
