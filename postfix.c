#include<stdio.h>
#include<ctype.h>

typedef struct stack
{
   char a[30];
   int top;
}stack;

void push(stack *s,char c)
{
	if(s->top>29)
	{
		printf("stack is full");
		return;
	}
	s->top++;
	s->a[s->top]=c;
}

	

int pop(stack *s)
{
	if(s->top==-1)
	{
		printf("stack is empty");
	return 0;
}
else
{
	char data=s->a[s->top--];
	return data;
}
}
int operation(int num1,int num2,char opr)
{
	switch(opr)
	{
		case '+':
		         return (num1+num2);
		case '-':
		         return (num1-num2);
		case '/':
		         return (num1/num2);
		case '*':
		        return (num1*num2);
	}
}
int evaluate (char post[])
{
	int result,n1,n2,i=0;
    char opr;
    stack s;
    s.top=-1;
    while(post[i]!='\0')
    {
      opr=post[i];
      if(isdigit(opr))
      push(&s,opr-'0');
      else
        {
			n1=pop(&s);
			n2=pop(&s);
			result=operation(n1,n2,opr);
			push(&s,result);

		}
		i++;
		
		}
		return pop(&s);
}
	
			
int main()

{
	char postfix[30];
	printf("\nEnter the postfix expression");
	scanf("%s",postfix);
	printf("evaluation of postfix expression=%d",evaluate(postfix));
	return 0;
	
}
	
	
