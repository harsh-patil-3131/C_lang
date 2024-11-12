#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int d;
	struct node*next;
}node;

typedef node* list;

void init_CLL(list *l){
	*l=NULL;
	return;
}
void insert_beg(list *l, int val){
	node *nn=malloc(sizeof(node));
	if(nn){
		nn->d=val;
		nn->next=NULL;
	}
	else{
		return;
	}
	if(*l==NULL){
		*l=nn;
		nn->next=nn;
		return;
	}
	node *p=*l;
	while(p->next!=*l){
		p=p->next;
	}
	p->next=nn;
	nn->next=*l;
	*l=nn;
}
void insert_end(list *l, int val){
	node *nn=malloc(sizeof(node)), *p=*l;
	if(nn){
		nn->d=val;
		nn->next=NULL;
	}
	else{
		return;
	}
	if(*l==NULL){
		*l=nn;
		nn->next=nn;
		return;
	}
	while(p->next!=*l){
		p=p->next;
	}
	p->next=nn;
	nn->next=*l;
}
void insert_at_pos(list *l, int pos, int val){
	int i=0;
	if(pos==0){
		insert_beg(l, val);
		return;
	}
	node *nn=malloc(sizeof(node));
	if(nn){
		nn->d=val;
		nn->next=NULL;
	}
	else{
		return;
	}
	node *p=*l;
	while(i<pos-1){
		i++;
		p=p->next;
	}
	nn->next=p->next;
	p->next=nn;
}

void remove_beg(list *l){
	if(*l==NULL){
		return;
	}
	node *p=*l, *q;
	while(p->next!=*l){
		p=p->next;
	}
	q=*l;
	p->next=q->next;
	*l=q->next;
	free(q);
}
void remove_end(list *l){
	if(*l==NULL || (*l)->next==(*l)){
		*l=NULL;
		return;
	}
	node *p=*l, *q;
	while(p->next!=*l){
		q=p;
		p=p->next;
	}
	p=q->next;
	q->next=*l;
	free(p);
}
void remove_pos(list *l, int pos){
	int i=0;
	node *p=*l, *q;
	if(pos==0){
		remove_beg(l);
		return;
	}
	while(i<pos-1){
		i++;
		p=p->next;
	}
	q=p->next;
	p->next=q->next;
	free(q);
}
void display(list l){
	node *p=l;
	while(p->next!=l){
		printf("%d ", p->d);
		p=p->next;
	}
	printf("%d\n", p->d);
}

int main(){
	list l;
	init_CLL(&l);
	insert_beg(&l, 1);
	insert_end(&l, 3);	
	insert_end(&l, 2);
	insert_end(&l, 7);
	insert_at_pos(&l, 1, 2);
	insert_at_pos(&l, 0, -1);
	display(l);
	remove_end(&l);
	display(l);
	remove_beg(&l);
	display(l);
	remove_pos(&l, 1);
	display(l);
	return 0;
}

