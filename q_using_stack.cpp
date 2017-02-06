#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>

using namespace std;
struct stack
{
	int capacity,size,TOP;
	int *array;
};

struct queue
{
	struct stack *s1,*s2;
};

struct stack* createstack(int cap)
{
	struct stack *new1=(struct stack*)malloc(sizeof(struct stack));
	new1->capacity=cap;
	new1->size=0;
	new1->TOP=0;
	new1->array=(int*)malloc(cap*sizeof(int));
	return new1;
}

void push(struct stack *x,int n)
{
	if(x->size>=x->capacity)
	{
		printf("full");
		return;
	}
	x->array[x->TOP]=n;
	x->TOP++;
	x->size++;
}

int pop(struct stack *x)
{
	if(x->size<=0)
	{
		printf("empty");
		return 0;
	}
	x->TOP--;
	x->size--;
	return x->array[x->TOP];
}

void enque(struct queue *Q,int n)
{
	push(Q->s1,n);
}

int deque(struct queue *Q)
{
	if(Q->s2->size>0)
	{
		return pop(Q->s2);

	}
	while(Q->s1->size!=0)
	{
		int faltu=pop(Q->s1);
		push(Q->s2,faltu);
	}
	return pop(Q->s2);
}

int main()
{
	struct stack *x=createstack(100);
	struct stack *y=createstack(100);
	struct queue *Q=(struct queue*)malloc(sizeof(struct queue));
	Q->s1=x;
	Q->s2=y;
	enque(Q,2);
	enque(Q,3);
	printf("%d\n",deque(Q));
	printf("%d\n",deque(Q));
	printf("%d\n",deque(Q));
	return 0;
}
