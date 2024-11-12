#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int *queue;
	int front, rear;
	int size;
}queue;

void init(queue *q, int size){
	q->size=size;
	q->front=0;
	q->rear=-1;
	q->queue=(int *)malloc(size * sizeof(int));
}
void enqueue(queue *q, int val){
	if(q->rear==q->size-1){
		return;
	}
	q->queue[++q->rear]=val;
}
int dequeue(queue *q){
	if(q->rear<q->front){
		return -1;
	}
	int val=q->queue[0];
	for(int i=0; i<q->rear; i++){
		q->queue[i]=q->queue[i+1];
	}
	q->rear--;
	return val;
}
void printQueue(queue q){
	for(int i=0; i<=q.rear; i++){
		printf("%d ", q.queue[i]);
	}
	printf("\n");
}

int main(){
	queue l;
	int size, a, x;
	printf("Give size of array: ");
	scanf("%d", &size);
	init(&l, size);
	printf("1 x: enqueue x in queue\n2:dequeue from queue\n3:Print Queue\n4:exit loop\n");
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
				else{
					printf("No elements in queue\n");
				}
				break;
			case 3:
				printQueue(l);
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong Input\n");
				break;
		}
	}
	while(a!=4);
	
	
	/*enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printQueue(q);
	dequeue(&q);
	printQueue(q);
	enqueue(&q, 4);
	enqueue(&q, 5);
	enqueue(&q, 6);
	enqueue(&q, 7);
	enqueue(&q, 8);
	enqueue(&q, 9);
	printQueue(q);
	*/
	return 0;
}
