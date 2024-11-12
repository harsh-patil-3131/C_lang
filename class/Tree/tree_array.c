#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct bst{
	int *A;
	int size;
}bst;
void init(bst *t, int size){
	t->size=size;
	t->A=(int *)malloc(size * (sizeof(int)));
	int i=0;
	while(i<size){
		t->A[i]=INT_MIN;
		i++;
	}
}
void insert(bst *t, int val){
	int i=0;
	if(t->A[i]==INT_MIN){
		t->A[i]=val;
		return;
	}
	while(i<t->size && t->A[i]!=INT_MIN){
		if(t->A[i]>val){
			i=2 * i + 1;
		}
		else if(t->A[i]<val){
			i = 2 * i + 2;
		}
		else{
			return;
		}
	}
	if(i<t->size){
		t->A[i]=val;
	}
}

void printarr(bst t){
	int i=0;
	while(i<t.size){
		if(t.A[i]==INT_MIN){
			printf("- ");
		}
		else{
			printf("%d ", t.A[i]);
		}
		i++;
	}
}
void inorder(bst t, int i){
	if(i>=t.size || t.A[i]==INT_MIN){
		return;
	}
	inorder(t, 2*i +1);
	printf("%d ", t.A[i]);
	inorder(t, 2 * i +2);
}

int main(){
	bst t;
	init(&t, 20);
	insert(&t, 8);
	insert(&t, 3);
	insert(&t, 7);
	insert(&t, 1);
	insert(&t, 5);
	printarr(t);
	printf("\n");
	inorder(t, 0);
	return 0;
}

