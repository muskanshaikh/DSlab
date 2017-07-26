#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;
int isFull(){
	//returns 1 if stack is full else returns -1
	return top==MAX_SIZE-1;
}

int isEmpty(){
	//returns 1 if stack is empty else returns -1
	return top==-1;
}

int peek(){
	//return element at the top of stack
	return  stack[top];
}

void push(int e){
	//inserts an element into stack
	if(!isFull)
	{
		top++;
		stack[top]==e;
	}
	else
	{
		printf("stack overflow");
	}
}

void pop(int e){
	//delete element from stack
	int d;
	if(!isEmpty)
	{
		d=stack[top];
		top--;
		printf("elements are deleted succesfully");
	}
	else{
		printf("stack underflow");
	}
}

int main(){
	int choice,e;
	do
	{
		printf(" 1.peek\n2.push \n3.pop\n 4.exit\n");
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice){
		case 1:
		     e=peek(stack);//call peek function
		     printf("\nelement at the top of stack is :%d",e);
		     break;
		case 2:printf("enter the element to be pushed");
			scanf("%d",&e);
			push(e);
		
		     //call push function
		     break;
		case 3:
			pop(e);
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


