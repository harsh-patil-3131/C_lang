#include<stdio.h>
#include<stdlib.h>
typedef struct heap{
	int *h;
	int size, rear;
}heap;

void init(heap *h, int size){
	h->h=(int *)malloc(size * sizeof(int));
	h->size=size;
	h->rear=-1;
}
void swap(heap *h, int a, int b){
	int temp;
	temp=h->h[a];
	h->h[a]=h->h[b];
	h->h[b]=temp;
}
int parent(int i){
	return (i - 1)/2;
}
void insert(heap *h, int k){
	if(h->rear==h->size-1){
		return;
	}
	h->h[++h->rear]=k;
	int i=h->rear;
	while(i>0 && h->h[i]>h->h[parent(i)]){
		swap(h, i, parent(i));
		i=parent(i);
	}
}
void display(heap h){
	int i=0;
	while(i<h.rear+1){
		printf("%d ", h.h[i]);
		i++;
	}
	printf("\n");
}
void heapify(heap *h, int ind){
	int largest=ind;
	int left=2*ind+1;
	int right=2*ind+2;
	if(left<=h->rear && h->h[left]>h->h[largest]){
		largest=left;
	}
	if(right<=h->rear && h->h[right]>h->h[largest]){
		largest=right;
	}
	if(ind!=largest){
		swap(h, ind, largest);
		heapify(h, largest);
	}
}

int Remove(heap *h){
	if(h->rear<0){
		printf("Heap is empty\n");
		return -1;
	}
	int rm=h->h[0];
	h->h[0]=h->h[h->rear];
	h->rear--;
	heapify(h, 0);
	return rm;
}
void heapsort(int arr[], int len){
	heap h;
	init(&h, len);
	int i=0;
	while(i<len){
		insert(&h, arr[i]);
		i++;
	}
	i=0;
	while(i<len){
		arr[i]=Remove(&h);
		i++;
	}
}
void printarr(int *arr, int len){
	int i=0;
	while(i<len){
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}
int main(){
	heap h;
	init(&h, 5);
	insert(&h, 5);
	insert(&h, 4);
	insert(&h, 1);
	insert(&h, 7);
	insert(&h, 6);
	insert(&h, 9);
	display(h);
	printf("removed element: %d\n", Remove(&h));
	display(h);
	printf("removed element: %d\n", Remove(&h));
	display(h);
	printf("removed element: %d\n", Remove(&h));
	display(h);
	printf("removed element: %d\n", Remove(&h));
	display(h);
	printf("removed element: %d\n", Remove(&h));
	int arr[10]={4, 2, 7, 4, 1, 0, 3, 6, 4};
	heapsort(arr, 9);
	printarr(arr, 9);
	return 0;
}

