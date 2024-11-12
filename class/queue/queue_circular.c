#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
	int *A;
	int size;
	int front, rear;
}queue;
void init(queue *q, int size){
	q->size=size;
	q->A=(int *)malloc(size * sizeof(int));
	q->front=q->rear=-1;
}
void enqueue(queue *q, int val){
	if(((q->rear+1)%q->size) == q->front){
		return;
	}
	if(q->rear==-1){
		q->rear=q->front=0;
		q->A[0]=val;
		return;
	}
	q->rear=(q->rear+1)%q->size;
	q->A[q->rear]=val;
}
int dequeue(queue *q){
	if(q->front==-1){
		return -1;
	}
	int d;
	if(q->front==q->rear){
		d=q->A[q->front];
		q->front=q->rear=-1;
		return d;
	}
	d=q->A[q->front];
	q->front=(q->front+1)%q->size;
	return d;
}
void printqueue(queue *q){
	int i=q->front;
	if(q->front==-1){
		return;
	}
	while(i!=q->rear){
		printf("%d ", q->A[i]);
		i=(i+1)%q->size;
	}
	printf("%d\n", q->A[i]);
}
int main(){
	queue q;
	init(&q, 5);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	enqueue(&q, 6);
	printqueue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	printqueue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	printqueue(&q);
	return 0;
}

