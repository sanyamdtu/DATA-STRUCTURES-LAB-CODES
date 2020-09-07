#include<iostream>
#include<stdio.h>
using namespace std;
#define size 20

struct queue{
	int a[size];
	int front=0, rear=0;
};
int isfull(struct queue *q){
	if((q->rear+1)%size==q->front){
		return 1;
	}
	return 0;
}
int isempty(struct queue *q){
	if(q->rear==q->front){
		return 1;
	}
	return 0;
}
void insert(struct queue *q,int x){
	if(isfull(q)){
		printf("\nQueue full.");
		return;
	}
	q->a[q->rear]=x;
	q->rear=(q->rear+1)%size;
}
int deleteq(struct queue *q){
	if(isempty(q)){
		printf("\nQueue empty.");
		return -1;
	}
	int x=q->a[q->front];
	q->front=(q->front+1)%size;
	return x;
}
void display(struct queue q){
	if(isempty(&q)){
		printf("\nQueue Empty.");
		return ;
	}
	printf("\nElements of the queue are : ");
	int i=q.front;
	while(i<q.rear){
		printf("%d ",q.a[i]);
		i++;
	}
}
int main(){
	int ch,x;
	struct queue q;
	while(1){
		printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:printf("\nEnter the element you want to insert : ");
			       scanf("%d",&x);
			       insert(&q,x);
			       break;
			case 2:x=deleteq(&q);
			       if(x==-1){
			       	break;
				   }
			       printf("\nElement deleted is : %d",x);
			       break;
			case 3:display(q);
			       break;
			case 4:exit(0);
			       break;
		}
	}
	return 0;
}
