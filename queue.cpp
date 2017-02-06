#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>

using namespace std;

struct Queue{
	int capacity,size,rear,front;
	int *array;
};

struct Queue* createQueue(int capacity)
{
	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
	q->capacity=capacity;
	q->front=q->size=0;
	q->rear=capacity-1;
	q->array=(int *)malloc(capacity*sizeof(int));
	return q;
}

int isFull(struct Queue* q)
{
	return q->size==q->capacity;
}

int isEmpty(struct Queue* q)
{
	return q->size==0;
}

void enQueue(struct Queue* q,int item)
{
	if(isFull(q))
		return;
	q->rear=(q->rear+1)%q->capacity;
	q->array[q->rear]=item;
	q->size=q->size+1;
}

int deQueue(struct Queue* q)
{
	if(isEmpty(q))
		return 0;
	int item = q->array[q->front];
	q->front=(q->front+1)%q->capacity;
	q->size=q->size-1;
	return item;
}

int front(struct Queue* q)
{
	if(isEmpty(q))
		return 0;
	return q->array[q->front];
}

int rear(struct Queue* q)
{
	if(isEmpty(q))
		return 0;
	return q->array[q->rear];
}

int main()
{
	struct Queue* q1=createQueue(100);
	enQueue(q1,10);
	enQueue(q1,13);
	enQueue(q1,2);
	cout<<"FRONT::"<<front(q1)<<endl;
	cout<<"Rear::"<<rear(q1)<<endl;
	cout<<"DEQUE::"<<deQueue(q1)<<endl;
	cout<<"FRONT::"<<front(q1)<<endl;
	cout<<"Rear::"<<rear(q1)<<endl;	
	return 0;
}
