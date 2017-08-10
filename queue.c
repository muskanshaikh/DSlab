#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE],rear=-1,front=-1;

int isFull(){
	//returns 1 if queue is full else returns -1
	return rear==MAX_SIZE-1;
}

int isEmpty(){
	//returns 1 if queue is empty else returns -1
	return front==-1 && rear==-1;
}

int peek(){
	//return element at the top of queue
	return  queue[front];
}
void insertqueue (int d)
{
	if(!isFull())
	{ 
		if(isEmpty())
		front++;
	rear++;
	queue[rear]=d;
	printf("your element is %d is successfully inserted",d);
}
	else
	{
		printf("Queue is full element cannot be inserted");
	}
}

void deletequeue()
{
	int d;
	if(!isEmpty())
	{
	 d=queue[front];
	if(front==rear)
	{
	front=rear=-1;
}
}
    else
    {
	front++;
}
	printf("element deleted is %d",d);
}
	
	
	

int main(){
	int choice,e;
	do
	{
		printf("\t\t\t \nMENU \n 1.peek \n 2.insert\n 3.delete \n 4.exit \n");
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice){
		case 1:
		      if(isEmpty())
		      printf("queue is empty");
		      else
		     e=peek();//all peek function
		     printf("\nelement at the top of queue %d",e);
		     break;
		case 2:printf("enter the element to be inserted");
			scanf("%d",&e);
			insertqueue(e);
		
		     //call push function
		     break;
		case 3:
	         deletequeue();
		     //call pop function
		     break;
		case 4:
			exit(0);
		     //call exit(0) function
		     break;
	default: printf("invalid choice");  
		     break; 
		 }  
	}while(1);
	return 0;
}



