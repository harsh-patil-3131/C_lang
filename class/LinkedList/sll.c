#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int d;
	struct node *next;
}node;

typedef node* list;

void init_SLL(list*l){
	*l=NULL;
	return;
}

void append(list *l, int val){
	node *nn=malloc(sizeof(node)), *p;
	if(nn){
		nn->d=val;
		nn->next=NULL;
	}
	else{
		return;
	}
	if(*l==NULL){
		*l=nn;
	}
	else{
		p=*l;
		while(p->next){
			p=p->next;
		}
		p->next=nn;
	}
}

int len(list l){
	int len=0;
	node *p;
	p=l;
	while(p){
		p=p->next;
		len++;
	}
	return len;
}

void traverse(list l){
	node *p;
	p=l;
	while(p){
		printf("%d ", p->d);
		p=p->next;
	}
	printf("\n");
}

void insert_at_beg(list *l, int val){
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
	}
	else{
		nn->next=*l;
		*l=nn;
	}
}

void remove_at_pos(list *l, int index){
	if(index<0){
		return;
	}
	node *p=*l, *q;
	int i=0;
	if(index==0){
		*l=p->next;
		free(p);
		return;
	}
	while(i<index-1){
		p=p->next;
		i++;
	}
	q=p->next;
	p->next=q->next;
	free(q);
}

void ins_in_sorted(list *l, int val){
	node *nn=malloc(sizeof(node)), *p=*l, *q;
	nn->d=val;
	nn->next=NULL;
	if(p->d>=val){
		nn->next=p;
		*l=nn;
	}
	while(p->next && (p->next->d<val)){
		p=p->next;
	}
	if(p->next){
		q=p->next;
		p->next=nn;
		nn->next=q;
	}
	else{
		p->next=nn;
	}
}
void sort(list *l){
	node *p, *q;
	p=*l;
	int temp;
	while(p){
		q=p->next;
		while(q){
			if(q->d<p->d){
				temp=q->d;
				q->d=p->d;
				p->d=temp;
			}
			q=q->next;
		}
		p=p->next;
	}
}

int main(){
	list l;
	init_SLL(&l);
	append(&l, 7);
	append(&l, 3);
	append(&l, 9);
	append(&l, 1);
	append(&l, 2);
	append(&l, 5);
	traverse(l);
	sort(&l);
	traverse(l);
	return 0;
}
