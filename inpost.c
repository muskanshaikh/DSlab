#include<stdio.h>
#include<ctype.h>  

typedef struct conversion
{
   char a[30];
   int top;
}stack;

void push(stack*,char);

char pop(stack*);

void convert(char[],char[]);

int priority(char);

char infix[30],postfix[30];

int main()

{
	char infix [30],postfix[30];
	printf("\nEnter the infix expression");
	scanf("%s",infix);
	convert(infix,postfix);
	printf("\npostfix expression\n%s",postfix);
	return 0;

}

void convert(char in[],char post[])
{
	char opr;
	stack s1;
	int j=0,i;
	s1.top==-1;
	for(i=0;in[i]!=0;i++)
	{
		if(isalpha(in[j])
		post[j++]=in[i];
		if(in[1]=='(')
		push(&s1,in[i]);
		if(in[1]=='='||in[i]=='/'||in[i]=='*')
		{
			if(s1.top!=-1)
			{
				opr=pop(&s1);
				while(priority(opr)>=priority(in[1]))
				{
					post[j++]=opr;
					opr=pop(&s1);
				}
				push(&s1,opr);
				push(&s1,in[1]);
			}
			else
			{
				push(&s1,in[i]);
			}
			if(in[i]==')')
			{
				opr=pop(&s1);
				while(opr!='(')
				{
					post[j++]=opr;
					opr=pop(&s1);
				}
			}
		}
		while(s1.top!=-1)
		post[j++]=pop(&s1);
		post[j]='\0';
	}
	int priority(char c)
	{
		if(c=='$')
		return 3;
		if(c=='/'||c=='*')
		return 2;
		if(c=='+'||c=='-')
		return 1;
		else 
		return 0;
	}
	void push(stack *s,char opr)
	{
		s->top++;
		s->a[s->[top]=opr;
	}
	char pop(stack *s)
	{
		if(s->top==-1)
	{
		printf("stack overflow");
		return 0;
	}
	else
	{
		char data=s->a[s->top--];
		return data;
	}
}
	

