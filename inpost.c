#include<stdio.h>
#include<ctype.h>  

typedef struct conversion
{
  int data[50];
   int top;
}stack;

void push(stack*,char);

char pop(stack*);

void convert(char[],char[]);

int priority(char);

char infix[30],postfix[30];

int isEmpty(stack *s1)
{
	if(s1->top==-1)
	return 1;
	else 
	return 0;
}

int main()

{
	char infix [30],postfix[30];
	printf("\nEnter the infix expression");
	scanf("%s",infix);
	convert(infix,postfix);
	printf("\npostfix expression\n%s1",postfix);
	return 0;

}
void convert(char in[] ,char postfix[])
{
	int i,j;
	int c,sc;
	stack s1;
	s1.top=-1;
	for(i=0,j=0;in[i]!='\0';i++)
	{
		c=infix[i];
		switch (c)
		{
			case '(':
			push(&s1,c);
			break;
			case ')':
			while((sc=pop(&s1))!='(')
			postfix[j++]=sc;
			break;
			case '+':
			case '-':
			case '/':
			case '*':
			case '^':
			case '$':
			while (!isEmpty(&s1)&&(priority(s1.data[s1.top]))>=priority(c))
			postfix[j++]=pop(&s1);
			push(&s1,c);
			break;
			default:
			postfix[j++]=c;
			break;
		}
	while(!isEmpty(&s1))
		postfix[j++]=pop(&s1);
	postfix[j]='\0';
 }
}
int priority(char d)
{
	 if(d=='$')
		return 3;
	 if(d=='/'||d=='*')
		return 2;
	 if(d=='+'||d=='-')
		return 1;
	 else
		return 0;
}

void push(stack *s1,char opr)
{
	s1->top++;
	s1->data[s1->top]=opr;
}

char pop(stack *s1)
{
	if (s1->top==-1)
	{
		printf("stack is empty\n");
		return 0;
    }
    else
    {
		char data=s1->data[s1->top--];
		return data;
    }
}

