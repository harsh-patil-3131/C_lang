#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
typedef struct node{
	int d;
	struct node *next;
}node;
typedef struct queue{
	node *front, *rear;
}queue;

void init(queue *q){
	q->front=NULL;
	q->rear=NULL;
}
void enqueue(queue *q, int val){
	node *n=(node *)malloc(sizeof(node));
	if(q->rear==NULL){
		q->front=q->rear=n;
		n->d=val;
		n->next=NULL;
		return;
	}
	q->rear->next=n;
	q->rear=n;
	n->d=val;
	n->next=NULL;
}
int dequeue(queue *q){
	node *p;
	int a;
	if(q->front){
		p=q->front;
		q->front=q->front->next;
		a=p->d;
		free(p);
		return a;
	}
	printf("Queue empty\n");
	return -1;
}
void traverse(queue q){
	while(q.front){
		printf("%d ", q.front->d);
		q.front=q.front->next;
	}
	printf("\n");
}
int main(){
	int a;
	int x;
	queue l;
	init(&l);
	printf("1 x: enqueue x in queue\n2: dequeue from queue\n3:exit loop\n");
	do{
		scanf("%d", &a);
		switch(a){
			case 1:
				scanf("%d", &x);
				enqueue(&l, x);
				break;
			case 2:
				x=dequeue(&l);
				if(x!=-1){
					printf("dequeued element:%d\n", x);
				}
				break;
			case 3:
				exit(1);
			default:
				printf("Wrong Input\n");
				break;
		}
	}
	while(a!=3);
	
	return 0;
}

