#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int d;
	struct node *prev, *next;
}node;
typedef struct dll{
	node *front, *rear;
}dll;
void init(dll *l){
	l->front=NULL;
	l->rear=NULL;
}
void insert_beg(dll *l, int val){
	node *nn=malloc(sizeof(node));
	if(nn){
		nn->d=val;
		nn->prev=NULL;
	}
	else{
		return;
	}
	if(l->front){
		nn->next=l->front;
		l->front->prev=nn;
		l->front=nn;
	}
	else{
		l->front=nn;
		l->rear=nn;
	}
}
void insert_end(dll *l, int val){
	node *nn=malloc(sizeof(node));
	if(nn){
		nn->d=val;
		nn->next=NULL;
	}
	else{
		return;
	}
	if(l->rear){
		l->rear->next=nn;
		nn->prev=l->rear;
		l->rear=nn;
	}
	else{
		l->front=nn;
		l->rear=nn;
	}
}
void displayLR(dll l){
	while(l.front){
		printf("%d ", l.front->d);
		l.front=l.front->next;
	}
	printf("\n");
}
void insert_pos(dll *l, int pos, int val){
	int i=0;
	node *nn=malloc(sizeof(node));
	nn->d=val;
	node *ptr=l->front;
	if(pos==0){
		nn->next=ptr;
		nn->prev=NULL;
		ptr->prev=nn;
		l->front=nn;
		return;
	}
	while(i<pos && ptr){
		ptr=ptr->next;
		i++;
	}
	if(i==pos && ptr==NULL){
		l->rear->next=nn;
		nn->prev=l->rear;
		l->rear=nn;
		nn->next=NULL;
		return;
	}
	nn->next=ptr;
	nn->prev=ptr->prev;
	ptr->prev=nn;
	nn->prev->next=nn;
}
void displayRL(dll l){
	while(l.rear){
		printf("%d ", l.rear->d);
		l.rear=l.rear->prev;
	}
	printf("\n");
}
int is_palindrome(dll l){
	while(l.front!=l.rear && l.front->next!=l.rear){
		if(l.front->d!=l.rear->d){
			return 0;
		}
		l.front=l.front->next;
		l.rear=l.rear->prev;
	}
	return 1;
}
void remove_beg(dll *l){
	if(l->front){
		node *ptr=l->front;
		l->front=l->front->next;
		free(ptr);
		l->front->prev=NULL;
	}
	else{
		return;
	}
}
void remove_end(dll *l){
	if(l->rear){
		node *ptr=l->rear;
		l->rear=l->rear->prev;
		free(ptr);
		l->rear->next=NULL;
	}
	else{
		return;
	}
}
void remove_pos(dll *l, int pos){
	int i=0;
	node *ptr=l->front;
	if(pos==0){
		l->front=l->front->next;
		free(ptr);
		l->front->prev=NULL;
		return;
	}
	while(i<pos && ptr){
		ptr=ptr->next;
		i++;
	}
	if(ptr->next==NULL){
		ptr->prev->next=NULL;
		l->rear=ptr->prev;
		free(ptr);
		return;
	}
	ptr->prev->next=ptr->next;
	ptr->next->prev=ptr->prev;
	free(ptr);
}
int main(){
	dll l;
	init(&l);
	insert_beg(&l, 1);
	insert_end(&l, 3);
	displayLR(l);
	insert_pos(&l, 1, 2);
	displayLR(l);
	insert_pos(&l, 3, 4);
	displayLR(l);
	insert_pos(&l, 0, 0);
	displayLR(l);
	if(is_palindrome(l)){
		printf("palindrome\n");	
	}
	else{
		printf("not palindrome\n");
	}
	insert_end(&l, 3);
	insert_end(&l, 2);
	insert_end(&l, 1);
	insert_end(&l, 0);
	displayLR(l);
	if(is_palindrome(l)){
		printf("palindrome\n");	
	}
	else{
		printf("not palindrome\n");
	}
	remove_beg(&l);
	displayLR(l);
	remove_end(&l);
	displayLR(l);
	remove_pos(&l, 2);
	displayLR(l);
	remove_pos(&l, 3);
	displayLR(l);
	remove_pos(&l, 2);
	displayLR(l);
	return 0;
}
