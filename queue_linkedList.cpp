#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>

using namespace std;

struct Node{
	int key;
	struct Node* next;
};

struct Queue
{
	struct Node* front;
	struct Node* rear;
};

struct Queue* createQueue()
{	
	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=q->rear=NULL;
	return q;
}

struct Node* createNode(int key)
{
	struct Node* node=(struct Node*)malloc(sizeof(Node));
	node->key=key;
	node->next=NULL;
	return node;
}

void enQueue(struct Queue* q,int key)
{
	struct Node* temp = createNode(key);
	if(q->rear==NULL)
	{
		q->rear=q->front=temp;
		return;
	}
	q->rear->next=temp;
	q->rear=temp;
}

struct Node* deQueue(struct Queue* q)
{
	if(q->front==NULL)
	{
		return 0;
	}
	struct Node* temp=q->front;
	q->front=q->front->next;
	if(q->front==NULL)
	{
		q->rear=NULL;
	}	
	return temp;
}

int main()
{
	struct Queue* q1=createQueue();
	enQueue(q1,10);
	enQueue(q1,23);
	enQueue(q1,9);
	enQueue(q1,32);
	struct Node* temp=deQueue(q1);
	cout<<"ITEM DEQUEUED IS::"<<temp->key<<endl;
	temp=deQueue(q1);
	cout<<"ITEM DEQUEUED NOW IS::"<<temp->key<<endl;
	return 0;
}

