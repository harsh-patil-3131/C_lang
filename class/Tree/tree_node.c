#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int d;
	struct node *left, *right;
}node;
typedef node *BST;

typedef struct queue{
	node **q;
	int front, rear, size;
}queue;

void init_queue(queue*q, int size){
	q->size=size;
	q->q=(node **)malloc(size * sizeof(node*));
	q->front=q->rear=-1;
}
void enq(queue *q, node *p){
	if(p==NULL){
		return;
	}
	if(((q->rear+1)%q->size)==q->front){
		return;
	}
	if(q->rear==-1){
		q->front=q->rear=0;
		q->q[0]=p;
		return;
	}
	q->rear=(q->rear+1)%q->size;
	q->q[q->rear]=p;
}
node *deq(queue *q){
	if(q->front==-1){
		printf("Queue empty\n");
		return NULL;
	}
	node *r;
	if(q->front==q->rear){
		r=q->q[q->front];
		q->front=q->rear=-1;
		return r;
	}
	r=q->q[q->front];
	q->front=(q->front+1)%q->size;
	return r;
}
int isempty(queue q){
	if(q.front==-1){
		return 1;
	}
	return 0;
}
void init(BST *t){
	*t=NULL;
	return;
}

void insert(BST *t, int val){
	node *nn=malloc(sizeof(node));
	nn->d=val;
	nn->left=nn->right=NULL;
	if(*t==NULL){
		*t=nn;
		return;
	}
	node *p=*t, *q;
	while(p){
		q=p;
		if(p->d<val){
			p=p->right;
		}
		else if(p->d>val){
			p=p->left;
		}
		else{
			free(nn);
			return;
		}
	}
	if(p!=NULL){
		printf("node with value %d exist\n", val);
		return;
	}
	if(q->d>val){
		q->left=nn;
	}
	else{
		q->right=nn;
	}
	
}
BST Recursive_insertion(BST *t, int val){
	if(*t==NULL){
		node *nn=malloc(sizeof(node));
		nn->d=val;
		nn->left=nn->right=NULL;
		*t=nn;
		return *t;
	}
	node *p=*t;
	if(p->d<val){
		p->right=Recursive_insertion(&(p->right), val);
	}
	else if(p->d>val){
		p->left=Recursive_insertion(&(p->left), val);
	}
	return p;
}
void removeNode(BST *t, int val){
	node *p, *q;
	p=*t;
	while(p && p->d!=val){
		q=p;
		if(p->d>val){
			p=p->left;
		}
		else{
			p=p->right;
		}
	}
	if(p==NULL){
		printf("element %d is not present\n", val);
		return;
	}
	if(!p->left && !p->right){//case 1: deleting leaf node
		if(p==*t){
			free(p);
			*t=NULL;
			return;
		}
		if(q->left==p){
			q->left=NULL;
		}
		else{
			q->right=NULL;
		}
		free(p);
		return;
	}
	//
	
	if((p->left && !p->right) ||(!p->left && p->right)){
		node *r;
		if(p->left==NULL){
			r=p->right;
		}
		else{
			r=p->left;
		}
		if(p==*t){
			*t=r;
		}
		else{
			if(q->left==p){
				q->left=r;
			}
			else{
				q->right=r;
			}
		}
		free(p);
		return;
	}
	if(p->left && p->right){
		node *sp, *s;
		sp=p;
		s=p->right;
		while(s->left){
			sp=s;
			s=s->left;
		}
		p->d=s->d;
		if(sp->left==s){
			sp->left=s->right;
		}
		else{//this when sp==p, i.e p==sp;
			sp->right=s->right;
		}
		free(s);
	}
}

void inorder(BST *t){
	if(*t){
		inorder(&((*t)->left));
		printf("%d ", (*t)->d);
		inorder(&((*t)->right));
	}
}
void traverse_levelwise(BST *t){
	printf("levelwise: ");
	if(*t==NULL){
		printf("*t==NULL\n");
		return;
	}
	node *p;
	queue q;
	int i;
	init_queue(&q, 100);
	enq(&q, *t);
	while(!isempty(q)){
		p=deq(&q);
		printf("%d ", p->d);
		enq(&q, p->left);
		enq(&q, p->right);
	}
	printf("\n");
}
int main(){
	BST t;
	init(&t);
	
	t=Recursive_insertion(&t, 5);
	t=Recursive_insertion(&t, 1);
	t=Recursive_insertion(&t, 4);
	t=Recursive_insertion(&t, 6);
	t=Recursive_insertion(&t, 2);
	t=Recursive_insertion(&t, 0);
	t=Recursive_insertion(&t, 9);
	t=Recursive_insertion(&t, 7);
	t=Recursive_insertion(&t, 10);
	
	
	printf("inorder: ");
	inorder(&t);
	printf("\n");
	traverse_levelwise(&t);
	/*
	removeNode(&t, 4);
	inorder(&t);
	printf("\n");
	removeNode(&t, 5);
	inorder(&t);
	printf("\n");
	removeNode(&t, 6);
	inorder(&t);
	printf("\n");
	removeNode(&t, 1);
	inorder(&t);
	printf("\n");
	removeNode(&t, 2);
	inorder(&t);
	printf("\n");
	removeNode(&t, 6);
	inorder(&t);
	printf("\n");
	*/
	return 0;
}
